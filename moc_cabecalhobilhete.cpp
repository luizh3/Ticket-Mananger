/****************************************************************************
** Meta object code from reading C++ file 'cabecalhobilhete.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "cabecalhobilhete.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cabecalhobilhete.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CabecalhoBilhete_t {
    QByteArrayData data[6];
    char stringdata0[63];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CabecalhoBilhete_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CabecalhoBilhete_t qt_meta_stringdata_CabecalhoBilhete = {
    {
QT_MOC_LITERAL(0, 0, 16), // "CabecalhoBilhete"
QT_MOC_LITERAL(1, 17, 16), // "cabesalhoBilhete"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 11), // "tipoBilhete"
QT_MOC_LITERAL(4, 47, 8), // "emitopor"
QT_MOC_LITERAL(5, 56, 6) // "motivo"

    },
    "CabecalhoBilhete\0cabesalhoBilhete\0\0"
    "tipoBilhete\0emitopor\0motivo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CabecalhoBilhete[] = {

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
       1,    3,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,

       0        // eod
};

void CabecalhoBilhete::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CabecalhoBilhete *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QString _r = _t->cabesalhoBilhete((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CabecalhoBilhete::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_CabecalhoBilhete.data,
    qt_meta_data_CabecalhoBilhete,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CabecalhoBilhete::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CabecalhoBilhete::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CabecalhoBilhete.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CabecalhoBilhete::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
