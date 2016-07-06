#include <QtWidgets>

int main(int argc, char** argv) {
	QApplication app(argc, argv);
	
	QWidget wgt;
	QLabel* plblName = new QLabel("&Name");
	QLabel* plblAge = new QLabel("A&ge");
	QLabel* plbl = new QLabel("<a href = \"http://www.bhv.ru\">SSSAIT</a>");
	plbl->setOpenExternalLinks(true);
	QLineEdit* ptxtName = new QLineEdit;
	plblName->setBuddy(ptxtName);

	QSpinBox* psbAge = new QSpinBox;
	plblAge->setBuddy(psbAge);

	QVBoxLayout* pvbxLayout = new QVBoxLayout;
	pvbxLayout->addWidget(plblName);
	pvbxLayout->addWidget(ptxtName);
	pvbxLayout->addWidget(plblAge);
	pvbxLayout->addWidget(psbAge);
	pvbxLayout->addWidget(plbl);

	wgt.setLayout(pvbxLayout);
	wgt.show();

	return app.exec();
}