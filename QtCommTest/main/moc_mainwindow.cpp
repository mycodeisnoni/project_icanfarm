/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[26];
    char stringdata0[271];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 13), // "upTemperature"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 15), // "downTemperature"
QT_MOC_LITERAL(4, 42, 9), // "downHumid"
QT_MOC_LITERAL(5, 52, 7), // "upHumid"
QT_MOC_LITERAL(6, 60, 5), // "upCo2"
QT_MOC_LITERAL(7, 66, 7), // "downCo2"
QT_MOC_LITERAL(8, 74, 8), // "goLogout"
QT_MOC_LITERAL(9, 83, 16), // "changeWaterColor"
QT_MOC_LITERAL(10, 100, 15), // "changeWindColor"
QT_MOC_LITERAL(11, 116, 14), // "changeSunColor"
QT_MOC_LITERAL(12, 131, 16), // "changeCloudColor"
QT_MOC_LITERAL(13, 148, 11), // "changeValue"
QT_MOC_LITERAL(14, 160, 15), // "recvLogInResult"
QT_MOC_LITERAL(15, 176, 4), // "flag"
QT_MOC_LITERAL(16, 181, 15), // "sendMqtt2Server"
QT_MOC_LITERAL(17, 197, 11), // "std::string"
QT_MOC_LITERAL(18, 209, 5), // "topic"
QT_MOC_LITERAL(19, 215, 3), // "msg"
QT_MOC_LITERAL(20, 219, 14), // "changeMqttTemp"
QT_MOC_LITERAL(21, 234, 1), // "t"
QT_MOC_LITERAL(22, 236, 15), // "changeMqttHumid"
QT_MOC_LITERAL(23, 252, 1), // "h"
QT_MOC_LITERAL(24, 254, 13), // "changeMqttCo2"
QT_MOC_LITERAL(25, 268, 2) // "co"

    },
    "MainWindow\0upTemperature\0\0downTemperature\0"
    "downHumid\0upHumid\0upCo2\0downCo2\0"
    "goLogout\0changeWaterColor\0changeWindColor\0"
    "changeSunColor\0changeCloudColor\0"
    "changeValue\0recvLogInResult\0flag\0"
    "sendMqtt2Server\0std::string\0topic\0msg\0"
    "changeMqttTemp\0t\0changeMqttHumid\0h\0"
    "changeMqttCo2\0co"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x08 /* Private */,
       3,    0,  100,    2, 0x08 /* Private */,
       4,    0,  101,    2, 0x08 /* Private */,
       5,    0,  102,    2, 0x08 /* Private */,
       6,    0,  103,    2, 0x08 /* Private */,
       7,    0,  104,    2, 0x08 /* Private */,
       8,    0,  105,    2, 0x08 /* Private */,
       9,    0,  106,    2, 0x08 /* Private */,
      10,    0,  107,    2, 0x08 /* Private */,
      11,    0,  108,    2, 0x08 /* Private */,
      12,    0,  109,    2, 0x08 /* Private */,
      13,    0,  110,    2, 0x08 /* Private */,
      14,    1,  111,    2, 0x08 /* Private */,
      16,    2,  114,    2, 0x08 /* Private */,
      20,    1,  119,    2, 0x08 /* Private */,
      22,    1,  122,    2, 0x08 /* Private */,
      24,    1,  125,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, 0x80000000 | 17, 0x80000000 | 17,   18,   19,
    QMetaType::Void, QMetaType::Double,   21,
    QMetaType::Void, QMetaType::Double,   23,
    QMetaType::Void, QMetaType::Int,   25,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->upTemperature(); break;
        case 1: _t->downTemperature(); break;
        case 2: _t->downHumid(); break;
        case 3: _t->upHumid(); break;
        case 4: _t->upCo2(); break;
        case 5: _t->downCo2(); break;
        case 6: _t->goLogout(); break;
        case 7: _t->changeWaterColor(); break;
        case 8: _t->changeWindColor(); break;
        case 9: _t->changeSunColor(); break;
        case 10: _t->changeCloudColor(); break;
        case 11: _t->changeValue(); break;
        case 12: _t->recvLogInResult((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->sendMqtt2Server((*reinterpret_cast< const std::string(*)>(_a[1])),(*reinterpret_cast< const std::string(*)>(_a[2]))); break;
        case 14: _t->changeMqttTemp((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 15: _t->changeMqttHumid((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 16: _t->changeMqttCo2((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
