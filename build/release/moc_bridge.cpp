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
    QByteArrayData data[28];
    char stringdata0[438];
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
QT_MOC_LITERAL(12, 143, 22), // "sg_done_model_openPort"
QT_MOC_LITERAL(13, 166, 23), // "isOpenSerialPortSuccess"
QT_MOC_LITERAL(14, 190, 9), // "sg_showUI"
QT_MOC_LITERAL(15, 200, 26), // "sg_enable_PortDataListener"
QT_MOC_LITERAL(16, 227, 16), // "sg_ui_openPortOK"
QT_MOC_LITERAL(17, 244, 18), // "sg_ui_openPortFail"
QT_MOC_LITERAL(18, 263, 20), // "sg_ui_dataAppendToUI"
QT_MOC_LITERAL(19, 284, 5), // "char*"
QT_MOC_LITERAL(20, 290, 4), // "data"
QT_MOC_LITERAL(21, 295, 12), // "sg_closePort"
QT_MOC_LITERAL(22, 308, 23), // "sg_done_model_closePort"
QT_MOC_LITERAL(23, 332, 17), // "sg_ui_closePorkOK"
QT_MOC_LITERAL(24, 350, 18), // "st_bridge_openPort"
QT_MOC_LITERAL(25, 369, 27), // "st_bridge_returnOpenPortRes"
QT_MOC_LITERAL(26, 397, 20), // "st_on_readDataThread"
QT_MOC_LITERAL(27, 418, 19) // "st_bridge_closePort"

    },
    "bridge\0sg_openPort\0\0QSerialPortInfo\0"
    "portInfo\0baudRate\0QSerialPort::DataBits\0"
    "dataBits\0QSerialPort::Parity\0parity\0"
    "QSerialPort::StopBits\0stopBits\0"
    "sg_done_model_openPort\0isOpenSerialPortSuccess\0"
    "sg_showUI\0sg_enable_PortDataListener\0"
    "sg_ui_openPortOK\0sg_ui_openPortFail\0"
    "sg_ui_dataAppendToUI\0char*\0data\0"
    "sg_closePort\0sg_done_model_closePort\0"
    "sg_ui_closePorkOK\0st_bridge_openPort\0"
    "st_bridge_returnOpenPortRes\0"
    "st_on_readDataThread\0st_bridge_closePort"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_bridge[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    5,   84,    2, 0x06 /* Public */,
      12,    1,   95,    2, 0x06 /* Public */,
      14,    0,   98,    2, 0x06 /* Public */,
      15,    0,   99,    2, 0x06 /* Public */,
      16,    0,  100,    2, 0x06 /* Public */,
      17,    0,  101,    2, 0x06 /* Public */,
      18,    1,  102,    2, 0x06 /* Public */,
      21,    0,  105,    2, 0x06 /* Public */,
      22,    0,  106,    2, 0x06 /* Public */,
      23,    0,  107,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      24,    5,  108,    2, 0x0a /* Public */,
      25,    1,  119,    2, 0x0a /* Public */,
      26,    0,  122,    2, 0x0a /* Public */,
      27,    0,  123,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, 0x80000000 | 6, 0x80000000 | 8, 0x80000000 | 10,    4,    5,    7,    9,   11,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 19,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, 0x80000000 | 6, 0x80000000 | 8, 0x80000000 | 10,    4,    5,    7,    9,   11,
    QMetaType::Void, QMetaType::Bool,   13,
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
        case 1: _t->sg_done_model_openPort((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->sg_showUI(); break;
        case 3: _t->sg_enable_PortDataListener(); break;
        case 4: _t->sg_ui_openPortOK(); break;
        case 5: _t->sg_ui_openPortFail(); break;
        case 6: _t->sg_ui_dataAppendToUI((*reinterpret_cast< char*(*)>(_a[1]))); break;
        case 7: _t->sg_closePort(); break;
        case 8: _t->sg_done_model_closePort(); break;
        case 9: _t->sg_ui_closePorkOK(); break;
        case 10: _t->st_bridge_openPort((*reinterpret_cast< QSerialPortInfo(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QSerialPort::DataBits(*)>(_a[3])),(*reinterpret_cast< QSerialPort::Parity(*)>(_a[4])),(*reinterpret_cast< QSerialPort::StopBits(*)>(_a[5]))); break;
        case 11: _t->st_bridge_returnOpenPortRes((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->st_on_readDataThread(); break;
        case 13: _t->st_bridge_closePort(); break;
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
            using _t = void (bridge::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&bridge::sg_done_model_openPort)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (bridge::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&bridge::sg_showUI)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (bridge::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&bridge::sg_enable_PortDataListener)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (bridge::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&bridge::sg_ui_openPortOK)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (bridge::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&bridge::sg_ui_openPortFail)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (bridge::*)(char * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&bridge::sg_ui_dataAppendToUI)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (bridge::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&bridge::sg_closePort)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (bridge::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&bridge::sg_done_model_closePort)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (bridge::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&bridge::sg_ui_closePorkOK)) {
                *result = 9;
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
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
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
void bridge::sg_done_model_openPort(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void bridge::sg_showUI()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void bridge::sg_enable_PortDataListener()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void bridge::sg_ui_openPortOK()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void bridge::sg_ui_openPortFail()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void bridge::sg_ui_dataAppendToUI(char * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void bridge::sg_closePort()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void bridge::sg_done_model_closePort()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void bridge::sg_ui_closePorkOK()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
