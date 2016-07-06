#include <QtWidgets>
#include "lcdnum.h"

LcdNum::LcdNum(QWidget* pwgt/*=0*/) : QWidget(pwgt) {
	QLCDNumber* plcd = new QLCDNumber;
	QSpinBox* pspb = new QSpinBox;
	QPushButton* pcmdBin = new QPushButton("2");
	QPushButton* pcmdOct = new QPushButton("8");
	QPushButton* pcmdDec = new QPushButton("10");
	QPushButton* pcmdHex = new QPushButton("16");
	QLabel* plbl1 = new QLabel("Number");
	QLabel* plbl2 = new QLabel("Numeric system");

	plcd->setSegmentStyle(QLCDNumber::Filled);
	plcd->setMode(QLCDNumber::Dec);

	plcd->setFixedHeight(30);

	QObject::connect(pspb, SIGNAL(valueChanged(int)), plcd, SLOT(display(int)));
	QObject::connect(pcmdBin, SIGNAL(clicked()), plcd, SLOT(setBinMode()));
	QObject::connect(pcmdOct, SIGNAL(clicked()), plcd, SLOT(setOctMode()));
	QObject::connect(pcmdDec, SIGNAL(clicked()), plcd, SLOT(setDecMode()));
	QObject::connect(pcmdHex, SIGNAL(clicked()), plcd, SLOT(setHexMode()));

	//layout setup
	QBoxLayout* vLayout = new QBoxLayout(QBoxLayout::TopToBottom);
	QBoxLayout* hLayout = new QBoxLayout(QBoxLayout::LeftToRight);

	hLayout->addWidget(pcmdBin);
	hLayout->addWidget(pcmdOct);
	hLayout->addWidget(pcmdDec);
	hLayout->addWidget(pcmdHex);

	vLayout->addWidget(plcd);
	vLayout->addWidget(plbl1);
	vLayout->addWidget(pspb);
	vLayout->addWidget(plbl2);
	vLayout->addLayout(hLayout);

	setLayout(vLayout);
}