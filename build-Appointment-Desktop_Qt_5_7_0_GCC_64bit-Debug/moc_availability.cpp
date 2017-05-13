/****************************************************************************
** Meta object code from reading C++ file 'availability.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Appointment/availability.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'availability.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Availability_t {
    QByteArrayData data[13];
    char stringdata0[225];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Availability_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Availability_t qt_meta_stringdata_Availability = {
    {
QT_MOC_LITERAL(0, 0, 12), // "Availability"
QT_MOC_LITERAL(1, 13, 20), // "on_MondayBox_toggled"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 7), // "checked"
QT_MOC_LITERAL(4, 43, 20), // "on_SundayBox_toggled"
QT_MOC_LITERAL(5, 64, 21), // "on_TuesdayBox_toggled"
QT_MOC_LITERAL(6, 86, 23), // "on_WednesdayBox_toggled"
QT_MOC_LITERAL(7, 110, 22), // "on_ThursdayBox_toggled"
QT_MOC_LITERAL(8, 133, 20), // "on_FridayBox_toggled"
QT_MOC_LITERAL(9, 154, 22), // "on_SaturdayBox_toggled"
QT_MOC_LITERAL(10, 177, 21), // "on_buttonBox_accepted"
QT_MOC_LITERAL(11, 199, 20), // "on_userBox_activated"
QT_MOC_LITERAL(12, 220, 4) // "arg1"

    },
    "Availability\0on_MondayBox_toggled\0\0"
    "checked\0on_SundayBox_toggled\0"
    "on_TuesdayBox_toggled\0on_WednesdayBox_toggled\0"
    "on_ThursdayBox_toggled\0on_FridayBox_toggled\0"
    "on_SaturdayBox_toggled\0on_buttonBox_accepted\0"
    "on_userBox_activated\0arg1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Availability[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x08 /* Private */,
       4,    1,   62,    2, 0x08 /* Private */,
       5,    1,   65,    2, 0x08 /* Private */,
       6,    1,   68,    2, 0x08 /* Private */,
       7,    1,   71,    2, 0x08 /* Private */,
       8,    1,   74,    2, 0x08 /* Private */,
       9,    1,   77,    2, 0x08 /* Private */,
      10,    0,   80,    2, 0x08 /* Private */,
      11,    1,   81,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,

       0        // eod
};

void Availability::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Availability *_t = static_cast<Availability *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_MondayBox_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->on_SundayBox_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->on_TuesdayBox_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_WednesdayBox_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_ThursdayBox_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->on_FridayBox_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->on_SaturdayBox_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->on_buttonBox_accepted(); break;
        case 8: _t->on_userBox_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Availability::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Availability.data,
      qt_meta_data_Availability,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Availability::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Availability::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Availability.stringdata0))
        return static_cast<void*>(const_cast< Availability*>(this));
    return QDialog::qt_metacast(_clname);
}

int Availability::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
