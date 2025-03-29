// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from cg_msgs:msg/Slip.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "cg_msgs/msg/detail/slip__struct.h"
#include "cg_msgs/msg/detail/slip__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool cg_msgs__msg__slip__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[23];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("cg_msgs.msg._slip.Slip", full_classname_dest, 22) == 0);
  }
  cg_msgs__msg__Slip * ros_message = _ros_message;
  {  // header
    PyObject * field = PyObject_GetAttrString(_pymsg, "header");
    if (!field) {
      return false;
    }
    if (!std_msgs__msg__header__convert_from_py(field, &ros_message->header)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // slip
    PyObject * field = PyObject_GetAttrString(_pymsg, "slip");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->slip = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // slip_avg
    PyObject * field = PyObject_GetAttrString(_pymsg, "slip_avg");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->slip_avg = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // slip_latch
    PyObject * field = PyObject_GetAttrString(_pymsg, "slip_latch");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->slip_latch = (Py_True == field);
    Py_DECREF(field);
  }
  {  // vel
    PyObject * field = PyObject_GetAttrString(_pymsg, "vel");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->vel = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // vel_avg
    PyObject * field = PyObject_GetAttrString(_pymsg, "vel_avg");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->vel_avg = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * cg_msgs__msg__slip__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Slip */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("cg_msgs.msg._slip");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Slip");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  cg_msgs__msg__Slip * ros_message = (cg_msgs__msg__Slip *)raw_ros_message;
  {  // header
    PyObject * field = NULL;
    field = std_msgs__msg__header__convert_to_py(&ros_message->header);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "header", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // slip
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->slip);
    {
      int rc = PyObject_SetAttrString(_pymessage, "slip", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // slip_avg
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->slip_avg);
    {
      int rc = PyObject_SetAttrString(_pymessage, "slip_avg", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // slip_latch
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->slip_latch ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "slip_latch", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // vel
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->vel);
    {
      int rc = PyObject_SetAttrString(_pymessage, "vel", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // vel_avg
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->vel_avg);
    {
      int rc = PyObject_SetAttrString(_pymessage, "vel_avg", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
