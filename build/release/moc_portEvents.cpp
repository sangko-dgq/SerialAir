/****************************************************************************
** Meta object code from reading C++ file 'serialModel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../src/models/serialModel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serialModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_portEvents_t {
    QByteArrayData data[14];
    char stringdata0[177];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_portEvents_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_portEvents_t qt_meta_stringdata_portEvents = {
    {
QT_MOC_LITERAL(0, 0, 10), // "serialModel"
QT_MOC_LITERAL(1, 11, 15), // "sg_portOpenFail"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 13), // "sg_portOpenOK"
QT_MOC_LITERAL(4, 42, 11), // "st_openPort"
QT_MOC_LITERAL(5, 54, 15), // "QSerialPortInfo"
QT_MOC_LITERAL(6, 70, 8), // "portInfo"
QT_MOC_LITERAL(7, 79, 8), // "baudRate"
QT_MOC_LITERAL(8, 88, 21), // "QSerialPort::DataBits"
QT_MOC_LITERAL(9, 110, 8), // "dataBits"
QT_MOC_LITERAL(10, 119, 19), // "QSerialPort::Parity"
QT_MOC_LITERAL(11, 139, 6), // "parity"
QT_MOC_LITERAL(12, 146, 21), // "QSerialPort::StopBits"
QT_MOC_LITERAL(13, 168, 8) // "stopBits"

    },
    "serialModel\0sg_portOpenFail\0\0sg_portOpenOK\0"
    "st_openPort\0QSerialPortInfo\0portInfo\0"
    "baudRate\0QSerialPort::DataBits\0dataBits\0"
    "QSerialPort::Parity\0parity\0"
    "QSerialPort::StopBits\0stopBits"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_portEvents[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,
       3,    0,   30,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    5,   31,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5, QMetaType::Int, 0x80000000 | 8, 0x80000000 | 10, 0x80000000 | 12,    6,    7,    9,   11,   13,

       0        // eod
};

void serialModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<serialModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sg_portOpenFail(); break;
        case 1: _t->sg_portOpenOK(); break;
        case 2: _t->st_openPort((*reinterpret_cast< QSerialPortInfo(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QSerialPort::DataBits(*)>(_a[3])),(*reinterpret_cast< QSerialPort::Parity(*)>(_a[4])),(*reinterpret_cast< QSerialPort::StopBits(*)>(_a[5]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (serialModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&serialModel::sg_portOpenFail)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (serialModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&serialModel::sg_portOpenOK)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject serialModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_portEvents.data,
    qt_meta_data_portEvents,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *serialModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *serialModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_portEvents.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int serialModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void serialModel::sg_portOpenFail()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void serialModel::sg_portOpenOK()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
