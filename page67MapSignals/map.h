#pragma once

#include <QObject>
#include <QtWidgets>

class Mapper : public QObject {
	Q_OBJECT
public:
	Mapper();
	Mapper(QApplication* pwgt);
	
public slots:
	void slotShowAction(const QString&);
};