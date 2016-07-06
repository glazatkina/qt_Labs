#include <QtWidgets>

int main(int argc, char** argv) {
	QApplication app(argc, argv);
	
	QWidget wgt;

	QStringListModel model;
	model.setStringList(QStringList() << "Helen" << "Natalya" << "Oleg" << "Olga" << "Ivan");

	QSortFilterProxyModel proxyModel;
	proxyModel.setSourceModel(&model);
	proxyModel.setFilterWildcard("O*");

	QListView* pListView1 = new QListView;
	pListView1->setModel(&model);

	QListView* pListView2 = new QListView;
	pListView2->setModel(&proxyModel);

	QHBoxLayout* phbxLayout = new QHBoxLayout;
	phbxLayout->addWidget(line);
	phbxLayout->addWidget(pListView1);
	phbxLayout->addWidget(pListView2);
	wgt.setLayout(phbxLayout);

	wgt.setWindowTitle("Proxy Model Example");
	wgt.show();
	app.exec();
}