// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from cg_msgs:msg/EncoderTelemetry.idl
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
#include "cg_msgs/msg/detail/encoder_telemetry__struct.h"
#include "cg_msgs/msg/detail/encoder_telemetry__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool cg_msgs__msg__encoder_telemetry__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[48];
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
    assert(strncmp("cg_msgs.msg._encoder_telemetry.EncoderTelemetry", full_classname_dest, 47) == 0);
  }
  cg_msgs__msg__EncoderTelemetry * ros_message = _ros_message;
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
  {  // steer_pos_front
    PyObject * field = PyObject_GetAttrString(_pymsg, "steer_pos_front");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->steer_pos_front = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // steer_pos_rear
    PyObject * field = PyObject_GetAttrString(_pymsg, "steer_pos_rear");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->steer_pos_rear = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // tool_pos
    PyObject * field = PyObject_GetAttrString(_pymsg, "tool_pos");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->tool_pos = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // drive_vel_front
    PyObject * field = PyObject_GetAttrString(_pymsg, "drive_vel_front");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->drive_vel_front = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // drive_vel_rear
    PyObject * field = PyObject_GetAttrString(_pymsg, "drive_vel_rear");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->drive_vel_rear = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // drive_delta_front
    PyObject * field = PyObject_GetAttrString(_pymsg, "drive_delta_front");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->drive_delta_front = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // drive_delta_rear
    PyObject * field = PyObject_GetAttrString(_pymsg, "drive_delta_rear");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->drive_delta_rear = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // term_byte
    PyObject * field = PyObject_GetAttrString(_pymsg, "term_byte");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->term_byte = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * cg_msgs__msg__encoder_telemetry__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of EncoderTelemetry */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("cg_msgs.msg._encoder_telemetry");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "EncoderTelemetry");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  cg_msgs__msg__EncoderTelemetry * ros_message = (cg_msgs__msg__EncoderTelemetry *)raw_ros_message;
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
  {  // steer_pos_front
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->steer_pos_front);
    {
      int rc = PyObject_SetAttrString(_pymessage, "steer_pos_front", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // steer_pos_rear
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->steer_pos_rear);
    {
      int rc = PyObject_SetAttrString(_pymessage, "steer_pos_rear", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // tool_pos
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->tool_pos);
    {
      int rc = PyObject_SetAttrString(_pymessage, "tool_pos", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // drive_vel_front
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->drive_vel_front);
    {
      int rc = PyObject_SetAttrString(_pymessage, "drive_vel_front", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // drive_vel_rear
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->drive_vel_rear);
    {
      int rc = PyObject_SetAttrString(_pymessage, "drive_vel_rear", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // drive_delta_front
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->drive_delta_front);
    {
      int rc = PyObject_SetAttrString(_pymessage, "drive_delta_front", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // drive_delta_rear
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->drive_delta_rear);
    {
      int rc = PyObject_SetAttrString(_pymessage, "drive_delta_rear", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // term_byte
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->term_byte);
    {
      int rc = PyObject_SetAttrString(_pymessage, "term_byte", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
