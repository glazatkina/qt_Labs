#include <QtWidgets>

class SimpleDelegate : public QStyledItemDelegate {
public :
	SimpleDelegate(QObject* pobj = 0) : QStyledItemDelegate(pobj) { }
	void paint(QPainter* pPainter, 
			const QStyleOptionViewItem& option, 
			const QModelIndex& index
			) const {
		if (option.state & QStyle::State_MouseOver) {
			QRect rect = option.rect;
			QLinearGradient gradient(0, 0, rect.width(), rect.height());

			gradient.setColorAt(0.3, Qt::white);
			gradient.setColorAt(0.6, Qt::blue);
			gradient.setColorAt(0.9, Qt::red);
			pPainter->setBrush(gradient);
			pPainter->drawRect(rect);
		}
		QStyledItemDelegate::paint(pPainter, option, index);
	}
};

//-------------------------------------------------------------
int main(int argc, char* argv[]) {
	QApplication app(argc, argv);
	QStringListModel model;
	QStringList lst;
	lst << "Item 1" << "Item 2" << "Item 3";
	model.setStringList(lst);

	QListView listView;
	listView.setModel(&model);
	listView.setItemDelegate(new SimpleDelegate(&listView));
	listView.viewport()->setAttribute(Qt::WA_Hover);
	listView.setWindowTitle("Russian Delegate");
	listView.show();

	app.exec();
}