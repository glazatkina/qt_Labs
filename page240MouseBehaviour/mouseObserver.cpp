#include "mouseObserver.h"

MouseObserver::MouseObserver(QWidget* pwgt /*=0*/) : QLabel(pwgt) {
	setAlignment(Qt::AlignCenter);
	setText("Mouse interactions\n(Press a mouse button)");
}

/*virtual*/ void MouseObserver::mousePressEvent(QMouseEvent* pe) {
	dumpEvent(pe, "Mouse Pressed");
}

/*virtual*/ void MouseObserver::mouseMoveEvent(QMouseEvent* pe) {
	dumpEvent(pe, "Mouse Is Moving");
}

/*virtual*/ void MouseObserver::mouseReleaseEvent(QMouseEvent* pe) {
	dumpEvent(pe, "Mouse Released");
}

void MouseObserver::dumpEvent(QMouseEvent* pe, const QString& strMessage) {
	if (strMessage == "enter") {
		QPalette pal = this->palette();
		pal.setColor(QPalette::Window, Qt::yellow);
		setPalette(pal);
	}
	if (strMessage == "leave") {
		QPalette pal = this->palette();
		pal.setColor(QPalette::Window, Qt::blue);
		setPalette(pal);
	}
	setText(strMessage + "\n buttons() = " + buttonsInfo(pe) +
			"\n x() = " + QString::number(pe->x()) +
			"\n y() = " + QString::number(pe->y()) +
			"\n globalX() = " + QString::number(pe->globalX()) +
			"\n globalY() = " + QString::number(pe->globalY()) +
			"\n modifiers() = " + modifiersInfo(pe));
}


QString MouseObserver::modifiersInfo(QMouseEvent* pe) {
	QString strMod;

	if (pe->modifiers() & Qt::ShiftModifier) {
		strMod += "Shift ";
	}
	if (pe->modifiers() & Qt::AltModifier) {
		strMod += "Alt ";
	}
	if (pe->modifiers() & Qt::ControlModifier) {
		strMod += "Ctrl ";
	}
	return strMod;
}

QString MouseObserver::buttonsInfo(QMouseEvent* pe) {
	QString res;

	if (pe->buttons() & Qt::LeftButton) {
		res += "Left ";
	}

	if (pe->buttons() & Qt::RightButton) {
		res += "Right ";
	}

	if (pe->buttons() & Qt::MidButton) {
		res += "Middle";
	}

	return res;
}

/*virtual*/ void MouseObserver::enterEvent(QEvent* event) {
	dumpEvent((QMouseEvent*)event, "enter");
	QWidget::enterEvent(event);
}
/*virtual*/ void MouseObserver::leaveEvent(QEvent* event) {
	dumpEvent((QMouseEvent*)event, "leave");
	QWidget::leaveEvent(event);
}