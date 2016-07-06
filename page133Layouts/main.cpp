#include <QtWidgets>

int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	QWidget wgt;

	QPushButton* pcmdA = new QPushButton("A");
	QPushButton* pcmdB = new QPushButton("B");
	QPushButton* pcmdC = new QPushButton("C");

	//layout setup
	QBoxLayout* pbxLayout = new QBoxLayout(QBoxLayout::LeftToRight);
	pbxLayout->addWidget(pcmdA, 1);
	pbxLayout->addWidget(pcmdB, 2);
	pbxLayout->addWidget(pcmdC, 3);
	//layout2 setup
	QPushButton* pcmdA1 = new QPushButton("A1");
	QPushButton* pcmdB1 = new QPushButton("B1");
	QBoxLayout* pbxLayout2 = new QBoxLayout(QBoxLayout::LeftToRight);
	pbxLayout2->addWidget(pcmdA1);
	pbxLayout2->addStretch(1);
	pbxLayout2->addWidget(pcmdB1);
	
	//main layout
	QBoxLayout* pbxLayoutMain = new QBoxLayout(QBoxLayout::TopToBottom);
	pbxLayoutMain->addLayout(pbxLayout);
	pbxLayoutMain->addStretch(10);
	pbxLayoutMain->addLayout(pbxLayout2);

	wgt.setLayout(pbxLayoutMain);

	wgt.resize(450, 100);
	wgt.show();

	return app.exec();
};