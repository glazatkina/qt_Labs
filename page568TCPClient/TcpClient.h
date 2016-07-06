#pragma once
#include <QTcpServer>
#include <QTcpSocket>
#include <QTextEdit>
#include <QLineEdit>
#include <QHostAddress>
#include <QWidget>

class TcpClient : public QWidget {
Q_OBJECT
private:
	QTcpSocket* m_ptcpSocket;
	QTextEdit* m_ptxtInfo;
	QLineEdit* m_ptxtInput;
	quint16 m_nNextBlockSize;

public:
	TcpClient(const QString& strHost, int nPort, QWidget* pwgt = 0);

private slots:
	void slotReadyRead();
	void slotError(QAbstractSocket::SocketError);
	void slotSendToServer();
	void slotConnected();
};