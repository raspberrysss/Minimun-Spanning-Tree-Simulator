/****************************************************************************
** Meta object code from reading C++ file 'mst.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../GRAPH_TREE2/mst.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mst.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MST_t {
    QByteArrayData data[18];
    char stringdata0[264];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MST_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MST_t qt_meta_stringdata_MST = {
    {
QT_MOC_LITERAL(0, 0, 3), // "MST"
QT_MOC_LITERAL(1, 4, 15), // "mousePressEvent"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 12), // "QMouseEvent*"
QT_MOC_LITERAL(4, 34, 5), // "event"
QT_MOC_LITERAL(5, 40, 10), // "paintEvent"
QT_MOC_LITERAL(6, 51, 12), // "QPaintEvent*"
QT_MOC_LITERAL(7, 64, 17), // "on_addvex_clicked"
QT_MOC_LITERAL(8, 82, 17), // "on_addadj_clicked"
QT_MOC_LITERAL(9, 100, 21), // "on_showweight_clicked"
QT_MOC_LITERAL(10, 122, 18), // "on_changew_clicked"
QT_MOC_LITERAL(11, 141, 18), // "on_delevex_clicked"
QT_MOC_LITERAL(12, 160, 19), // "on_changein_clicked"
QT_MOC_LITERAL(13, 180, 18), // "on_deleadj_clicked"
QT_MOC_LITERAL(14, 199, 15), // "on_prim_clicked"
QT_MOC_LITERAL(15, 215, 12), // "on_k_clicked"
QT_MOC_LITERAL(16, 228, 18), // "on_clean_2_clicked"
QT_MOC_LITERAL(17, 247, 16) // "on_clean_clicked"

    },
    "MST\0mousePressEvent\0\0QMouseEvent*\0"
    "event\0paintEvent\0QPaintEvent*\0"
    "on_addvex_clicked\0on_addadj_clicked\0"
    "on_showweight_clicked\0on_changew_clicked\0"
    "on_delevex_clicked\0on_changein_clicked\0"
    "on_deleadj_clicked\0on_prim_clicked\0"
    "on_k_clicked\0on_clean_2_clicked\0"
    "on_clean_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MST[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x0a /* Public */,
       5,    1,   82,    2, 0x0a /* Public */,
       7,    0,   85,    2, 0x08 /* Private */,
       8,    0,   86,    2, 0x08 /* Private */,
       9,    0,   87,    2, 0x08 /* Private */,
      10,    0,   88,    2, 0x08 /* Private */,
      11,    0,   89,    2, 0x08 /* Private */,
      12,    0,   90,    2, 0x08 /* Private */,
      13,    0,   91,    2, 0x08 /* Private */,
      14,    0,   92,    2, 0x08 /* Private */,
      15,    0,   93,    2, 0x08 /* Private */,
      16,    0,   94,    2, 0x08 /* Private */,
      17,    0,   95,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    2,
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

       0        // eod
};

void MST::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MST *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 1: _t->paintEvent((*reinterpret_cast< QPaintEvent*(*)>(_a[1]))); break;
        case 2: _t->on_addvex_clicked(); break;
        case 3: _t->on_addadj_clicked(); break;
        case 4: _t->on_showweight_clicked(); break;
        case 5: _t->on_changew_clicked(); break;
        case 6: _t->on_delevex_clicked(); break;
        case 7: _t->on_changein_clicked(); break;
        case 8: _t->on_deleadj_clicked(); break;
        case 9: _t->on_prim_clicked(); break;
        case 10: _t->on_k_clicked(); break;
        case 11: _t->on_clean_2_clicked(); break;
        case 12: _t->on_clean_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MST::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_MST.data,
    qt_meta_data_MST,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MST::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MST::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MST.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MST::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
