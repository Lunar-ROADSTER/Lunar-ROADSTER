# generated from rosidl_generator_py/resource/_idl.py.em
# with input from lx_msgs:msg/BermProgress.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'heights'
# Member 'timestamps'
# Member 'volumes'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_BermProgress(type):
    """Metaclass of message 'BermProgress'."""

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
                'lx_msgs.msg.BermProgress')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__berm_progress
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__berm_progress
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__berm_progress
            cls._TYPE_SUPPORT = module.type_support_msg__msg__berm_progress
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__berm_progress

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


class BermProgress(metaclass=Metaclass_BermProgress):
    """Message class 'BermProgress'."""

    __slots__ = [
        '_berm_points',
        '_heights',
        '_average_height',
        '_length',
        '_peakline_error',
        '_timestamps',
        '_volumes',
    ]

    _fields_and_field_types = {
        'berm_points': 'sequence<geometry_msgs/PointStamped>',
        'heights': 'sequence<float>',
        'average_height': 'float',
        'length': 'float',
        'peakline_error': 'float',
        'timestamps': 'sequence<float>',
        'volumes': 'sequence<float>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'PointStamped')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('float')),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('float')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('float')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.berm_points = kwargs.get('berm_points', [])
        self.heights = array.array('f', kwargs.get('heights', []))
        self.average_height = kwargs.get('average_height', float())
        self.length = kwargs.get('length', float())
        self.peakline_error = kwargs.get('peakline_error', float())
        self.timestamps = array.array('f', kwargs.get('timestamps', []))
        self.volumes = array.array('f', kwargs.get('volumes', []))

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
        if self.berm_points != other.berm_points:
            return False
        if self.heights != other.heights:
            return False
        if self.average_height != other.average_height:
            return False
        if self.length != other.length:
            return False
        if self.peakline_error != other.peakline_error:
            return False
        if self.timestamps != other.timestamps:
            return False
        if self.volumes != other.volumes:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def berm_points(self):
        """Message field 'berm_points'."""
        return self._berm_points

    @berm_points.setter
    def berm_points(self, value):
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
                "The 'berm_points' field must be a set or sequence and each value of type 'PointStamped'"
        self._berm_points = value

    @builtins.property
    def heights(self):
        """Message field 'heights'."""
        return self._heights

    @heights.setter
    def heights(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'f', \
                "The 'heights' array.array() must have the type code of 'f'"
            self._heights = value
            return
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
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -3.402823466e+38 or val > 3.402823466e+38) or math.isinf(val) for val in value)), \
                "The 'heights' field must be a set or sequence and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._heights = array.array('f', value)

    @builtins.property
    def average_height(self):
        """Message field 'average_height'."""
        return self._average_height

    @average_height.setter
    def average_height(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'average_height' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'average_height' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._average_height = value

    @builtins.property
    def length(self):
        """Message field 'length'."""
        return self._length

    @length.setter
    def length(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'length' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'length' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._length = value

    @builtins.property
    def peakline_error(self):
        """Message field 'peakline_error'."""
        return self._peakline_error

    @peakline_error.setter
    def peakline_error(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'peakline_error' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'peakline_error' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._peakline_error = value

    @builtins.property
    def timestamps(self):
        """Message field 'timestamps'."""
        return self._timestamps

    @timestamps.setter
    def timestamps(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'f', \
                "The 'timestamps' array.array() must have the type code of 'f'"
            self._timestamps = value
            return
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
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -3.402823466e+38 or val > 3.402823466e+38) or math.isinf(val) for val in value)), \
                "The 'timestamps' field must be a set or sequence and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._timestamps = array.array('f', value)

    @builtins.property
    def volumes(self):
        """Message field 'volumes'."""
        return self._volumes

    @volumes.setter
    def volumes(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'f', \
                "The 'volumes' array.array() must have the type code of 'f'"
            self._volumes = value
            return
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
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -3.402823466e+38 or val > 3.402823466e+38) or math.isinf(val) for val in value)), \
                "The 'volumes' field must be a set or sequence and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._volumes = array.array('f', value)
