#pragma once
#include <QGroupBox>

class QCheckBox;
class QRadioButton;
class QGroupBox;

class Buttons : public QGroupBox {
	Q_OBJECT
private:
	QCheckBox* m_npchk;
	QRadioButton* m_npradRed;
	QRadioButton* m_npradBlue;
	QRadioButton* m_npradGreen;
public:
	Buttons(QWidget* pwgt = 0);
public slots:
	void slotButtonClicked();
};