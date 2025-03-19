// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from lx_msgs:msg/ToolInfo.idl
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
#include "lx_msgs/msg/detail/tool_info__struct.h"
#include "lx_msgs/msg/detail/tool_info__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool lx_msgs__msg__tool_info__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[32];
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
    assert(strncmp("lx_msgs.msg._tool_info.ToolInfo", full_classname_dest, 31) == 0);
  }
  lx_msgs__msg__ToolInfo * ros_message = _ros_message;
  {  // drum_pos
    PyObject * field = PyObject_GetAttrString(_pymsg, "drum_pos");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->drum_pos = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // drum_current
    PyObject * field = PyObject_GetAttrString(_pymsg, "drum_current");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->drum_current = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * lx_msgs__msg__tool_info__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of ToolInfo */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("lx_msgs.msg._tool_info");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "ToolInfo");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  lx_msgs__msg__ToolInfo * ros_message = (lx_msgs__msg__ToolInfo *)raw_ros_message;
  {  // drum_pos
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->drum_pos);
    {
      int rc = PyObject_SetAttrString(_pymessage, "drum_pos", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // drum_current
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->drum_current);
    {
      int rc = PyObject_SetAttrString(_pymessage, "drum_current", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
