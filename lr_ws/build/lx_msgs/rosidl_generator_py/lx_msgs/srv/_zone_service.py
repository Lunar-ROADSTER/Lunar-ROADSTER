# generated from rosidl_generator_py/resource/_idl.py.em
# with input from lx_msgs:srv/ZoneService.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ZoneService_Request(type):
    """Metaclass of message 'ZoneService_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('lx_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'lx_msgs.srv.ZoneService_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__zone_service__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__zone_service__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__zone_service__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__zone_service__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__zone_service__request

            from geometry_msgs.msg import PointStamped
            if PointStamped.__class__._TYPE_SUPPORT is None:
                PointStamped.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ZoneService_Request(metaclass=Metaclass_ZoneService_Request):
    """Message class 'ZoneService_Request'."""

    __slots__ = [
        '_zone_type',
        '_zone_coordinates',
    ]

    _fields_and_field_types = {
        'zone_type': 'string',
        'zone_coordinates': 'sequence<geometry_msgs/PointStamped>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'PointStamped')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.zone_type = kwargs.get('zone_type', str())
        self.zone_coordinates = kwargs.get('zone_coordinates', [])

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.zone_type != other.zone_type:
            return False
        if self.zone_coordinates != other.zone_coordinates:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def zone_type(self):
        """Message field 'zone_type'."""
        return self._zone_type

    @zone_type.setter
    def zone_type(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'zone_type' field must be of type 'str'"
        self._zone_type = value

    @builtins.property
    def zone_coordinates(self):
        """Message field 'zone_coordinates'."""
        return self._zone_coordinates

    @zone_coordinates.setter
    def zone_coordinates(self, value):
        if __debug__:
            from geometry_msgs.msg import PointStamped
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, PointStamped) for v in value) and
                 True), \
                "The 'zone_coordinates' field must be a set or sequence and each value of type 'PointStamped'"
        self._zone_coordinates = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_ZoneService_Response(type):
    """Metaclass of message 'ZoneService_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('lx_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'lx_msgs.srv.ZoneService_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__zone_service__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__zone_service__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__zone_service__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__zone_service__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__zone_service__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ZoneService_Response(metaclass=Metaclass_ZoneService_Response):
    """Message class 'ZoneService_Response'."""

    __slots__ = [
        '_success',
    ]

    _fields_and_field_types = {
        'success': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.success = kwargs.get('success', bool())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.success != other.success:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def success(self):
        """Message field 'success'."""
        return self._success

    @success.setter
    def success(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'success' field must be of type 'bool'"
        self._success = value


class Metaclass_ZoneService(type):
    """Metaclass of service 'ZoneService'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('lx_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'lx_msgs.srv.ZoneService')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__zone_service

            from lx_msgs.srv import _zone_service
            if _zone_service.Metaclass_ZoneService_Request._TYPE_SUPPORT is None:
                _zone_service.Metaclass_ZoneService_Request.__import_type_support__()
            if _zone_service.Metaclass_ZoneService_Response._TYPE_SUPPORT is None:
                _zone_service.Metaclass_ZoneService_Response.__import_type_support__()


class ZoneService(metaclass=Metaclass_ZoneService):
    from lx_msgs.srv._zone_service import ZoneService_Request as Request
    from lx_msgs.srv._zone_service import ZoneService_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
