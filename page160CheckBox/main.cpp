#include <QtWidgets>

int main(int argc, char** argv) {
	QApplication app(argc, argv);
	
	QWidget wgt;

	QCheckBox* pchkNormal = new QCheckBox("&Normal Check Box");
	pchkNormal->setChecked(true);

	QCheckBox* pchkTristate = new QCheckBox("&Trictate Check Box");
	pchkTristate->setTristate(true);
	pchkTristate->setCheckState(Qt::PartiallyChecked);

	QVBoxLayout* pvbxLayout = new QVBoxLayout;
	pvbxLayout->addWidget(pchkNormal);
	pvbxLayout->addWidget(pchkTristate);

	wgt.setLayout(pvbxLayout);
	wgt.show();

	return app.exec();
}