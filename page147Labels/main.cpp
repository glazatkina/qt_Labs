#include <QtWidgets>

int main(int argc, char** argv) {
	QApplication app(argc, argv);
	
	QLabel lbl("<H1><CENTER>Qlabel - HTML Demo</CENTER></H1>"
		"<H2><Center>For what all this circus?</center></h2>"
		"<center><img border = \"0\" src=\":/balalaika.png\"></center>"
		"<h2><center>List</center></h2>"
		"<ol><li>one</li>"
		"<li>two</li>"
		"<li>three</li></ol>");

	lbl.show();
	return app.exec();
}