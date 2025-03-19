// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from lx_msgs:srv/Switch.idl
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
#include "lx_msgs/srv/detail/switch__struct.h"
#include "lx_msgs/srv/detail/switch__functions.h"

bool lx_msgs__msg__berm_section__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * lx_msgs__msg__berm_section__convert_to_py(void * raw_ros_message);
bool lx_msgs__msg__berm_section__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * lx_msgs__msg__berm_section__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool lx_msgs__srv__switch__request__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[35];
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
    assert(strncmp("lx_msgs.srv._switch.Switch_Request", full_classname_dest, 34) == 0);
  }
  lx_msgs__srv__Switch_Request * ros_message = _ros_message;
  {  // switch_state
    PyObject * field = PyObject_GetAttrString(_pymsg, "switch_state");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->switch_state = (Py_True == field);
    Py_DECREF(field);
  }
  {  // current_berm_segment
    PyObject * field = PyObject_GetAttrString(_pymsg, "current_berm_segment");
    if (!field) {
      return false;
    }
    if (!lx_msgs__msg__berm_section__convert_from_py(field, &ros_message->current_berm_segment)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // prev_berm_segment
    PyObject * field = PyObject_GetAttrString(_pymsg, "prev_berm_segment");
    if (!field) {
      return false;
    }
    if (!lx_msgs__msg__berm_section__convert_from_py(field, &ros_message->prev_berm_segment)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // first_seg_dump
    PyObject * field = PyObject_GetAttrString(_pymsg, "first_seg_dump");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->first_seg_dump = (Py_True == field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * lx_msgs__srv__switch__request__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Switch_Request */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("lx_msgs.srv._switch");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Switch_Request");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  lx_msgs__srv__Switch_Request * ros_message = (lx_msgs__srv__Switch_Request *)raw_ros_message;
  {  // switch_state
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->switch_state ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "switch_state", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // current_berm_segment
    PyObject * field = NULL;
    field = lx_msgs__msg__berm_section__convert_to_py(&ros_message->current_berm_segment);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "current_berm_segment", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // prev_berm_segment
    PyObject * field = NULL;
    field = lx_msgs__msg__berm_section__convert_to_py(&ros_message->prev_berm_segment);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "prev_berm_segment", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // first_seg_dump
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->first_seg_dump ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "first_seg_dump", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
// already included above
// #include <Python.h>
// already included above
// #include <stdbool.h>
// already included above
// #include "numpy/ndarrayobject.h"
// already included above
// #include "rosidl_runtime_c/visibility_control.h"
// already included above
// #include "lx_msgs/srv/detail/switch__struct.h"
// already included above
// #include "lx_msgs/srv/detail/switch__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool lx_msgs__srv__switch__response__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[36];
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
    assert(strncmp("lx_msgs.srv._switch.Switch_Response", full_classname_dest, 35) == 0);
  }
  lx_msgs__srv__Switch_Response * ros_message = _ros_message;
  {  // success
    PyObject * field = PyObject_GetAttrString(_pymsg, "success");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->success = (Py_True == field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * lx_msgs__srv__switch__response__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Switch_Response */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("lx_msgs.srv._switch");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Switch_Response");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  lx_msgs__srv__Switch_Response * ros_message = (lx_msgs__srv__Switch_Response *)raw_ros_message;
  {  // success
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->success ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "success", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
