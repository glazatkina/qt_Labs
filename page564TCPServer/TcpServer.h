#pragma once
#include <QTcpServer>
#include <QTcpSocket>
#include <QTextEdit>
#include <QHostAddress>
#include <QWidget>

class TcpServer : public QWidget {
Q_OBJECT
private:
	QTcpServer* m_ptcpServer;
	QTextEdit* m_ptxt;
	quint16 m_nNextBlockSize;

	void sendToClient(QTcpSocket* pSocket, const QString& str);

public:
	TcpServer(int nPort, QWidget* pwgt = 0);

public slots:
	virtual void slotNewConnection();
	void slotReadClient();
};