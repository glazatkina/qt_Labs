/****************************************************************************
** Meta object code from reading C++ file 'TcpClient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../TcpClient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TcpClient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TcpClient_t {
    QByteArrayData data[7];
    char stringdata0[95];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TcpClient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TcpClient_t qt_meta_stringdata_TcpClient = {
    {
QT_MOC_LITERAL(0, 0, 9), // "TcpClient"
QT_MOC_LITERAL(1, 10, 13), // "slotReadyRead"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 9), // "slotError"
QT_MOC_LITERAL(4, 35, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(5, 64, 16), // "slotSendToServer"
QT_MOC_LITERAL(6, 81, 13) // "slotConnected"

    },
    "TcpClient\0slotReadyRead\0\0slotError\0"
    "QAbstractSocket::SocketError\0"
    "slotSendToServer\0slotConnected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TcpClient[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08 /* Private */,
       3,    1,   35,    2, 0x08 /* Private */,
       5,    0,   38,    2, 0x08 /* Private */,
       6,    0,   39,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TcpClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TcpClient *_t = static_cast<TcpClient *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotReadyRead(); break;
        case 1: _t->slotError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 2: _t->slotSendToServer(); break;
        case 3: _t->slotConnected(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    }
}

const QMetaObject TcpClient::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TcpClient.data,
      qt_meta_data_TcpClient,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TcpClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TcpClient::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TcpClient.stringdata0))
        return static_cast<void*>(const_cast< TcpClient*>(this));
    return QWidget::qt_metacast(_clname);
}

int TcpClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
