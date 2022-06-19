/****************************************************************************
** Meta object code from reading C++ file 'bridge.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../src/bridge/bridge.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bridge.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_bridge_t {
    QByteArrayData data[15];
    char stringdata0[191];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_bridge_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_bridge_t qt_meta_stringdata_bridge = {
    {
QT_MOC_LITERAL(0, 0, 6), // "bridge"
QT_MOC_LITERAL(1, 7, 11), // "sg_openPort"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 15), // "QSerialPortInfo"
QT_MOC_LITERAL(4, 36, 8), // "portInfo"
QT_MOC_LITERAL(5, 45, 8), // "baudRate"
QT_MOC_LITERAL(6, 54, 21), // "QSerialPort::DataBits"
QT_MOC_LITERAL(7, 76, 8), // "dataBits"
QT_MOC_LITERAL(8, 85, 19), // "QSerialPort::Parity"
QT_MOC_LITERAL(9, 105, 6), // "parity"
QT_MOC_LITERAL(10, 112, 21), // "QSerialPort::StopBits"
QT_MOC_LITERAL(11, 134, 8), // "stopBits"
QT_MOC_LITERAL(12, 143, 7), // "sg_test"
QT_MOC_LITERAL(13, 151, 18), // "sg_show_portOpenOK"
QT_MOC_LITERAL(14, 170, 20) // "sg_show_portOpenFail"

    },
    "bridge\0sg_openPort\0\0QSerialPortInfo\0"
    "portInfo\0baudRate\0QSerialPort::DataBits\0"
    "dataBits\0QSerialPort::Parity\0parity\0"
    "QSerialPort::StopBits\0stopBits\0sg_test\0"
    "sg_show_portOpenOK\0sg_show_portOpenFail"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_bridge[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    5,   34,    2, 0x06 /* Public */,
      12,    0,   45,    2, 0x06 /* Public */,
      13,    0,   46,    2, 0x06 /* Public */,
      14,    0,   47,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, 0x80000000 | 6, 0x80000000 | 8, 0x80000000 | 10,    4,    5,    7,    9,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void bridge::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<bridge *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sg_openPort((*reinterpret_cast< QSerialPortInfo(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QSerialPort::DataBits(*)>(_a[3])),(*reinterpret_cast< QSerialPort::Parity(*)>(_a[4])),(*reinterpret_cast< QSerialPort::StopBits(*)>(_a[5]))); break;
        case 1: _t->sg_test(); break;
        case 2: _t->sg_show_portOpenOK(); break;
        case 3: _t->sg_show_portOpenFail(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (bridge::*)(QSerialPortInfo , int , QSerialPort::DataBits , QSerialPort::Parity , QSerialPort::StopBits );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&bridge::sg_openPort)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (bridge::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&bridge::sg_test)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (bridge::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&bridge::sg_show_portOpenOK)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (bridge::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&bridge::sg_show_portOpenFail)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject bridge::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_bridge.data,
    qt_meta_data_bridge,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *bridge::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *bridge::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_bridge.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int bridge::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void bridge::sg_openPort(QSerialPortInfo _t1, int _t2, QSerialPort::DataBits _t3, QSerialPort::Parity _t4, QSerialPort::StopBits _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void bridge::sg_test()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void bridge::sg_show_portOpenOK()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void bridge::sg_show_portOpenFail()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
