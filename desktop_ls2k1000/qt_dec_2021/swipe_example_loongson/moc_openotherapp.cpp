/****************************************************************************
** Meta object code from reading C++ file 'openotherapp.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "openotherapp.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'openotherapp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_OpenOtherApp_t {
    QByteArrayData data[22];
    char stringdata0[242];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OpenOtherApp_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OpenOtherApp_t qt_meta_stringdata_OpenOtherApp = {
    {
QT_MOC_LITERAL(0, 0, 12), // "OpenOtherApp"
QT_MOC_LITERAL(1, 13, 11), // "bestChanged"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 8), // "updateUI"
QT_MOC_LITERAL(4, 35, 12), // "openCalendar"
QT_MOC_LITERAL(5, 48, 9), // "openClock"
QT_MOC_LITERAL(6, 58, 10), // "openSerial"
QT_MOC_LITERAL(7, 69, 9), // "openRs485"
QT_MOC_LITERAL(8, 79, 7), // "openCan"
QT_MOC_LITERAL(9, 87, 7), // "openLed"
QT_MOC_LITERAL(10, 95, 15), // "openTemperature"
QT_MOC_LITERAL(11, 111, 11), // "openWeather"
QT_MOC_LITERAL(12, 123, 10), // "openBuzzer"
QT_MOC_LITERAL(13, 134, 15), // "openBearmonitor"
QT_MOC_LITERAL(14, 150, 15), // "openMediaplayer"
QT_MOC_LITERAL(15, 166, 7), // "openGps"
QT_MOC_LITERAL(16, 174, 17), // "openPictureviewer"
QT_MOC_LITERAL(17, 192, 12), // "openFileview"
QT_MOC_LITERAL(18, 205, 10), // "openTetris"
QT_MOC_LITERAL(19, 216, 10), // "openWuziqi"
QT_MOC_LITERAL(20, 227, 9), // "openSnake"
QT_MOC_LITERAL(21, 237, 4) // "best"

    },
    "OpenOtherApp\0bestChanged\0\0updateUI\0"
    "openCalendar\0openClock\0openSerial\0"
    "openRs485\0openCan\0openLed\0openTemperature\0"
    "openWeather\0openBuzzer\0openBearmonitor\0"
    "openMediaplayer\0openGps\0openPictureviewer\0"
    "openFileview\0openTetris\0openWuziqi\0"
    "openSnake\0best"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OpenOtherApp[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       1,  128, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  109,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,  110,    2, 0x0a /* Public */,
       4,    0,  111,    2, 0x0a /* Public */,
       5,    0,  112,    2, 0x0a /* Public */,
       6,    0,  113,    2, 0x0a /* Public */,
       7,    0,  114,    2, 0x0a /* Public */,
       8,    0,  115,    2, 0x0a /* Public */,
       9,    0,  116,    2, 0x0a /* Public */,
      10,    0,  117,    2, 0x0a /* Public */,
      11,    0,  118,    2, 0x0a /* Public */,
      12,    0,  119,    2, 0x0a /* Public */,
      13,    0,  120,    2, 0x0a /* Public */,
      14,    0,  121,    2, 0x0a /* Public */,
      15,    0,  122,    2, 0x0a /* Public */,
      16,    0,  123,    2, 0x0a /* Public */,
      17,    0,  124,    2, 0x0a /* Public */,
      18,    0,  125,    2, 0x0a /* Public */,
      19,    0,  126,    2, 0x0a /* Public */,
      20,    0,  127,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      21, QMetaType::Void, 0x00095000,

 // properties: notify_signal_id
       0,

       0        // eod
};

void OpenOtherApp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        OpenOtherApp *_t = static_cast<OpenOtherApp *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->bestChanged(); break;
        case 1: _t->updateUI(); break;
        case 2: _t->openCalendar(); break;
        case 3: _t->openClock(); break;
        case 4: _t->openSerial(); break;
        case 5: _t->openRs485(); break;
        case 6: _t->openCan(); break;
        case 7: _t->openLed(); break;
        case 8: _t->openTemperature(); break;
        case 9: _t->openWeather(); break;
        case 10: _t->openBuzzer(); break;
        case 11: _t->openBearmonitor(); break;
        case 12: _t->openMediaplayer(); break;
        case 13: _t->openGps(); break;
        case 14: _t->openPictureviewer(); break;
        case 15: _t->openFileview(); break;
        case 16: _t->openTetris(); break;
        case 17: _t->openWuziqi(); break;
        case 18: _t->openSnake(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (OpenOtherApp::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OpenOtherApp::bestChanged)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject OpenOtherApp::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_OpenOtherApp.data,
      qt_meta_data_OpenOtherApp,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *OpenOtherApp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OpenOtherApp::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_OpenOtherApp.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int OpenOtherApp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 19;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void OpenOtherApp::bestChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
