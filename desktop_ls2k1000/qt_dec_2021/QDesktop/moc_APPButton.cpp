/****************************************************************************
** Meta object code from reading C++ file 'APPButton.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "APPButton.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'APPButton.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_APPButton_t {
    QByteArrayData data[9];
    char stringdata0[100];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_APPButton_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_APPButton_t qt_meta_stringdata_APPButton = {
    {
QT_MOC_LITERAL(0, 0, 9), // "APPButton"
QT_MOC_LITERAL(1, 10, 11), // "appFinished"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 9), // "appBacked"
QT_MOC_LITERAL(4, 33, 8), // "appFored"
QT_MOC_LITERAL(5, 42, 8), // "appMoved"
QT_MOC_LITERAL(6, 51, 8), // "appIndex"
QT_MOC_LITERAL(7, 60, 19), // "appFlagTimerOutSlot"
QT_MOC_LITERAL(8, 80, 19) // "appExecTimerOutSlot"

    },
    "APPButton\0appFinished\0\0appBacked\0"
    "appFored\0appMoved\0appIndex\0"
    "appFlagTimerOutSlot\0appExecTimerOutSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_APPButton[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    0,   46,    2, 0x06 /* Public */,
       5,    1,   47,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   50,    2, 0x09 /* Protected */,
       8,    0,   51,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void APPButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        APPButton *_t = static_cast<APPButton *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->appFinished(); break;
        case 1: _t->appBacked(); break;
        case 2: _t->appFored(); break;
        case 3: _t->appMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->appFlagTimerOutSlot(); break;
        case 5: _t->appExecTimerOutSlot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (APPButton::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&APPButton::appFinished)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (APPButton::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&APPButton::appBacked)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (APPButton::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&APPButton::appFored)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (APPButton::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&APPButton::appMoved)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject APPButton::staticMetaObject = {
    { &QPushButton::staticMetaObject, qt_meta_stringdata_APPButton.data,
      qt_meta_data_APPButton,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *APPButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *APPButton::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_APPButton.stringdata0))
        return static_cast<void*>(this);
    return QPushButton::qt_metacast(_clname);
}

int APPButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void APPButton::appFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void APPButton::appBacked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void APPButton::appFored()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void APPButton::appMoved(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
