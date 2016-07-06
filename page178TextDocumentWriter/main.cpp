#include <QtWidgets>
#include "saveAs.h"

int main(int argc, char** argv) {
	QApplication app(argc, argv);
	
	SaverAs saver;
	saver.show();

	return app.exec();
}