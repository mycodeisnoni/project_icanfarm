/****************************************************************************
** Meta object code from reading C++ file 'thread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "thread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'thread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Thread_t {
    QByteArrayData data[20];
    char stringdata0[224];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Thread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Thread_t qt_meta_stringdata_Thread = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Thread"
QT_MOC_LITERAL(1, 7, 12), // "sendTempData"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 1), // "t"
QT_MOC_LITERAL(4, 23, 13), // "sendHumidData"
QT_MOC_LITERAL(5, 37, 1), // "h"
QT_MOC_LITERAL(6, 39, 11), // "sendCo2Data"
QT_MOC_LITERAL(7, 51, 2), // "co"
QT_MOC_LITERAL(8, 54, 18), // "recvMqttFromServer"
QT_MOC_LITERAL(9, 73, 19), // "mqtt::async_client*"
QT_MOC_LITERAL(10, 93, 12), // "mqtt_client_"
QT_MOC_LITERAL(11, 106, 17), // "tempSensorProcess"
QT_MOC_LITERAL(12, 124, 12), // "QSerialPort*"
QT_MOC_LITERAL(13, 137, 12), // "serial_port_"
QT_MOC_LITERAL(14, 150, 18), // "humidSensorProcess"
QT_MOC_LITERAL(15, 169, 16), // "co2SensorProcess"
QT_MOC_LITERAL(16, 186, 15), // "sendMqtt2Server"
QT_MOC_LITERAL(17, 202, 11), // "std::string"
QT_MOC_LITERAL(18, 214, 5), // "topic"
QT_MOC_LITERAL(19, 220, 3) // "msg"

    },
    "Thread\0sendTempData\0\0t\0sendHumidData\0"
    "h\0sendCo2Data\0co\0recvMqttFromServer\0"
    "mqtt::async_client*\0mqtt_client_\0"
    "tempSensorProcess\0QSerialPort*\0"
    "serial_port_\0humidSensorProcess\0"
    "co2SensorProcess\0sendMqtt2Server\0"
    "std::string\0topic\0msg"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Thread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       4,    1,   57,    2, 0x06 /* Public */,
       6,    1,   60,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   63,    2, 0x08 /* Private */,
      11,    2,   66,    2, 0x08 /* Private */,
      14,    2,   71,    2, 0x08 /* Private */,
      15,    2,   76,    2, 0x08 /* Private */,
      16,    3,   81,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    5,
    QMetaType::Void, QMetaType::Int,    7,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 9, 0x80000000 | 12,   10,   13,
    QMetaType::Void, 0x80000000 | 9, 0x80000000 | 12,   10,   13,
    QMetaType::Void, 0x80000000 | 9, 0x80000000 | 12,   10,   13,
    QMetaType::Void, 0x80000000 | 9, 0x80000000 | 17, 0x80000000 | 17,   10,   18,   19,

       0        // eod
};

void Thread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Thread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendTempData((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->sendHumidData((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->sendCo2Data((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->recvMqttFromServer((*reinterpret_cast< mqtt::async_client*(*)>(_a[1]))); break;
        case 4: _t->tempSensorProcess((*reinterpret_cast< mqtt::async_client*(*)>(_a[1])),(*reinterpret_cast< QSerialPort*(*)>(_a[2]))); break;
        case 5: _t->humidSensorProcess((*reinterpret_cast< mqtt::async_client*(*)>(_a[1])),(*reinterpret_cast< QSerialPort*(*)>(_a[2]))); break;
        case 6: _t->co2SensorProcess((*reinterpret_cast< mqtt::async_client*(*)>(_a[1])),(*reinterpret_cast< QSerialPort*(*)>(_a[2]))); break;
        case 7: _t->sendMqtt2Server((*reinterpret_cast< mqtt::async_client*(*)>(_a[1])),(*reinterpret_cast< const std::string(*)>(_a[2])),(*reinterpret_cast< const std::string(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QSerialPort* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QSerialPort* >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QSerialPort* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Thread::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Thread::sendTempData)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Thread::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Thread::sendHumidData)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Thread::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Thread::sendCo2Data)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Thread::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_Thread.data,
    qt_meta_data_Thread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Thread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Thread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Thread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int Thread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Thread::sendTempData(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Thread::sendHumidData(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Thread::sendCo2Data(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
