#include <QtWidgets>

int main(int argc, char** argv) {
	QApplication app(argc, argv);
	
	QWidget wgt;
	wgt.setWindowTitle("Scroll Bar");
	QLCDNumber* plcd = new QLCDNumber(4);
	QScrollBar* phsb = new QScrollBar(Qt::Horizontal);

	QObject::connect(phsb, SIGNAL(valueChanged(int)), plcd, SLOT(display(int)));

	phsb->setValue(10);

	QVBoxLayout* pvbxLayout = new QVBoxLayout;
	pvbxLayout->addWidget(plcd);
	pvbxLayout->addWidget(phsb);
	wgt.setLayout(pvbxLayout);

	wgt.resize(250, 150);

	wgt.show();
	return app.exec();
}