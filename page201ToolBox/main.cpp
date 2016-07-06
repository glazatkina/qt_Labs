#include <QtWidgets>

int main(int argc, char** argv) {
	QApplication app(argc, argv);
	QToolBox tbx;
	QStringList lst;
	tbx.setWindowTitle("ToolBox Example");

	lst << "Windows" << "Linux" << "Android" << "MacOSX";
	foreach(QString str, lst) {
		tbx.addItem(new QLabel(str, &tbx), QPixmap(":/" + str + ".jpg"), str);
	}
	tbx.resize(360, 100);
	tbx.show();

	return app.exec();
}