/****************************************************************************
** Meta object code from reading C++ file 'mqtt.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "mqtt.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mqtt.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MqttCallback_t {
    QByteArrayData data[8];
    char stringdata0[66];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MqttCallback_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MqttCallback_t qt_meta_stringdata_MqttCallback = {
    {
QT_MOC_LITERAL(0, 0, 12), // "MqttCallback"
QT_MOC_LITERAL(1, 13, 14), // "sendServerTemp"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 1), // "t"
QT_MOC_LITERAL(4, 31, 15), // "sendServerHumid"
QT_MOC_LITERAL(5, 47, 1), // "h"
QT_MOC_LITERAL(6, 49, 13), // "sendServerCo2"
QT_MOC_LITERAL(7, 63, 2) // "co"

    },
    "MqttCallback\0sendServerTemp\0\0t\0"
    "sendServerHumid\0h\0sendServerCo2\0co"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MqttCallback[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       4,    1,   32,    2, 0x06 /* Public */,
       6,    1,   35,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    5,
    QMetaType::Void, QMetaType::Int,    7,

       0        // eod
};

void MqttCallback::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MqttCallback *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendServerTemp((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->sendServerHumid((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->sendServerCo2((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MqttCallback::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MqttCallback::sendServerTemp)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MqttCallback::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MqttCallback::sendServerHumid)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MqttCallback::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MqttCallback::sendServerCo2)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MqttCallback::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_MqttCallback.data,
    qt_meta_data_MqttCallback,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MqttCallback::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MqttCallback::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MqttCallback.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "mqtt::callback"))
        return static_cast< mqtt::callback*>(this);
    return QObject::qt_metacast(_clname);
}

int MqttCallback::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void MqttCallback::sendServerTemp(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MqttCallback::sendServerHumid(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MqttCallback::sendServerCo2(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
