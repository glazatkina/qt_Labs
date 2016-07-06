#include <QtWidgets>
#include "map.h"

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	Mapper m(&app);
	return app.exec();
};