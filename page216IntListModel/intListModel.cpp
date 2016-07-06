#include <QtWidgets>
#include "intListModel.h"

IntListModel::IntListModel(const QList<int>& list, QObject* pobj /*=0*/) : QAbstractListModel(pobj), m_list(list) {}

QVariant IntListModel::data(const QModelIndex& index, int nRole) const {
	if (!index.isValid()) {
		return QVariant();
	}
	return (nRole == Qt::DisplayRole || nRole == Qt::EditRole) ? m_list.at(index.row()) : QVariant();
}

bool IntListModel::setData(const QModelIndex& index, const QVariant& value, int nRole) {
	if (index.isValid() && nRole == Qt::EditRole) {
		m_list.replace(index.row(), value.toInt());
		emit dataChanged(index, index);
		return true;
	}
	return false;
}

int IntListModel::rowCount(const QModelIndex& parent /*= QModelIndex()*/) const {
	return m_list.size();
}

QVariant IntListModel::headerData(int nSection, Qt::Orientation orientation, int nRole /*= Qt::DisplayRole*/) const {
	if (nRole != Qt::DisplayRole) {
		return QVariant();
	}
	return (orientation == Qt::Horizontal) ? QString("Number") : QString::number(nSection);
}

Qt::ItemFlags IntListModel::flags(const QModelIndex& index) const {
	Qt::ItemFlags flags = QAbstractListModel::flags(index);
	return index.isValid() ? (flags | Qt::ItemIsEditable) : flags;
}