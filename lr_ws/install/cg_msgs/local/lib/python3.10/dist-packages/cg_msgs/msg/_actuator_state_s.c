// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from cg_msgs:msg/ActuatorState.idl
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
#include "cg_msgs/msg/detail/actuator_state__struct.h"
#include "cg_msgs/msg/detail/actuator_state__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool cg_msgs__msg__actuator_state__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[42];
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
    assert(strncmp("cg_msgs.msg._actuator_state.ActuatorState", full_classname_dest, 41) == 0);
  }
  cg_msgs__msg__ActuatorState * ros_message = _ros_message;
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
  {  // wheel_velocity
    PyObject * field = PyObject_GetAttrString(_pymsg, "wheel_velocity");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->wheel_velocity = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // steer_position
    PyObject * field = PyObject_GetAttrString(_pymsg, "steer_position");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->steer_position = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // tool_position
    PyObject * field = PyObject_GetAttrString(_pymsg, "tool_position");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->tool_position = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * cg_msgs__msg__actuator_state__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of ActuatorState */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("cg_msgs.msg._actuator_state");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "ActuatorState");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  cg_msgs__msg__ActuatorState * ros_message = (cg_msgs__msg__ActuatorState *)raw_ros_message;
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
  {  // wheel_velocity
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->wheel_velocity);
    {
      int rc = PyObject_SetAttrString(_pymessage, "wheel_velocity", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // steer_position
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->steer_position);
    {
      int rc = PyObject_SetAttrString(_pymessage, "steer_position", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // tool_position
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->tool_position);
    {
      int rc = PyObject_SetAttrString(_pymessage, "tool_position", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
