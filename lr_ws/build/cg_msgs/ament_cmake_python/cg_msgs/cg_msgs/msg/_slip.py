# generated from rosidl_generator_py/resource/_idl.py.em
# with input from cg_msgs:msg/Slip.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Slip(type):
    """Metaclass of message 'Slip'."""

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
            module = import_type_support('cg_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'cg_msgs.msg.Slip')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__slip
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__slip
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__slip
            cls._TYPE_SUPPORT = module.type_support_msg__msg__slip
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__slip

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'SLIP__DEFAULT': 0.0,
            'SLIP_AVG__DEFAULT': 0.0,
            'SLIP_LATCH__DEFAULT': True,
            'VEL__DEFAULT': 0.0,
            'VEL_AVG__DEFAULT': 0.0,
        }

    @property
    def SLIP__DEFAULT(cls):
        """Return default value for message field 'slip'."""
        return 0.0

    @property
    def SLIP_AVG__DEFAULT(cls):
        """Return default value for message field 'slip_avg'."""
        return 0.0

    @property
    def SLIP_LATCH__DEFAULT(cls):
        """Return default value for message field 'slip_latch'."""
        return True

    @property
    def VEL__DEFAULT(cls):
        """Return default value for message field 'vel'."""
        return 0.0

    @property
    def VEL_AVG__DEFAULT(cls):
        """Return default value for message field 'vel_avg'."""
        return 0.0


class Slip(metaclass=Metaclass_Slip):
    """Message class 'Slip'."""

    __slots__ = [
        '_header',
        '_slip',
        '_slip_avg',
        '_slip_latch',
        '_vel',
        '_vel_avg',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'slip': 'float',
        'slip_avg': 'float',
        'slip_latch': 'boolean',
        'vel': 'float',
        'vel_avg': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.slip = kwargs.get(
            'slip', Slip.SLIP__DEFAULT)
        self.slip_avg = kwargs.get(
            'slip_avg', Slip.SLIP_AVG__DEFAULT)
        self.slip_latch = kwargs.get(
            'slip_latch', Slip.SLIP_LATCH__DEFAULT)
        self.vel = kwargs.get(
            'vel', Slip.VEL__DEFAULT)
        self.vel_avg = kwargs.get(
            'vel_avg', Slip.VEL_AVG__DEFAULT)

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
        if self.slip != other.slip:
            return False
        if self.slip_avg != other.slip_avg:
            return False
        if self.slip_latch != other.slip_latch:
            return False
        if self.vel != other.vel:
            return False
        if self.vel_avg != other.vel_avg:
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
    def slip(self):
        """Message field 'slip'."""
        return self._slip

    @slip.setter
    def slip(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'slip' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'slip' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._slip = value

    @builtins.property
    def slip_avg(self):
        """Message field 'slip_avg'."""
        return self._slip_avg

    @slip_avg.setter
    def slip_avg(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'slip_avg' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'slip_avg' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._slip_avg = value

    @builtins.property
    def slip_latch(self):
        """Message field 'slip_latch'."""
        return self._slip_latch

    @slip_latch.setter
    def slip_latch(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'slip_latch' field must be of type 'bool'"
        self._slip_latch = value

    @builtins.property
    def vel(self):
        """Message field 'vel'."""
        return self._vel

    @vel.setter
    def vel(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'vel' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'vel' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._vel = value

    @builtins.property
    def vel_avg(self):
        """Message field 'vel_avg'."""
        return self._vel_avg

    @vel_avg.setter
    def vel_avg(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'vel_avg' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'vel_avg' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._vel_avg = value
