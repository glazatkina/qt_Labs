﻿#pragma once

#include <QtWidgets>

class MouseObserver : public QLabel {
public: 
	MouseObserver(QWidget* pwgt = 0);
protected:
	virtual void mousePressEvent(QMouseEvent* pe);
	virtual void mouseMoveEvent(QMouseEvent* pe);
	virtual void mouseReleaseEvent(QMouseEvent* pe);
	virtual void enterEvent(QEvent* event);
	virtual void leaveEvent(QEvent* event);

	void dumpEvent(QMouseEvent* pe, const QString& strMessage);
	QString modifiersInfo(QMouseEvent* pe);
	QString buttonsInfo(QMouseEvent* pe);
};