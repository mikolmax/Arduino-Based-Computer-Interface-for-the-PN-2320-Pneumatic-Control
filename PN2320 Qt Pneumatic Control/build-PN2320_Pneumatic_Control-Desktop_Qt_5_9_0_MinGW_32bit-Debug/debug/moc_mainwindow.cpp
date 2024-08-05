/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../PN2320_Pneumatic_Control/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[16];
    char stringdata0[358];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 24), // "on_directButton1_clicked"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 24), // "on_directButton2_clicked"
QT_MOC_LITERAL(4, 62, 27), // "on_directButton3Pos_clicked"
QT_MOC_LITERAL(5, 90, 27), // "on_directButton3Neg_clicked"
QT_MOC_LITERAL(6, 118, 15), // "on_send_clicked"
QT_MOC_LITERAL(7, 134, 23), // "on_outputButton_clicked"
QT_MOC_LITERAL(8, 158, 22), // "on_pushButton1_pressed"
QT_MOC_LITERAL(9, 181, 23), // "on_pushButton1_released"
QT_MOC_LITERAL(10, 205, 22), // "on_pushButton2_pressed"
QT_MOC_LITERAL(11, 228, 23), // "on_pushButton2_released"
QT_MOC_LITERAL(12, 252, 25), // "on_pushButton3Pos_pressed"
QT_MOC_LITERAL(13, 278, 26), // "on_pushButton3Pos_released"
QT_MOC_LITERAL(14, 305, 25), // "on_pushButton3Neg_pressed"
QT_MOC_LITERAL(15, 331, 26) // "on_pushButton3Neg_released"

    },
    "MainWindow\0on_directButton1_clicked\0"
    "\0on_directButton2_clicked\0"
    "on_directButton3Pos_clicked\0"
    "on_directButton3Neg_clicked\0on_send_clicked\0"
    "on_outputButton_clicked\0on_pushButton1_pressed\0"
    "on_pushButton1_released\0on_pushButton2_pressed\0"
    "on_pushButton2_released\0"
    "on_pushButton3Pos_pressed\0"
    "on_pushButton3Pos_released\0"
    "on_pushButton3Neg_pressed\0"
    "on_pushButton3Neg_released"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    0,   85,    2, 0x08 /* Private */,
       4,    0,   86,    2, 0x08 /* Private */,
       5,    0,   87,    2, 0x08 /* Private */,
       6,    0,   88,    2, 0x08 /* Private */,
       7,    0,   89,    2, 0x08 /* Private */,
       8,    0,   90,    2, 0x08 /* Private */,
       9,    0,   91,    2, 0x08 /* Private */,
      10,    0,   92,    2, 0x08 /* Private */,
      11,    0,   93,    2, 0x08 /* Private */,
      12,    0,   94,    2, 0x08 /* Private */,
      13,    0,   95,    2, 0x08 /* Private */,
      14,    0,   96,    2, 0x08 /* Private */,
      15,    0,   97,    2, 0x08 /* Private */,

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

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_directButton1_clicked(); break;
        case 1: _t->on_directButton2_clicked(); break;
        case 2: _t->on_directButton3Pos_clicked(); break;
        case 3: _t->on_directButton3Neg_clicked(); break;
        case 4: _t->on_send_clicked(); break;
        case 5: _t->on_outputButton_clicked(); break;
        case 6: _t->on_pushButton1_pressed(); break;
        case 7: _t->on_pushButton1_released(); break;
        case 8: _t->on_pushButton2_pressed(); break;
        case 9: _t->on_pushButton2_released(); break;
        case 10: _t->on_pushButton3Pos_pressed(); break;
        case 11: _t->on_pushButton3Pos_released(); break;
        case 12: _t->on_pushButton3Neg_pressed(); break;
        case 13: _t->on_pushButton3Neg_released(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject MainWindow::staticMetaObject = {
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
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
