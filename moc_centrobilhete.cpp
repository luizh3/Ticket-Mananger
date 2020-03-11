/****************************************************************************
** Meta object code from reading C++ file 'centrobilhete.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "centrobilhete.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'centrobilhete.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CentroBilhete_t {
    QByteArrayData data[9];
    char stringdata0[82];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CentroBilhete_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CentroBilhete_t qt_meta_stringdata_CentroBilhete = {
    {
QT_MOC_LITERAL(0, 0, 13), // "CentroBilhete"
QT_MOC_LITERAL(1, 14, 21), // "centroBilheteFormatar"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 11), // "description"
QT_MOC_LITERAL(4, 49, 4), // "nome"
QT_MOC_LITERAL(5, 54, 10), // "assinatura"
QT_MOC_LITERAL(6, 65, 4), // "data"
QT_MOC_LITERAL(7, 70, 5), // "turma"
QT_MOC_LITERAL(8, 76, 5) // "turno"

    },
    "CentroBilhete\0centroBilheteFormatar\0"
    "\0description\0nome\0assinatura\0data\0"
    "turma\0turno"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CentroBilhete[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    6,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,    6,    7,    8,

       0        // eod
};

void CentroBilhete::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CentroBilhete *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QString _r = _t->centroBilheteFormatar((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])),(*reinterpret_cast< const QString(*)>(_a[6])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CentroBilhete::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_CentroBilhete.data,
    qt_meta_data_CentroBilhete,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CentroBilhete::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CentroBilhete::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CentroBilhete.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CentroBilhete::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
