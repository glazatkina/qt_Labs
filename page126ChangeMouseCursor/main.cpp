#include <QtWidgets>

int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	QWidget wgt;
	wgt.resize(200, 200);

	QPixmap pix(":/clock.png");
	QCursor cur(pix);
	//wgt.setCursor(Qt::CrossCursor);
	wgt.setCursor(cur);

	wgt.show();
	return app.exec();
};