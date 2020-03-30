/****************************************************************************
** Meta object code from reading C++ file 'blur.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../plugins/blur/blur.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'blur.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BlurEffect_t {
    QByteArrayData data[9];
    char stringdata0[118];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BlurEffect_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BlurEffect_t qt_meta_stringdata_BlurEffect = {
    {
QT_MOC_LITERAL(0, 0, 10), // "BlurEffect"
QT_MOC_LITERAL(1, 11, 15), // "slotWindowAdded"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 19), // "KWin::EffectWindow*"
QT_MOC_LITERAL(4, 48, 1), // "w"
QT_MOC_LITERAL(5, 50, 17), // "slotWindowDeleted"
QT_MOC_LITERAL(6, 68, 18), // "slotPropertyNotify"
QT_MOC_LITERAL(7, 87, 4), // "atom"
QT_MOC_LITERAL(8, 92, 25) // "slotScreenGeometryChanged"

    },
    "BlurEffect\0slotWindowAdded\0\0"
    "KWin::EffectWindow*\0w\0slotWindowDeleted\0"
    "slotPropertyNotify\0atom\0"
    "slotScreenGeometryChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BlurEffect[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x0a /* Public */,
       5,    1,   37,    2, 0x0a /* Public */,
       6,    2,   40,    2, 0x0a /* Public */,
       8,    0,   45,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Long,    4,    7,
    QMetaType::Void,

       0        // eod
};

void BlurEffect::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BlurEffect *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotWindowAdded((*reinterpret_cast< KWin::EffectWindow*(*)>(_a[1]))); break;
        case 1: _t->slotWindowDeleted((*reinterpret_cast< KWin::EffectWindow*(*)>(_a[1]))); break;
        case 2: _t->slotPropertyNotify((*reinterpret_cast< KWin::EffectWindow*(*)>(_a[1])),(*reinterpret_cast< long(*)>(_a[2]))); break;
        case 3: _t->slotScreenGeometryChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< KWin::EffectWindow* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< KWin::EffectWindow* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< KWin::EffectWindow* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject BlurEffect::staticMetaObject = { {
    &KWin::Effect::staticMetaObject,
    qt_meta_stringdata_BlurEffect.data,
    qt_meta_data_BlurEffect,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *BlurEffect::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BlurEffect::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BlurEffect.stringdata0))
        return static_cast<void*>(this);
    return KWin::Effect::qt_metacast(_clname);
}

int BlurEffect::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = KWin::Effect::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
