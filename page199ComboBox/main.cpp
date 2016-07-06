#include <QtWidgets>

int main(int argc, char** argv) {
	QApplication app(argc, argv);
	QComboBox cbo;
	QStringList lst;

	lst << "Natalya" << "Ksenya" << "Nickolay" << "Yana";
	cbo.addItems(lst);
	cbo.setEditable(true);
	cbo.setWindowTitle("Choose your name");

	cbo.show();
	return app.exec();
}