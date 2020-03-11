/****************************************************************************
** Meta object code from reading C++ file 'telaconfiggeral.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "telaconfiggeral/telaconfiggeral.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'telaconfiggeral.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TelaConfigGeral_t {
    QByteArrayData data[14];
    char stringdata0[233];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TelaConfigGeral_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TelaConfigGeral_t qt_meta_stringdata_TelaConfigGeral = {
    {
QT_MOC_LITERAL(0, 0, 15), // "TelaConfigGeral"
QT_MOC_LITERAL(1, 16, 15), // "comboBoxChanged"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 34), // "selectAnimationFailOrSucessCh..."
QT_MOC_LITERAL(4, 68, 15), // "insertNomeTurma"
QT_MOC_LITERAL(5, 84, 9), // "nomeTurma"
QT_MOC_LITERAL(6, 94, 16), // "salvarNomeEscola"
QT_MOC_LITERAL(7, 111, 10), // "nomeEscola"
QT_MOC_LITERAL(8, 122, 15), // "maximoCaraLinha"
QT_MOC_LITERAL(9, 138, 17), // "retornoNomeEscola"
QT_MOC_LITERAL(10, 156, 26), // "retornoMaximoCaracterLinha"
QT_MOC_LITERAL(11, 183, 12), // "deletarTurma"
QT_MOC_LITERAL(12, 196, 8), // "comboBox"
QT_MOC_LITERAL(13, 205, 27) // "selectAnimationFailOrSucess"

    },
    "TelaConfigGeral\0comboBoxChanged\0\0"
    "selectAnimationFailOrSucessChanged\0"
    "insertNomeTurma\0nomeTurma\0salvarNomeEscola\0"
    "nomeEscola\0maximoCaraLinha\0retornoNomeEscola\0"
    "retornoMaximoCaracterLinha\0deletarTurma\0"
    "comboBox\0selectAnimationFailOrSucess"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TelaConfigGeral[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       2,   64, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   51,    2, 0x0a /* Public */,
       6,    2,   54,    2, 0x0a /* Public */,
       9,    0,   59,    2, 0x0a /* Public */,
      10,    0,   60,    2, 0x0a /* Public */,
      11,    1,   61,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    7,    8,
    QMetaType::QString,
    QMetaType::Int,
    QMetaType::Void, QMetaType::QString,    5,

 // properties: name, type, flags
      12, QMetaType::QStringList, 0x00495001,
      13, QMetaType::Bool, 0x00495103,

 // properties: notify_signal_id
       0,
       1,

       0        // eod
};

void TelaConfigGeral::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TelaConfigGeral *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->comboBoxChanged(); break;
        case 1: _t->selectAnimationFailOrSucessChanged(); break;
        case 2: _t->insertNomeTurma((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->salvarNomeEscola((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: { QString _r = _t->retornoNomeEscola();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 5: { int _r = _t->retornoMaximoCaracterLinha();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->deletarTurma((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TelaConfigGeral::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TelaConfigGeral::comboBoxChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TelaConfigGeral::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TelaConfigGeral::selectAnimationFailOrSucessChanged)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<TelaConfigGeral *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QStringList*>(_v) = _t->comboBoxPrintar(); break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->selectAnimationFailOrSucess(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<TelaConfigGeral *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 1: _t->setSelectAnimationFailOrSucess(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject TelaConfigGeral::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_TelaConfigGeral.data,
    qt_meta_data_TelaConfigGeral,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TelaConfigGeral::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TelaConfigGeral::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TelaConfigGeral.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TelaConfigGeral::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void TelaConfigGeral::comboBoxChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void TelaConfigGeral::selectAnimationFailOrSucessChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
