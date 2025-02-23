// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from cg_msgs:msg/BeaconTag.idl
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
#include "cg_msgs/msg/detail/beacon_tag__struct.h"
#include "cg_msgs/msg/detail/beacon_tag__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool cg_msgs__msg__beacon_tag__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[34];
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
    assert(strncmp("cg_msgs.msg._beacon_tag.BeaconTag", full_classname_dest, 33) == 0);
  }
  cg_msgs__msg__BeaconTag * ros_message = _ros_message;
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
  {  // tag_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "tag_id");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->tag_id, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // pose_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "pose_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->pose_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // pose_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "pose_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->pose_y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // pose_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "pose_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->pose_z = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // orientation_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "orientation_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->orientation_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // orientation_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "orientation_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->orientation_y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // orientation_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "orientation_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->orientation_z = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // orientation_w
    PyObject * field = PyObject_GetAttrString(_pymsg, "orientation_w");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->orientation_w = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * cg_msgs__msg__beacon_tag__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of BeaconTag */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("cg_msgs.msg._beacon_tag");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "BeaconTag");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  cg_msgs__msg__BeaconTag * ros_message = (cg_msgs__msg__BeaconTag *)raw_ros_message;
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
  {  // tag_id
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->tag_id.data,
      strlen(ros_message->tag_id.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "tag_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // pose_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->pose_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pose_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // pose_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->pose_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pose_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // pose_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->pose_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pose_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // orientation_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->orientation_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "orientation_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // orientation_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->orientation_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "orientation_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // orientation_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->orientation_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "orientation_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // orientation_w
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->orientation_w);
    {
      int rc = PyObject_SetAttrString(_pymessage, "orientation_w", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
