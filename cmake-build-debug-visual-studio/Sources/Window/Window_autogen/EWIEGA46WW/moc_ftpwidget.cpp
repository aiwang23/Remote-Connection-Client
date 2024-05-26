/****************************************************************************
** Meta object code from reading C++ file 'ftpwidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../Sources/Window/ftpwidget.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ftpwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_Window__FtpWidget_t {
    uint offsetsAndSizes[34];
    char stringdata0[18];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[18];
    char stringdata4[5];
    char stringdata5[18];
    char stringdata6[12];
    char stringdata7[10];
    char stringdata8[20];
    char stringdata9[4];
    char stringdata10[7];
    char stringdata11[10];
    char stringdata12[10];
    char stringdata13[10];
    char stringdata14[13];
    char stringdata15[15];
    char stringdata16[4];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_Window__FtpWidget_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_Window__FtpWidget_t qt_meta_stringdata_Window__FtpWidget = {
    {
        QT_MOC_LITERAL(0, 17),  // "Window::FtpWidget"
        QT_MOC_LITERAL(18, 13),  // "LoginOKSignal"
        QT_MOC_LITERAL(32, 0),  // ""
        QT_MOC_LITERAL(33, 17),  // "Core::FtpUserData"
        QT_MOC_LITERAL(51, 4),  // "data"
        QT_MOC_LITERAL(56, 17),  // "LoginFailedSignal"
        QT_MOC_LITERAL(74, 11),  // "CloseSignal"
        QT_MOC_LITERAL(86, 9),  // "OnLoginOK"
        QT_MOC_LITERAL(96, 19),  // "OnCellDoubleClicked"
        QT_MOC_LITERAL(116, 3),  // "row"
        QT_MOC_LITERAL(120, 6),  // "OnCdup"
        QT_MOC_LITERAL(127, 9),  // "OnRefresh"
        QT_MOC_LITERAL(137, 9),  // "PutAction"
        QT_MOC_LITERAL(147, 9),  // "GetAction"
        QT_MOC_LITERAL(157, 12),  // "DeleteAction"
        QT_MOC_LITERAL(170, 14),  // "OnDetailedInfo"
        QT_MOC_LITERAL(185, 3)   // "idx"
    },
    "Window::FtpWidget",
    "LoginOKSignal",
    "",
    "Core::FtpUserData",
    "data",
    "LoginFailedSignal",
    "CloseSignal",
    "OnLoginOK",
    "OnCellDoubleClicked",
    "row",
    "OnCdup",
    "OnRefresh",
    "PutAction",
    "GetAction",
    "DeleteAction",
    "OnDetailedInfo",
    "idx"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_Window__FtpWidget[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   80,    2, 0x06,    1 /* Public */,
       5,    0,   83,    2, 0x06,    3 /* Public */,
       6,    0,   84,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    0,   85,    2, 0x0a,    5 /* Public */,
       8,    1,   86,    2, 0x0a,    6 /* Public */,
      10,    0,   89,    2, 0x0a,    8 /* Public */,
      11,    0,   90,    2, 0x10a,    9 /* Public | MethodIsConst  */,
      12,    0,   91,    2, 0x0a,   10 /* Public */,
      13,    0,   92,    2, 0x0a,   11 /* Public */,
      14,    0,   93,    2, 0x0a,   12 /* Public */,
      15,    2,   94,    2, 0x10a,   13 /* Public | MethodIsConst  */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    9,   16,

       0        // eod
};

Q_CONSTINIT const QMetaObject Window::FtpWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Window__FtpWidget.offsetsAndSizes,
    qt_meta_data_Window__FtpWidget,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_Window__FtpWidget_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<FtpWidget, std::true_type>,
        // method 'LoginOKSignal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Core::FtpUserData, std::false_type>,
        // method 'LoginFailedSignal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'CloseSignal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'OnLoginOK'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'OnCellDoubleClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'OnCdup'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'OnRefresh'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'PutAction'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'GetAction'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'DeleteAction'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'OnDetailedInfo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void Window::FtpWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FtpWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->LoginOKSignal((*reinterpret_cast< std::add_pointer_t<Core::FtpUserData>>(_a[1]))); break;
        case 1: _t->LoginFailedSignal(); break;
        case 2: _t->CloseSignal(); break;
        case 3: _t->OnLoginOK(); break;
        case 4: _t->OnCellDoubleClicked((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->OnCdup(); break;
        case 6: _t->OnRefresh(); break;
        case 7: _t->PutAction(); break;
        case 8: _t->GetAction(); break;
        case 9: _t->DeleteAction(); break;
        case 10: _t->OnDetailedInfo((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FtpWidget::*)(Core::FtpUserData );
            if (_t _q_method = &FtpWidget::LoginOKSignal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FtpWidget::*)();
            if (_t _q_method = &FtpWidget::LoginFailedSignal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (FtpWidget::*)();
            if (_t _q_method = &FtpWidget::CloseSignal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *Window::FtpWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Window::FtpWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Window__FtpWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Window::FtpWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void Window::FtpWidget::LoginOKSignal(Core::FtpUserData _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Window::FtpWidget::LoginFailedSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Window::FtpWidget::CloseSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
