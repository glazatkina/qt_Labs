#include <QtWidgets>

int main(int argc, char** argv) {
	QApplication app(argc, argv);
	QSpinBox spb;

	QPalette pal2(Qt::red, Qt::blue);
	QApplication::setPalette(pal2);
	/*QPalette pal = spb.palette();
	pal.setBrush(QPalette::Button, QBrush(Qt::red, Qt::Dense3Pattern));
	pal.setColor(QPalette::ButtonText, Qt::blue);
	pal.setColor(QPalette::Text, Qt::magenta);
	pal.setColor(QPalette::Active, QPalette::Base, Qt::green);*/

	//spb.setPalette(pal);
	spb.resize(50, 50);
	spb.show();


	app.exec();
}