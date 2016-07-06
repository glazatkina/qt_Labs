#include <QtWidgets>
#include "mouseFilter.h"

MouseFilter::MouseFilter(QObject* pobj /*=0*/) : QObject(pobj) {}

/*virtual*/ bool MouseFilter::eventFilter(QObject* pobj, QEvent* pe) {
	if (pe->type() == QEvent::MouseButtonPress) {
		if (static_cast<QMouseEvent*>(pe)->button() == Qt::LeftButton) {
			QString str = pobj->metaObject()->className();
			QMessageBox::information(0, "Class Name", str);
			return true;
		}
	}
	return false;
}