# generated from rosidl_generator_py/resource/_idl.py.em
# with input from grid_map_msgs:msg/GridMap.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_GridMap(type):
    """Metaclass of message 'GridMap'."""

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
            module = import_type_support('grid_map_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'grid_map_msgs.msg.GridMap')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__grid_map
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__grid_map
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__grid_map
            cls._TYPE_SUPPORT = module.type_support_msg__msg__grid_map
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__grid_map

            from grid_map_msgs.msg import GridMapInfo
            if GridMapInfo.__class__._TYPE_SUPPORT is None:
                GridMapInfo.__class__.__import_type_support__()

            from std_msgs.msg import Float32MultiArray
            if Float32MultiArray.__class__._TYPE_SUPPORT is None:
                Float32MultiArray.__class__.__import_type_support__()

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GridMap(metaclass=Metaclass_GridMap):
    """Message class 'GridMap'."""

    __slots__ = [
        '_header',
        '_info',
        '_layers',
        '_basic_layers',
        '_data',
        '_outer_start_index',
        '_inner_start_index',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'info': 'grid_map_msgs/GridMapInfo',
        'layers': 'sequence<string>',
        'basic_layers': 'sequence<string>',
        'data': 'sequence<std_msgs/Float32MultiArray>',
        'outer_start_index': 'uint16',
        'inner_start_index': 'uint16',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['grid_map_msgs', 'msg'], 'GridMapInfo'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.UnboundedString()),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.UnboundedString()),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Float32MultiArray')),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        from grid_map_msgs.msg import GridMapInfo
        self.info = kwargs.get('info', GridMapInfo())
        self.layers = kwargs.get('layers', [])
        self.basic_layers = kwargs.get('basic_layers', [])
        self.data = kwargs.get('data', [])
        self.outer_start_index = kwargs.get('outer_start_index', int())
        self.inner_start_index = kwargs.get('inner_start_index', int())

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
        if self.header != other.header:
            return False
        if self.info != other.info:
            return False
        if self.layers != other.layers:
            return False
        if self.basic_layers != other.basic_layers:
            return False
        if self.data != other.data:
            return False
        if self.outer_start_index != other.outer_start_index:
            return False
        if self.inner_start_index != other.inner_start_index:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def header(self):
        """Message field 'header'."""
        return self._header

    @header.setter
    def header(self, value):
        if __debug__:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @builtins.property
    def info(self):
        """Message field 'info'."""
        return self._info

    @info.setter
    def info(self, value):
        if __debug__:
            from grid_map_msgs.msg import GridMapInfo
            assert \
                isinstance(value, GridMapInfo), \
                "The 'info' field must be a sub message of type 'GridMapInfo'"
        self._info = value

    @builtins.property
    def layers(self):
        """Message field 'layers'."""
        return self._layers

    @layers.setter
    def layers(self, value):
        if __debug__:
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
                 all(isinstance(v, str) for v in value) and
                 True), \
                "The 'layers' field must be a set or sequence and each value of type 'str'"
        self._layers = value

    @builtins.property
    def basic_layers(self):
        """Message field 'basic_layers'."""
        return self._basic_layers

    @basic_layers.setter
    def basic_layers(self, value):
        if __debug__:
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
                 all(isinstance(v, str) for v in value) and
                 True), \
                "The 'basic_layers' field must be a set or sequence and each value of type 'str'"
        self._basic_layers = value

    @builtins.property
    def data(self):
        """Message field 'data'."""
        return self._data

    @data.setter
    def data(self, value):
        if __debug__:
            from std_msgs.msg import Float32MultiArray
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
                 all(isinstance(v, Float32MultiArray) for v in value) and
                 True), \
                "The 'data' field must be a set or sequence and each value of type 'Float32MultiArray'"
        self._data = value

    @builtins.property
    def outer_start_index(self):
        """Message field 'outer_start_index'."""
        return self._outer_start_index

    @outer_start_index.setter
    def outer_start_index(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'outer_start_index' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'outer_start_index' field must be an unsigned integer in [0, 65535]"
        self._outer_start_index = value

    @builtins.property
    def inner_start_index(self):
        """Message field 'inner_start_index'."""
        return self._inner_start_index

    @inner_start_index.setter
    def inner_start_index(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'inner_start_index' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'inner_start_index' field must be an unsigned integer in [0, 65535]"
        self._inner_start_index = value
