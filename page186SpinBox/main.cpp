#include <QtWidgets>

class NameValidator : public QValidator {
public:
	NameValidator(QObject* parent) : QValidator(parent) {}
	virtual State validate(QString& str, int& pos) const {
		QRegExp rxp = QRegExp("[0-9]");
		if (str.contains(rxp)) { return Invalid; }
		return Acceptable;
	}
};

int main(int argc, char** argv) {
	QApplication app(argc, argv);

	QWidget wgt;
	wgt.setWindowTitle("Spin Boxes");

	QLabel* plblCount = new QLabel("Megabytes:");	
	QLabel* plblDate = new QLabel("Date and Time:");
	QLabel* plblValid = new QLabel("Name:");

	QSpinBox spb;
	spb.setRange(1, 100);
	spb.setSuffix(" MB");
	spb.setButtonSymbols(QSpinBox::PlusMinus);
	spb.setWrapping(true);
	spb.resize(100, 30);

	plblCount->setBuddy(&spb);
	QObject::connect(&spb, SIGNAL(valueChanged(const QString&)), plblCount, SLOT(setText(const QString&)));

	QDateTimeEdit dateTimeEdit(QDateTime::currentDateTime());

	QLineEdit* ptxt = new QLineEdit;

	NameValidator* pnameValidator = new NameValidator(ptxt);
	ptxt->setValidator(pnameValidator);
	plblValid->setBuddy(ptxt);

	QVBoxLayout* pvbxLayout = new QVBoxLayout;
	pvbxLayout->addWidget(plblCount);
	pvbxLayout->addWidget(&spb);
	pvbxLayout->addWidget(plblDate);
	pvbxLayout->addWidget(&dateTimeEdit);
	pvbxLayout->addWidget(plblValid);
	pvbxLayout->addWidget(ptxt);

	wgt.setLayout(pvbxLayout);
	wgt.resize(230, 180);
	wgt.show();
	return app.exec();
}