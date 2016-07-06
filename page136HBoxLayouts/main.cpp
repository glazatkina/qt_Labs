#include <QtWidgets>

int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	QWidget wgt;

	QPushButton* pcmdA = new QPushButton("A");
	QPushButton* pcmdB = new QPushButton("B");
	QPushButton* pcmdC = new QPushButton("C");
	QPushButton* pcmdD = new QPushButton("D");

	//horizontal layout setup
	QHBoxLayout* phbxLayout = new QHBoxLayout;
	phbxLayout->setMargin(10);
	phbxLayout->setSpacing(20);
	phbxLayout->addWidget(pcmdA);
	phbxLayout->addWidget(pcmdB);

	//vertical layout
	QVBoxLayout* pvbxLayout = new QVBoxLayout;
	pvbxLayout->setMargin(10);
	pvbxLayout->setSpacing(20);
	pvbxLayout->addWidget(pcmdC);
	pvbxLayout->addWidget(pcmdD);
	pvbxLayout->addLayout(phbxLayout);


	wgt.setLayout(pvbxLayout);

	wgt.show();
	return app.exec();
};