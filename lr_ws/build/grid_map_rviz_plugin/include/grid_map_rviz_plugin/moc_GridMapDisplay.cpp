/****************************************************************************
** Meta object code from reading C++ file 'GridMapDisplay.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../src/drivers/grid_map/grid_map_rviz_plugin/include/grid_map_rviz_plugin/GridMapDisplay.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GridMapDisplay.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_grid_map_rviz_plugin__GridMapDisplay_t {
    QByteArrayData data[8];
    char stringdata0[161];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_grid_map_rviz_plugin__GridMapDisplay_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_grid_map_rviz_plugin__GridMapDisplay_t qt_meta_stringdata_grid_map_rviz_plugin__GridMapDisplay = {
    {
QT_MOC_LITERAL(0, 0, 36), // "grid_map_rviz_plugin::GridMap..."
QT_MOC_LITERAL(1, 37, 19), // "updateHistoryLength"
QT_MOC_LITERAL(2, 57, 0), // ""
QT_MOC_LITERAL(3, 58, 16), // "updateHeightMode"
QT_MOC_LITERAL(4, 75, 15), // "updateColorMode"
QT_MOC_LITERAL(5, 91, 16), // "updateUseRainbow"
QT_MOC_LITERAL(6, 108, 32), // "updateAutocomputeIntensityBounds"
QT_MOC_LITERAL(7, 141, 19) // "updateVisualization"

    },
    "grid_map_rviz_plugin::GridMapDisplay\0"
    "updateHistoryLength\0\0updateHeightMode\0"
    "updateColorMode\0updateUseRainbow\0"
    "updateAutocomputeIntensityBounds\0"
    "updateVisualization"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_grid_map_rviz_plugin__GridMapDisplay[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void grid_map_rviz_plugin::GridMapDisplay::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GridMapDisplay *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->updateHistoryLength(); break;
        case 1: _t->updateHeightMode(); break;
        case 2: _t->updateColorMode(); break;
        case 3: _t->updateUseRainbow(); break;
        case 4: _t->updateAutocomputeIntensityBounds(); break;
        case 5: _t->updateVisualization(); break;
        default: ;
        }
    }
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject grid_map_rviz_plugin::GridMapDisplay::staticMetaObject = { {
    QMetaObject::SuperData::link<rviz_common::MessageFilterDisplay<grid_map_msgs::msg::GridMap>::staticMetaObject>(),
    qt_meta_stringdata_grid_map_rviz_plugin__GridMapDisplay.data,
    qt_meta_data_grid_map_rviz_plugin__GridMapDisplay,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *grid_map_rviz_plugin::GridMapDisplay::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *grid_map_rviz_plugin::GridMapDisplay::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_grid_map_rviz_plugin__GridMapDisplay.stringdata0))
        return static_cast<void*>(this);
    return rviz_common::MessageFilterDisplay<grid_map_msgs::msg::GridMap>::qt_metacast(_clname);
}

int grid_map_rviz_plugin::GridMapDisplay::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = rviz_common::MessageFilterDisplay<grid_map_msgs::msg::GridMap>::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
