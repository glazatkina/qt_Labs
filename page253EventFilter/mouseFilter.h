#pragma once

#include <QtWidgets>

class MouseFilter : public QObject {
public: 
	MouseFilter(QObject* bobj = 0);
protected:
	virtual bool eventFilter(QObject*, QEvent*);
};