#pragma once

#include <QWidget>
#include <QPrinter>
#include <QTextDocumentWriter>

class QTextEdit;
class QTextDocumentWriter;
class QPrinter;
class QPushButton;

class SaverAs : public QWidget {
	Q_OBJECT
private:
	QTextEdit* ptxt;
	QTextDocumentWriter writerODF;
	QPrinter printer;
	QPushButton* pcmdPDF;
	QPushButton* pcmdODF;
public:
	SaverAs(QWidget* pwgt = 0);
public slots:
	void saveAsPDF();
	void saveAsODF();
};