#include <QtWidgets>

int main(int argc, char** argv) {
	QApplication app(argc, argv);

	QGroupBox gbx("&Colors");

	QRadioButton* pradRed = new QRadioButton("&Red");
	QRadioButton* pradBlue = new QRadioButton("&Blue");
	QRadioButton* pradGreen = new QRadioButton("&Green");
	pradBlue->setChecked(true);

	QVBoxLayout* pvbxLayout = new QVBoxLayout;
	pvbxLayout->addWidget(pradRed);
	pvbxLayout->addWidget(pradBlue);
	pvbxLayout->addWidget(pradGreen);

	gbx.setLayout(pvbxLayout);
	gbx.show();

	return app.exec();
}