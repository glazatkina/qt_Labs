#include <QtWidgets>

int main(int argc, char** argv) {
	const int n = 3;

	QApplication app(argc, argv);
	QTableWidget tbl(n,n);
	QStringList lst;
	QTableWidgetItem* ptwi = 0;

	lst << "One" << "Two" << "Three";
	tbl.setHorizontalHeaderLabels(lst);
	tbl.setVerticalHeaderLabels(lst);
	tbl.setWindowTitle("Table Example");
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			ptwi = new QTableWidgetItem(QString("%1.%2").arg(i).arg(j));
			tbl.setItem(i, j, ptwi);
		}
	}
	tbl.resize(370, 135);
	tbl.show();

	return app.exec();
}