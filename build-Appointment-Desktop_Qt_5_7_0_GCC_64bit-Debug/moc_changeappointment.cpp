/****************************************************************************
** Meta object code from reading C++ file 'changeappointment.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Appointment/changeappointment.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'changeappointment.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ChangeAppointment_t {
    QByteArrayData data[13];
    char stringdata0[196];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ChangeAppointment_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ChangeAppointment_t qt_meta_stringdata_ChangeAppointment = {
    {
QT_MOC_LITERAL(0, 0, 17), // "ChangeAppointment"
QT_MOC_LITERAL(1, 18, 16), // "on_close_clicked"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 26), // "on_AppointmentView_clicked"
QT_MOC_LITERAL(4, 63, 5), // "index"
QT_MOC_LITERAL(5, 69, 17), // "on_update_clicked"
QT_MOC_LITERAL(6, 87, 24), // "on_contactList_activated"
QT_MOC_LITERAL(7, 112, 4), // "arg1"
QT_MOC_LITERAL(8, 117, 23), // "on_timeEdit_timeChanged"
QT_MOC_LITERAL(9, 141, 4), // "time"
QT_MOC_LITERAL(10, 146, 23), // "on_dateEdit_dateChanged"
QT_MOC_LITERAL(11, 170, 4), // "date"
QT_MOC_LITERAL(12, 175, 20) // "on_userBox_activated"

    },
    "ChangeAppointment\0on_close_clicked\0\0"
    "on_AppointmentView_clicked\0index\0"
    "on_update_clicked\0on_contactList_activated\0"
    "arg1\0on_timeEdit_timeChanged\0time\0"
    "on_dateEdit_dateChanged\0date\0"
    "on_userBox_activated"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ChangeAppointment[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    1,   50,    2, 0x08 /* Private */,
       5,    0,   53,    2, 0x08 /* Private */,
       6,    1,   54,    2, 0x08 /* Private */,
       8,    1,   57,    2, 0x08 /* Private */,
      10,    1,   60,    2, 0x08 /* Private */,
      12,    1,   63,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QTime,    9,
    QMetaType::Void, QMetaType::QDate,   11,
    QMetaType::Void, QMetaType::QString,    7,

       0        // eod
};

void ChangeAppointment::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ChangeAppointment *_t = static_cast<ChangeAppointment *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_close_clicked(); break;
        case 1: _t->on_AppointmentView_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 2: _t->on_update_clicked(); break;
        case 3: _t->on_contactList_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_timeEdit_timeChanged((*reinterpret_cast< const QTime(*)>(_a[1]))); break;
        case 5: _t->on_dateEdit_dateChanged((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        case 6: _t->on_userBox_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject ChangeAppointment::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ChangeAppointment.data,
      qt_meta_data_ChangeAppointment,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ChangeAppointment::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChangeAppointment::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ChangeAppointment.stringdata0))
        return static_cast<void*>(const_cast< ChangeAppointment*>(this));
    return QDialog::qt_metacast(_clname);
}

int ChangeAppointment::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
