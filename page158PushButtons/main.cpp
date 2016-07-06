#include <QtWidgets>

int main(int argc, char** argv) {
	QApplication app(argc, argv);
	
	QWidget wgt;
	
	QPushButton* pcmdNormal = new QPushButton("Normal Button");

	QPushButton* pcmdToggle = new QPushButton("Toggle Button");
	pcmdToggle->setCheckable(true);
	pcmdToggle->setChecked(true);

	QPushButton* pcmdFlatButton = new QPushButton("&Flat Button");
	pcmdFlatButton->setFlat(true);

	QPushButton* pcmdPix = new QPushButton("&Pixmap Button");
	QPixmap pix(":/ChordsMaestro.png");
	pcmdPix->setIcon(pix);
	pcmdPix->setIconSize(pix.size());

	QPushButton* pcmdMenu = new QPushButton("Menu");
	QMenu* pmnu = new QMenu(pcmdMenu);
	pmnu->addAction("Item1");
	pmnu->addAction("Item2");
	pmnu->addAction("&Quit", &app, SLOT(quit()));

	pcmdMenu->setMenu(pmnu);

	QVBoxLayout* pvbxLayout = new QVBoxLayout;
	pvbxLayout->addWidget(pcmdNormal);
	pvbxLayout->addWidget(pcmdToggle);
	pvbxLayout->addWidget(pcmdFlatButton);
	pvbxLayout->addWidget(pcmdPix);
	pvbxLayout->addWidget(pcmdMenu);

	wgt.setLayout(pvbxLayout);
	wgt.show();

	return app.exec();
}