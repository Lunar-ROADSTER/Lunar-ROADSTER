// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from lx_msgs:srv/PclGroundHeight.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "lx_msgs/srv/detail/pcl_ground_height__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace lx_msgs
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _PclGroundHeight_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PclGroundHeight_Request_type_support_ids_t;

static const _PclGroundHeight_Request_type_support_ids_t _PclGroundHeight_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _PclGroundHeight_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PclGroundHeight_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PclGroundHeight_Request_type_support_symbol_names_t _PclGroundHeight_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, lx_msgs, srv, PclGroundHeight_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, lx_msgs, srv, PclGroundHeight_Request)),
  }
};

typedef struct _PclGroundHeight_Request_type_support_data_t
{
  void * data[2];
} _PclGroundHeight_Request_type_support_data_t;

static _PclGroundHeight_Request_type_support_data_t _PclGroundHeight_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PclGroundHeight_Request_message_typesupport_map = {
  2,
  "lx_msgs",
  &_PclGroundHeight_Request_message_typesupport_ids.typesupport_identifier[0],
  &_PclGroundHeight_Request_message_typesupport_symbol_names.symbol_name[0],
  &_PclGroundHeight_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PclGroundHeight_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PclGroundHeight_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace lx_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<lx_msgs::srv::PclGroundHeight_Request>()
{
  return &::lx_msgs::srv::rosidl_typesupport_cpp::PclGroundHeight_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, lx_msgs, srv, PclGroundHeight_Request)() {
  return get_message_type_support_handle<lx_msgs::srv::PclGroundHeight_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "lx_msgs/srv/detail/pcl_ground_height__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace lx_msgs
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _PclGroundHeight_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PclGroundHeight_Response_type_support_ids_t;

static const _PclGroundHeight_Response_type_support_ids_t _PclGroundHeight_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _PclGroundHeight_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PclGroundHeight_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PclGroundHeight_Response_type_support_symbol_names_t _PclGroundHeight_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, lx_msgs, srv, PclGroundHeight_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, lx_msgs, srv, PclGroundHeight_Response)),
  }
};

typedef struct _PclGroundHeight_Response_type_support_data_t
{
  void * data[2];
} _PclGroundHeight_Response_type_support_data_t;

static _PclGroundHeight_Response_type_support_data_t _PclGroundHeight_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PclGroundHeight_Response_message_typesupport_map = {
  2,
  "lx_msgs",
  &_PclGroundHeight_Response_message_typesupport_ids.typesupport_identifier[0],
  &_PclGroundHeight_Response_message_typesupport_symbol_names.symbol_name[0],
  &_PclGroundHeight_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PclGroundHeight_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PclGroundHeight_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace lx_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<lx_msgs::srv::PclGroundHeight_Response>()
{
  return &::lx_msgs::srv::rosidl_typesupport_cpp::PclGroundHeight_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, lx_msgs, srv, PclGroundHeight_Response)() {
  return get_message_type_support_handle<lx_msgs::srv::PclGroundHeight_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "lx_msgs/srv/detail/pcl_ground_height__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace lx_msgs
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _PclGroundHeight_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PclGroundHeight_type_support_ids_t;

static const _PclGroundHeight_type_support_ids_t _PclGroundHeight_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _PclGroundHeight_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PclGroundHeight_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PclGroundHeight_type_support_symbol_names_t _PclGroundHeight_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, lx_msgs, srv, PclGroundHeight)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, lx_msgs, srv, PclGroundHeight)),
  }
};

typedef struct _PclGroundHeight_type_support_data_t
{
  void * data[2];
} _PclGroundHeight_type_support_data_t;

static _PclGroundHeight_type_support_data_t _PclGroundHeight_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PclGroundHeight_service_typesupport_map = {
  2,
  "lx_msgs",
  &_PclGroundHeight_service_typesupport_ids.typesupport_identifier[0],
  &_PclGroundHeight_service_typesupport_symbol_names.symbol_name[0],
  &_PclGroundHeight_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t PclGroundHeight_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PclGroundHeight_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace lx_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<lx_msgs::srv::PclGroundHeight>()
{
  return &::lx_msgs::srv::rosidl_typesupport_cpp::PclGroundHeight_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, lx_msgs, srv, PclGroundHeight)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<lx_msgs::srv::PclGroundHeight>();
}

#ifdef __cplusplus
}
#endif
