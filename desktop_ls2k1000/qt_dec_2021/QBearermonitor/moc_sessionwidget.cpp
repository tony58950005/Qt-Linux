/****************************************************************************
** Meta object code from reading C++ file 'sessionwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "sessionwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sessionwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SessionWidget_t {
    QByteArrayData data[10];
    char stringdata0[137];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SessionWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SessionWidget_t qt_meta_stringdata_SessionWidget = {
    {
QT_MOC_LITERAL(0, 0, 13), // "SessionWidget"
QT_MOC_LITERAL(1, 14, 11), // "openSession"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 15), // "openSyncSession"
QT_MOC_LITERAL(4, 43, 12), // "closeSession"
QT_MOC_LITERAL(5, 56, 11), // "stopSession"
QT_MOC_LITERAL(6, 68, 13), // "updateSession"
QT_MOC_LITERAL(7, 82, 18), // "updateSessionError"
QT_MOC_LITERAL(8, 101, 29), // "QNetworkSession::SessionError"
QT_MOC_LITERAL(9, 131, 5) // "error"

    },
    "SessionWidget\0openSession\0\0openSyncSession\0"
    "closeSession\0stopSession\0updateSession\0"
    "updateSessionError\0QNetworkSession::SessionError\0"
    "error"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SessionWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    1,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,

       0        // eod
};

void SessionWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SessionWidget *_t = static_cast<SessionWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->openSession(); break;
        case 1: _t->openSyncSession(); break;
        case 2: _t->closeSession(); break;
        case 3: _t->stopSession(); break;
        case 4: _t->updateSession(); break;
        case 5: _t->updateSessionError((*reinterpret_cast< QNetworkSession::SessionError(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkSession::SessionError >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SessionWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SessionWidget.data,
      qt_meta_data_SessionWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SessionWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SessionWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SessionWidget.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui_SessionWidget"))
        return static_cast< Ui_SessionWidget*>(this);
    return QWidget::qt_metacast(_clname);
}

int SessionWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
