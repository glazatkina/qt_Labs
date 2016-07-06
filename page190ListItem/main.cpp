#include <QtWidgets>

int main(int argc, char** argv) {
	QApplication app(argc, argv);
	QStringList lst;
	QListWidget lwg;
	QListWidgetItem* pitem = 0;

	lwg.setIconSize(QSize(48, 48));
	lwg.setSelectionMode(QAbstractItemView::MultiSelection);
	lwg.setViewMode(QListView::IconMode);
	lst << "Linux" << "Windows" << "MacOSX" << "Android";
	foreach(QString str, lst) {
		pitem = new QListWidgetItem(str, &lwg);
		pitem->setIcon(QPixmap(":/" + str + ".jpg"));
		pitem->setFlags(Qt::ItemIsEditable | Qt::ItemIsEnabled);
	}
	lwg.resize(150, 205);
	lwg.show();

	return app.exec();
}