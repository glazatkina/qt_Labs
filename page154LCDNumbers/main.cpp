#include <QtWidgets>
#include "lcdnum.h"
int main(int argc, char** argv) {
	QApplication app(argc, argv);
	
	LcdNum numb;
	numb.show();

	return app.exec();
}
