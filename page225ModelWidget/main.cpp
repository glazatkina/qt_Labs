#include <QtWidgets>

int main(int argc, char** argv) {
	QApplication app(argc, argv);
	QStringList lst;
	QListWidget lwg;
	QListWidgetItem* pitem = 0;
	lst << "Windows" << "Linux" << "Android" << "MacOSX";

	lwg.setIconSize(QSize(48, 48));
	foreach(QString str, lst) {
		pitem = new QListWidgetItem(str, &lwg);
		pitem->setIcon(QPixmap(":/" + str + ".jpg"));
	}
	lwg.setWindowTitle("Test 1");
	lwg.show();

	QListView listView;
	listView.setModel(lwg.model());
	listView.setSelectionModel(lwg.selectionModel());
	listView.setWindowTitle("Test 2");
	listView.show();

	return app.exec();
}