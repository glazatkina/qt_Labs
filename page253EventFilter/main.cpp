#include <QtWidgets>
#include "mouseFilter.h"

int main(int argc, char** argv) {
	QApplication app(argc, argv);
	
	QLineEdit txt("QLineEdit");
	txt.installEventFilter(new MouseFilter(&txt));
	txt.show();

	QLabel lbl("QLabel");
	lbl.installEventFilter(new MouseFilter(&lbl));
	lbl.show();

	QPushButton pcmd("QPushButton");
	pcmd.installEventFilter(new MouseFilter(&pcmd));
	pcmd.show();

	app.exec();
}