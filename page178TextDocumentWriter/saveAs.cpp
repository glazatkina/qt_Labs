#include <QtWidgets>
#include "saveAs.h"

SaverAs::SaverAs(QWidget* pwgt/*=0*/) : QWidget(pwgt) {
	setWindowTitle("Text Saver");
	ptxt = new QTextEdit("Text example <b>WOW</b>!!!");
	pcmdPDF = new QPushButton("Save as PDF");
	pcmdODF = new QPushButton("Save as ODF");

	QVBoxLayout* pvbxLayout = new QVBoxLayout;
	pvbxLayout->addWidget(ptxt);
	pvbxLayout->addWidget(pcmdODF);
	pvbxLayout->addWidget(pcmdPDF);
	setLayout(pvbxLayout);

	QObject::connect(pcmdODF, SIGNAL(clicked()), SLOT(saveAsODF()));
	QObject::connect(pcmdPDF, SIGNAL(clicked()), SLOT(saveAsPDF()));
}

void SaverAs::saveAsODF() {
	writerODF.setFormat("odf");
	writerODF.setFileName("outODF.odf");
	writerODF.write(ptxt->document());
}

void SaverAs::saveAsPDF() {
	printer.setOutputFormat(QPrinter::PdfFormat);
	printer.setOutputFileName("outPDF.pdf");
	ptxt->document()->print(&printer);
}