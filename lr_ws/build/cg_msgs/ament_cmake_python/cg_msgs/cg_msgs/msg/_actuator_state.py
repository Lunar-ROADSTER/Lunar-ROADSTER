# generated from rosidl_generator_py/resource/_idl.py.em
# with input from cg_msgs:msg/ActuatorState.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ActuatorState(type):
    """Metaclass of message 'ActuatorState'."""

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
                'cg_msgs.msg.ActuatorState')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__actuator_state
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__actuator_state
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__actuator_state
            cls._TYPE_SUPPORT = module.type_support_msg__msg__actuator_state
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__actuator_state

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'WHEEL_VELOCITY__DEFAULT': 0.0,
            'STEER_POSITION__DEFAULT': 0.0,
            'TOOL_POSITION__DEFAULT': 0.0,
        }

    @property
    def WHEEL_VELOCITY__DEFAULT(cls):
        """Return default value for message field 'wheel_velocity'."""
        return 0.0

    @property
    def STEER_POSITION__DEFAULT(cls):
        """Return default value for message field 'steer_position'."""
        return 0.0

    @property
    def TOOL_POSITION__DEFAULT(cls):
        """Return default value for message field 'tool_position'."""
        return 0.0


class ActuatorState(metaclass=Metaclass_ActuatorState):
    """Message class 'ActuatorState'."""

    __slots__ = [
        '_header',
        '_wheel_velocity',
        '_steer_position',
        '_tool_position',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'wheel_velocity': 'double',
        'steer_position': 'double',
        'tool_position': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.wheel_velocity = kwargs.get(
            'wheel_velocity', ActuatorState.WHEEL_VELOCITY__DEFAULT)
        self.steer_position = kwargs.get(
            'steer_position', ActuatorState.STEER_POSITION__DEFAULT)
        self.tool_position = kwargs.get(
            'tool_position', ActuatorState.TOOL_POSITION__DEFAULT)

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
        if self.wheel_velocity != other.wheel_velocity:
            return False
        if self.steer_position != other.steer_position:
            return False
        if self.tool_position != other.tool_position:
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
    def wheel_velocity(self):
        """Message field 'wheel_velocity'."""
        return self._wheel_velocity

    @wheel_velocity.setter
    def wheel_velocity(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'wheel_velocity' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'wheel_velocity' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._wheel_velocity = value

    @builtins.property
    def steer_position(self):
        """Message field 'steer_position'."""
        return self._steer_position

    @steer_position.setter
    def steer_position(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'steer_position' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'steer_position' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._steer_position = value

    @builtins.property
    def tool_position(self):
        """Message field 'tool_position'."""
        return self._tool_position

    @tool_position.setter
    def tool_position(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'tool_position' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'tool_position' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._tool_position = value
