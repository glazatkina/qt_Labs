#include <QtWidgets>

int main(int argc, char** argv) {
	QApplication app(argc, argv);
	QTextEdit txt;
	txt.setWindowTitle("HTML Buddy");

	txt.setHtml("<HTML>"
		"<body bgcolor = magenta>"
		"<p align = \"center\" >"
		"Hello!<Br>"
		"It's me!"
		"</p></body></html>");
	txt.resize(200, 300);
	txt.show();
	return app.exec();
}