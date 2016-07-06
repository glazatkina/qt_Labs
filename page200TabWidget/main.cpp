#include <QtWidgets>

int main(int argc, char** argv) {
	QApplication app(argc, argv);
	QTabWidget tab;
	QStringList lst;
	tab.setWindowTitle("Tab Example");

	lst << "Windows" << "Linux" << "Android" << "MacOSX";
	foreach(QString str, lst) {
		tab.addTab(new QLabel(str, &tab), QPixmap(":/" + str + ".jpg"), str);
	}
	tab.resize(360, 100);
	tab.show();

	return app.exec();
}