#include <QtWidgets>

int main(int argc, char** argv) {
	QApplication app(argc, argv);
	
	QSplitter spl(Qt::Vertical);
	QTextEdit* ptxt1 = new QTextEdit;
	QTextEdit* ptxt2 = new QTextEdit;

	ptxt1->setCursor(Qt::WhatsThisCursor);
	ptxt2->setCursor(Qt::ForbiddenCursor);

	ptxt1->setPlainText("Owwww");
	ptxt2->setPlainText("Don't touch me!");

	ptxt1->setDisabled(true);
	ptxt2->setFontItalic(true);
	ptxt2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
	spl.addWidget(ptxt1);
	spl.addWidget(ptxt2);

	spl.resize(200, 200);
	spl.setOpaqueResize(true);
	spl.show();

	return app.exec();
}