#include <QApplication>
#include "buttons.h"
int main(int argc, char** argv) {
	QApplication app(argc, argv);
	
	Buttons btn;
	btn.show();

	return app.exec();
}
