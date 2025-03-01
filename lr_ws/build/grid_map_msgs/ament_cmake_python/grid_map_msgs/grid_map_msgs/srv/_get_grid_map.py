# generated from rosidl_generator_py/resource/_idl.py.em
# with input from grid_map_msgs:srv/GetGridMap.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_GetGridMap_Request(type):
    """Metaclass of message 'GetGridMap_Request'."""

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
                'grid_map_msgs.srv.GetGridMap_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__get_grid_map__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__get_grid_map__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__get_grid_map__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__get_grid_map__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__get_grid_map__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GetGridMap_Request(metaclass=Metaclass_GetGridMap_Request):
    """Message class 'GetGridMap_Request'."""

    __slots__ = [
        '_frame_id',
        '_position_x',
        '_position_y',
        '_length_x',
        '_length_y',
        '_layers',
    ]

    _fields_and_field_types = {
        'frame_id': 'string',
        'position_x': 'double',
        'position_y': 'double',
        'length_x': 'double',
        'length_y': 'double',
        'layers': 'sequence<string>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.UnboundedString()),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.frame_id = kwargs.get('frame_id', str())
        self.position_x = kwargs.get('position_x', float())
        self.position_y = kwargs.get('position_y', float())
        self.length_x = kwargs.get('length_x', float())
        self.length_y = kwargs.get('length_y', float())
        self.layers = kwargs.get('layers', [])

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
        if self.frame_id != other.frame_id:
            return False
        if self.position_x != other.position_x:
            return False
        if self.position_y != other.position_y:
            return False
        if self.length_x != other.length_x:
            return False
        if self.length_y != other.length_y:
            return False
        if self.layers != other.layers:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def frame_id(self):
        """Message field 'frame_id'."""
        return self._frame_id

    @frame_id.setter
    def frame_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'frame_id' field must be of type 'str'"
        self._frame_id = value

    @builtins.property
    def position_x(self):
        """Message field 'position_x'."""
        return self._position_x

    @position_x.setter
    def position_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'position_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'position_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._position_x = value

    @builtins.property
    def position_y(self):
        """Message field 'position_y'."""
        return self._position_y

    @position_y.setter
    def position_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'position_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'position_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._position_y = value

    @builtins.property
    def length_x(self):
        """Message field 'length_x'."""
        return self._length_x

    @length_x.setter
    def length_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'length_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'length_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._length_x = value

    @builtins.property
    def length_y(self):
        """Message field 'length_y'."""
        return self._length_y

    @length_y.setter
    def length_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'length_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'length_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._length_y = value

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


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_GetGridMap_Response(type):
    """Metaclass of message 'GetGridMap_Response'."""

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
                'grid_map_msgs.srv.GetGridMap_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__get_grid_map__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__get_grid_map__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__get_grid_map__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__get_grid_map__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__get_grid_map__response

            from grid_map_msgs.msg import GridMap
            if GridMap.__class__._TYPE_SUPPORT is None:
                GridMap.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GetGridMap_Response(metaclass=Metaclass_GetGridMap_Response):
    """Message class 'GetGridMap_Response'."""

    __slots__ = [
        '_map',
    ]

    _fields_and_field_types = {
        'map': 'grid_map_msgs/GridMap',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['grid_map_msgs', 'msg'], 'GridMap'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from grid_map_msgs.msg import GridMap
        self.map = kwargs.get('map', GridMap())

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
        if self.map != other.map:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property  # noqa: A003
    def map(self):  # noqa: A003
        """Message field 'map'."""
        return self._map

    @map.setter  # noqa: A003
    def map(self, value):  # noqa: A003
        if __debug__:
            from grid_map_msgs.msg import GridMap
            assert \
                isinstance(value, GridMap), \
                "The 'map' field must be a sub message of type 'GridMap'"
        self._map = value


class Metaclass_GetGridMap(type):
    """Metaclass of service 'GetGridMap'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('grid_map_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'grid_map_msgs.srv.GetGridMap')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__get_grid_map

            from grid_map_msgs.srv import _get_grid_map
            if _get_grid_map.Metaclass_GetGridMap_Request._TYPE_SUPPORT is None:
                _get_grid_map.Metaclass_GetGridMap_Request.__import_type_support__()
            if _get_grid_map.Metaclass_GetGridMap_Response._TYPE_SUPPORT is None:
                _get_grid_map.Metaclass_GetGridMap_Response.__import_type_support__()


class GetGridMap(metaclass=Metaclass_GetGridMap):
    from grid_map_msgs.srv._get_grid_map import GetGridMap_Request as Request
    from grid_map_msgs.srv._get_grid_map import GetGridMap_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
