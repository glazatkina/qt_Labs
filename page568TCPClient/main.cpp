#include <QtWidgets>

#include "TcpClient.h"

int main(int argc, char** argv) {
	QApplication app(argc, argv);
	
	TcpClient client("localhost", 2323);
	client.show();

	app.exec();
}