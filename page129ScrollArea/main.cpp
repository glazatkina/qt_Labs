#include <QtWidgets>

int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	QScrollArea sa;
	sa.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
	//sa.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	QWidget* pwgt = new QWidget;
	QPixmap pix(":/img.jpg");
	
	QPalette pal;
	pal.setBrush(pwgt->backgroundRole(), QBrush(pix));
	pwgt->setPalette(pal);
	pwgt->setAutoFillBackground(true);
	pwgt->setFixedSize(pix.width()/4, pix.height()/4);

	sa.setWidget(pwgt);
	sa.resize(350, 150);
	sa.show();
	return app.exec();
};