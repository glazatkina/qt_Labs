#include "map.h"

Mapper::Mapper() : QObject() {}

Mapper::Mapper(QApplication* pwgt) {

	QSignalMapper* psigMapper = new QSignalMapper(this);
	connect(psigMapper, SIGNAL(mapped(const QString&)), 
			this,		SLOT(slotShowAction(const QString&)));

	QPushButton* pcmd1 = new QPushButton("Button1");
	pcmd1->show();
	connect(pcmd1, SIGNAL(clicked()), psigMapper, SLOT(map()));
	psigMapper->setMapping(pcmd1, "Button1 Action");
	
	QPushButton* pcmd2 = new QPushButton("Button2");
	pcmd2->show();
	connect(pcmd2, SIGNAL(clicked()), psigMapper, SLOT(map()));
	psigMapper->setMapping(pcmd2, "Button2 Action");
}

void Mapper::slotShowAction(const QString& str) {
	qDebug() << str;
}