#include <QtWidgets>
#include "buttons.h"

Buttons::Buttons(QWidget* pwgt/*=0*/) : QGroupBox("QGroupBox", pwgt) {
	resize(100, 150);
	setCheckable(true);
	setChecked(true);

	m_npradBlue = new QRadioButton("&Blue");
	m_npradRed = new QRadioButton("&Red");
	m_npradGreen = new QRadioButton("&Green");
	m_npradGreen->setChecked(true);
	connect(m_npradBlue, SIGNAL(clicked()), SLOT(slotButtonClicked()));
	connect(m_npradRed, SIGNAL(clicked()), SLOT(slotButtonClicked()));
	connect(m_npradGreen, SIGNAL(clicked()), SLOT(slotButtonClicked()));

	m_npchk = new QCheckBox("&Light");
	m_npchk->setChecked(true);
	connect(m_npchk, SIGNAL(clicked()), SLOT(slotButtonClicked()));

	QPushButton* pcmd = new QPushButton("Exit");
	connect(pcmd, SIGNAL(clicked()), qApp, SLOT(quit()));

	QVBoxLayout* pvbxLayout = new QVBoxLayout;
	pvbxLayout->addWidget(m_npradBlue);
	pvbxLayout->addWidget(m_npradRed);
	pvbxLayout->addWidget(m_npradGreen);
	pvbxLayout->addWidget(m_npchk);
	pvbxLayout->addWidget(pcmd);

	setLayout(pvbxLayout);
	
	slotButtonClicked();
}

void Buttons::slotButtonClicked() {
	QPalette pal = palette();
	int nLight = m_npchk->isChecked() ? 150 : 80;
	if (m_npradBlue->isChecked()) {
		pal.setColor(backgroundRole(), QColor(Qt::blue).light(nLight));
	} else 	if (m_npradRed->isChecked()) {
		pal.setColor(backgroundRole(), QColor(Qt::red).light(nLight));
	}
	else	if (m_npradGreen->isChecked()) {
		pal.setColor(backgroundRole(), QColor(Qt::green).light(nLight));
	}
	setPalette(pal);
}