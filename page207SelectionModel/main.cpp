#include <QtWidgets>

int main(int argc, char** argv) {
	QApplication app(argc, argv);
	QWidget wgt;
	wgt.setWindowTitle("Selection Sharing Example");

	QStringListModel model;
	QStringList lst;
	lst << "Item 1" << "Item 2" << "Item 3";
	model.setStringList(lst);

	QTreeView* pTreeView = new QTreeView;
	pTreeView->setModel(&model);

	QListView* pListView = new QListView;
	pListView->setModel(&model);

	QTableView* pTableView = new QTableView;
	pTableView->setModel(&model);

	QItemSelectionModel select(&model);
	pTreeView->setSelectionModel(&select);
	pListView->setSelectionModel(&select);
	pTableView->setSelectionModel(&select);

	QHBoxLayout* phbxLayout = new QHBoxLayout;
	phbxLayout->addWidget(pTreeView);
	phbxLayout->addWidget(pListView);
	phbxLayout->addWidget(pTableView);

	wgt.setLayout(phbxLayout);
	wgt.show();
	return app.exec();
}