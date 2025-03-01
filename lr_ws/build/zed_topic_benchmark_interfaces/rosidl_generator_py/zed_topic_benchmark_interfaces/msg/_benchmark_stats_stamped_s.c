// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from zed_topic_benchmark_interfaces:msg/BenchmarkStatsStamped.idl
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
#include "zed_topic_benchmark_interfaces/msg/detail/benchmark_stats_stamped__struct.h"
#include "zed_topic_benchmark_interfaces/msg/detail/benchmark_stats_stamped__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool zed_topic_benchmark_interfaces__msg__benchmark_stats_stamped__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[82];
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
    assert(strncmp("zed_topic_benchmark_interfaces.msg._benchmark_stats_stamped.BenchmarkStatsStamped", full_classname_dest, 81) == 0);
  }
  zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped * ros_message = _ros_message;
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
  {  // topic_freq
    PyObject * field = PyObject_GetAttrString(_pymsg, "topic_freq");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->topic_freq = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // topic_avg_freq
    PyObject * field = PyObject_GetAttrString(_pymsg, "topic_avg_freq");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->topic_avg_freq = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // topic_bw
    PyObject * field = PyObject_GetAttrString(_pymsg, "topic_bw");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->topic_bw = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // topic_avg_bw
    PyObject * field = PyObject_GetAttrString(_pymsg, "topic_avg_bw");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->topic_avg_bw = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * zed_topic_benchmark_interfaces__msg__benchmark_stats_stamped__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of BenchmarkStatsStamped */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("zed_topic_benchmark_interfaces.msg._benchmark_stats_stamped");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "BenchmarkStatsStamped");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped * ros_message = (zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped *)raw_ros_message;
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
  {  // topic_freq
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->topic_freq);
    {
      int rc = PyObject_SetAttrString(_pymessage, "topic_freq", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // topic_avg_freq
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->topic_avg_freq);
    {
      int rc = PyObject_SetAttrString(_pymessage, "topic_avg_freq", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // topic_bw
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->topic_bw);
    {
      int rc = PyObject_SetAttrString(_pymessage, "topic_bw", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // topic_avg_bw
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->topic_avg_bw);
    {
      int rc = PyObject_SetAttrString(_pymessage, "topic_avg_bw", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
