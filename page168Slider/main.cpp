#include <QtWidgets>

int main(int argc, char** argv) {
	QApplication app(argc, argv);
	
	QWidget wgt;
	wgt.setWindowTitle("Slider");
	QSlider* psld = new QSlider(Qt::Horizontal);
	QLabel* plbl = new QLabel("3");

	psld->setRange(0, 10);
	psld->setPageStep(2);
	psld->setValue(3);
	psld->setTickInterval(2);
	psld->setTickPosition(QSlider::TicksBelow);
	QObject::connect(psld, SIGNAL(valueChanged(int)), plbl, SLOT(setNum(int)));

	QHBoxLayout* phbxLayout = new QHBoxLayout;
	phbxLayout->addWidget(psld);
	phbxLayout->addWidget(plbl);

	wgt.setLayout(phbxLayout);
	wgt.show();
	return app.exec();
}