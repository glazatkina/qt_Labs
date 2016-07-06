#include <QtWidgets>
#include "mouseObserver.h"

int main(int argc, char** argv) {
	QApplication app(argc, argv);

	MouseObserver wgt;
	wgt.setWindowTitle("Mouse Events");
	wgt.resize(250, 150);
	wgt.show();

	app.exec();
}