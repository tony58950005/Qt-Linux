/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[21];
    char stringdata0[370];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 21), // "slotClickedPbListMode"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 24), // "slotClickedPbPreviewMode"
QT_MOC_LITERAL(4, 59, 19), // "slotClickedPbFSMode"
QT_MOC_LITERAL(5, 79, 28), // "slotCurrentItemChangedIDList"
QT_MOC_LITERAL(6, 108, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(7, 125, 7), // "current"
QT_MOC_LITERAL(8, 133, 8), // "previous"
QT_MOC_LITERAL(9, 142, 27), // "slotItemDoubleClickedIDList"
QT_MOC_LITERAL(10, 170, 4), // "item"
QT_MOC_LITERAL(11, 175, 18), // "slotTimeoutDUTimer"
QT_MOC_LITERAL(12, 194, 20), // "slotTimeoutPlayTimer"
QT_MOC_LITERAL(13, 215, 19), // "slotTimeoutHMBTimer"
QT_MOC_LITERAL(14, 235, 17), // "slotClickedPbPlay"
QT_MOC_LITERAL(15, 253, 21), // "slotClickedPbPrevious"
QT_MOC_LITERAL(16, 275, 17), // "slotClickedPbNext"
QT_MOC_LITERAL(17, 293, 20), // "slotClickedPbEnlarge"
QT_MOC_LITERAL(18, 314, 19), // "slotClickedPbReduce"
QT_MOC_LITERAL(19, 334, 17), // "slotClickedPbRN90"
QT_MOC_LITERAL(20, 352, 17) // "slotClickedPbRP90"

    },
    "MainWindow\0slotClickedPbListMode\0\0"
    "slotClickedPbPreviewMode\0slotClickedPbFSMode\0"
    "slotCurrentItemChangedIDList\0"
    "QListWidgetItem*\0current\0previous\0"
    "slotItemDoubleClickedIDList\0item\0"
    "slotTimeoutDUTimer\0slotTimeoutPlayTimer\0"
    "slotTimeoutHMBTimer\0slotClickedPbPlay\0"
    "slotClickedPbPrevious\0slotClickedPbNext\0"
    "slotClickedPbEnlarge\0slotClickedPbReduce\0"
    "slotClickedPbRN90\0slotClickedPbRP90"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x0a /* Public */,
       3,    0,   90,    2, 0x0a /* Public */,
       4,    0,   91,    2, 0x0a /* Public */,
       5,    2,   92,    2, 0x0a /* Public */,
       9,    1,   97,    2, 0x0a /* Public */,
      11,    0,  100,    2, 0x0a /* Public */,
      12,    0,  101,    2, 0x0a /* Public */,
      13,    0,  102,    2, 0x0a /* Public */,
      14,    0,  103,    2, 0x0a /* Public */,
      15,    0,  104,    2, 0x0a /* Public */,
      16,    0,  105,    2, 0x0a /* Public */,
      17,    0,  106,    2, 0x0a /* Public */,
      18,    0,  107,    2, 0x0a /* Public */,
      19,    0,  108,    2, 0x0a /* Public */,
      20,    0,  109,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 6,    7,    8,
    QMetaType::Void, 0x80000000 | 6,   10,
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

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotClickedPbListMode(); break;
        case 1: _t->slotClickedPbPreviewMode(); break;
        case 2: _t->slotClickedPbFSMode(); break;
        case 3: _t->slotCurrentItemChangedIDList((*reinterpret_cast< QListWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QListWidgetItem*(*)>(_a[2]))); break;
        case 4: _t->slotItemDoubleClickedIDList((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 5: _t->slotTimeoutDUTimer(); break;
        case 6: _t->slotTimeoutPlayTimer(); break;
        case 7: _t->slotTimeoutHMBTimer(); break;
        case 8: _t->slotClickedPbPlay(); break;
        case 9: _t->slotClickedPbPrevious(); break;
        case 10: _t->slotClickedPbNext(); break;
        case 11: _t->slotClickedPbEnlarge(); break;
        case 12: _t->slotClickedPbReduce(); break;
        case 13: _t->slotClickedPbRN90(); break;
        case 14: _t->slotClickedPbRP90(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


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
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
