#include <QtXml>
#include <QDebug>

void traverseNode(const QDomNode& node) {
	QDomNode domNode = node.firstChild();
	while (!domNode.isNull()) {
		QDomElement domElement = domNode.toElement();
		if (!domElement.isNull()) {
			if (domElement.tagName() == "contact") {
				qDebug() << "Attr: " << domElement.attribute("number", "1");
			}
			else {
				qDebug() << "TagName: " << domElement.tagName();
				qDebug() << "\tText: " << domElement.text();
			}
		}
		traverseNode(domNode);
		domNode = domNode.nextSibling();
	}
}

int main() {
	QDomDocument domDoc;
	QFile file("addressbook.xml");

	if (file.open(QIODevice::ReadOnly)) {
		if (domDoc.setContent(&file)) {
			QDomElement domElement = domDoc.documentElement();
			traverseNode(domElement);
		}
		file.close();
	}
	else {
		qDebug() << "ERROR!!!";
	}

	return 0;
}