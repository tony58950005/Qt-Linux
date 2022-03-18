/****************************************************************************
** Meta object code from reading C++ file 'gamearea.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "gamearea.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gamearea.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GameArea_t {
    QByteArrayData data[15];
    char stringdata0[143];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GameArea_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GameArea_t qt_meta_stringdata_GameArea = {
    {
QT_MOC_LITERAL(0, 0, 8), // "GameArea"
QT_MOC_LITERAL(1, 9, 10), // "gamePaused"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 11), // "gameResumed"
QT_MOC_LITERAL(4, 33, 9), // "gameReset"
QT_MOC_LITERAL(5, 43, 9), // "gameEnded"
QT_MOC_LITERAL(6, 53, 11), // "updateTimer"
QT_MOC_LITERAL(7, 65, 5), // "steps"
QT_MOC_LITERAL(8, 71, 12), // "stateChanged"
QT_MOC_LITERAL(9, 84, 8), // "saveGame"
QT_MOC_LITERAL(10, 93, 8), // "loadGame"
QT_MOC_LITERAL(11, 102, 9), // "startGame"
QT_MOC_LITERAL(12, 112, 9), // "pauseGame"
QT_MOC_LITERAL(13, 122, 10), // "resumeGame"
QT_MOC_LITERAL(14, 133, 9) // "resetGame"

    },
    "GameArea\0gamePaused\0\0gameResumed\0"
    "gameReset\0gameEnded\0updateTimer\0steps\0"
    "stateChanged\0saveGame\0loadGame\0startGame\0"
    "pauseGame\0resumeGame\0resetGame"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GameArea[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,
       3,    0,   75,    2, 0x06 /* Public */,
       4,    0,   76,    2, 0x06 /* Public */,
       5,    0,   77,    2, 0x06 /* Public */,
       6,    1,   78,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   81,    2, 0x0a /* Public */,
       9,    0,   82,    2, 0x0a /* Public */,
      10,    0,   83,    2, 0x0a /* Public */,
      11,    0,   84,    2, 0x0a /* Public */,
      12,    0,   85,    2, 0x0a /* Public */,
      13,    0,   86,    2, 0x0a /* Public */,
      14,    0,   87,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GameArea::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GameArea *_t = static_cast<GameArea *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->gamePaused(); break;
        case 1: _t->gameResumed(); break;
        case 2: _t->gameReset(); break;
        case 3: _t->gameEnded(); break;
        case 4: _t->updateTimer((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->stateChanged(); break;
        case 6: _t->saveGame(); break;
        case 7: _t->loadGame(); break;
        case 8: _t->startGame(); break;
        case 9: _t->pauseGame(); break;
        case 10: _t->resumeGame(); break;
        case 11: _t->resetGame(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GameArea::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GameArea::gamePaused)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GameArea::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GameArea::gameResumed)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (GameArea::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GameArea::gameReset)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (GameArea::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GameArea::gameEnded)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (GameArea::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GameArea::updateTimer)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GameArea::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GameArea.data,
      qt_meta_data_GameArea,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *GameArea::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameArea::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GameArea.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int GameArea::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void GameArea::gamePaused()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void GameArea::gameResumed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void GameArea::gameReset()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void GameArea::gameEnded()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void GameArea::updateTimer(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
