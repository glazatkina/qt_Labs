#include <QtWidgets>
#include "calculator.h"

Calculator::Calculator(QWidget* pwgt/* = 0*/) : QWidget(pwgt) {
	m_plcd = new QLCDNumber(12);
	m_plcd->setSegmentStyle(QLCDNumber::Flat);
	m_plcd->setMinimumSize(150, 50);

	QChar aButtons[4][4] = {{'7', '8', '9','/'},
							{'4', '5', '6', '*'},
							{'1', '2','3','-'},
							{'0','.','=','+'}};
	QGridLayout* ptopLayout = new QGridLayout;
	ptopLayout->addWidget(m_plcd, 0, 0, 1, 4);
	ptopLayout->addWidget(createButton("CE"), 1, 3);

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			ptopLayout->addWidget(createButton(aButtons[i][j]), i + 2, j);
		}
	}
	setLayout(ptopLayout);
	QPushButton* pcmdA = new QPushButton("A");
	QPushButton* pcmdB = new QPushButton("B");
	ptopLayout->addWidget(pcmdA, 1, 0);
	ptopLayout->addWidget(pcmdB, 1, 2);
	QWidget::setTabOrder(pcmdB, pcmdA);
}

QPushButton* Calculator::createButton(const QString& str) {
	QPushButton* pcmd = new QPushButton(str);
	pcmd->setMinimumSize(40, 40);
	connect(pcmd, SIGNAL(clicked()), SLOT(slotButtonClicked()));
	return pcmd;
}

void Calculator::calculate() {
	double dOperand2 = m_stk.pop().toDouble();
	QString strOperation = m_stk.pop();
	double dOperand1 = m_stk.pop().toDouble();
	double dResult = 0;

	if (strOperation == "+") {
		dResult = dOperand1 + dOperand2;
	}
	if (strOperation == "-") {
		dResult = dOperand1 - dOperand2;
	}
	if (strOperation == "*") {
		dResult = dOperand1 * dOperand2;
	}
	if (strOperation == "/") {
		dResult = dOperand1 / dOperand2;
	}
	m_plcd->display(dResult);
}

void Calculator::slotButtonClicked() {
	QString str = ((QPushButton*)sender())->text();

	if (str == "CE") {
		m_stk.clear();
		m_strDisplay = "";
		m_plcd->display("0");
		return;
	}

	if (str.contains(QRegExp("[0-9]"))) {
		m_strDisplay += str;
		m_plcd->display(m_strDisplay.toDouble());
	}
	else if (str == ".") {
		m_strDisplay += str;
		m_plcd->display(m_strDisplay);
	}
	else {
		if (m_stk.count() >= 2) {
			m_stk.push(QString().setNum(m_plcd->value()));
			calculate();
			m_stk.clear();
			m_stk.push(QString().setNum(m_plcd->value()));
			if (str != "=") {
				m_stk.push(str);
			}
			else {
				m_strDisplay = "";
			}
		}
		else {
			m_stk.push(QString().setNum(m_plcd->value()));
			m_stk.push(str);
			m_strDisplay = "";
			m_plcd->display("0");
		}
	}
}