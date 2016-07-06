#pragma once
#include <QWidget>

class QLCDNumber;
class QSpinBox;
class QPushButton;
class QLabel;
class QBoxLayout;

class LcdNum : public QWidget {
private:
	QLCDNumber* plcd;
	QSpinBox* pspb;
	QPushButton* pcmdBin;
	QPushButton* pcmdOct;
	QPushButton* pcmdDec;
	QPushButton* pcmdHex;
	QLabel* plbl1;
	QLabel* plbl2;
	QBoxLayout* vLayout;
	QBoxLayout* hLayout;
public:
	LcdNum(QWidget* pobj = 0);
};