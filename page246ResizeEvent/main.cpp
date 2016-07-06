#include <QtWidgets>

class ResizeObserver : public QLabel {
public:
	ResizeObserver(QWidget* pwgt = 0) : QLabel(pwgt) {
		setAlignment(Qt::AlignCenter);
	}
protected:
	virtual void resizeEvent(QResizeEvent* pe) {
		setText(QString("Resized") +
			"\n width() = " + QString::number(pe->size().width())
			+ "\n height() = " + QString::number(pe->size().height()));
	}

};

int main(int argc, char** argv) {
	QApplication app(argc, argv);

	ResizeObserver wgt;
	wgt.setWindowTitle("Resize Event");
	wgt.resize(200, 150);
	wgt.show();

	app.exec();
}