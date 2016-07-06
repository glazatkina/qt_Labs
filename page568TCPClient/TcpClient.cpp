#include <QtWidgets>

#include "TcpClient.h"

TcpClient::TcpClient(const QString& strHost, int nPort, QWidget* pwgt /*= 0*/) : QWidget(pwgt), m_nNextBlockSize(0) {
	m_ptcpSocket = new QTcpSocket(this);

	m_ptcpSocket->connectToHost(strHost, nPort);
	connect(m_ptcpSocket, SIGNAL(connected()), SLOT(slotConnected()));
	connect(m_ptcpSocket, SIGNAL(readyRead()), SLOT(slotReadyRead()));
	connect(m_ptcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(slotError(QAbstractSocket::SocketError)));

	m_ptxtInfo = new QTextEdit;
	m_ptxtInput = new QLineEdit;

	m_ptxtInfo->setReadOnly(true);

	QPushButton* pcmd = new QPushButton("&Send");
	connect(pcmd, SIGNAL(clicked()), this, SLOT(slotSendToServer()));

	//layout
	QVBoxLayout* pvbx = new QVBoxLayout;
	pvbx->addWidget(new QLabel("<H1>Client</H1>"));
	pvbx->addWidget(m_ptxtInfo);
	pvbx->addWidget(m_ptxtInput);
	pvbx->addWidget(pcmd);
	setLayout(pvbx);
}

void TcpClient::slotReadyRead() {
	QDataStream in(m_ptcpSocket);
	in.setVersion(QDataStream::Qt_5_3);

	for (;;) {
		if (!m_nNextBlockSize) {
			if (m_ptcpSocket->bytesAvailable() < sizeof(quint16)) {
				break;
			}
			in >> m_nNextBlockSize;
		}

		if (m_ptcpSocket->bytesAvailable() < m_nNextBlockSize) {
			break;
		}

		QTime time;
		QString str;
		in >> time >> str;
		m_ptxtInfo->append(time.toString() + " " + str);
		m_nNextBlockSize = 0;
	}
}

void TcpClient::slotError(QAbstractSocket::SocketError err) {
	QString strErr = "Error: " + (err == QAbstractSocket::HostNotFoundError ? "The host was not found" :
		err == QAbstractSocket::RemoteHostClosedError ? "The remote host is closed" :
		err == QAbstractSocket::ConnectionRefusedError ? "The connection was refused" :
		QString(m_ptcpSocket->errorString()));
	m_ptxtInfo->append(strErr);
}
void TcpClient::slotSendToServer() {
	QByteArray arrBlock;
	QDataStream out(&arrBlock, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_5_3);
	out << quint16(0) << QTime::currentTime() << m_ptxtInput->text();

	out.device()->seek(0);
	out << quint16(arrBlock.size() - sizeof(quint16(0)));

	m_ptcpSocket->write(arrBlock);
	m_ptxtInput->clear();
}
void TcpClient::slotConnected() {
	m_ptxtInfo->append("Reciever the connected() signal");
}