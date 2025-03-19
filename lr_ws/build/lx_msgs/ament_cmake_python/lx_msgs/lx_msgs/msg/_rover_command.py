# generated from rosidl_generator_py/resource/_idl.py.em
# with input from lx_msgs:msg/RoverCommand.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_RoverCommand(type):
    """Metaclass of message 'RoverCommand'."""

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
                'lx_msgs.msg.RoverCommand')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__rover_command
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__rover_command
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__rover_command
            cls._TYPE_SUPPORT = module.type_support_msg__msg__rover_command
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__rover_command

            from geometry_msgs.msg import Twist
            if Twist.__class__._TYPE_SUPPORT is None:
                Twist.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class RoverCommand(metaclass=Metaclass_RoverCommand):
    """Message class 'RoverCommand'."""

    __slots__ = [
        '_mobility_twist',
        '_actuator_speed',
        '_drum_speed',
    ]

    _fields_and_field_types = {
        'mobility_twist': 'geometry_msgs/Twist',
        'actuator_speed': 'double',
        'drum_speed': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Twist'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from geometry_msgs.msg import Twist
        self.mobility_twist = kwargs.get('mobility_twist', Twist())
        self.actuator_speed = kwargs.get('actuator_speed', float())
        self.drum_speed = kwargs.get('drum_speed', float())

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
        if self.mobility_twist != other.mobility_twist:
            return False
        if self.actuator_speed != other.actuator_speed:
            return False
        if self.drum_speed != other.drum_speed:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def mobility_twist(self):
        """Message field 'mobility_twist'."""
        return self._mobility_twist

    @mobility_twist.setter
    def mobility_twist(self, value):
        if __debug__:
            from geometry_msgs.msg import Twist
            assert \
                isinstance(value, Twist), \
                "The 'mobility_twist' field must be a sub message of type 'Twist'"
        self._mobility_twist = value

    @builtins.property
    def actuator_speed(self):
        """Message field 'actuator_speed'."""
        return self._actuator_speed

    @actuator_speed.setter
    def actuator_speed(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'actuator_speed' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'actuator_speed' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._actuator_speed = value

    @builtins.property
    def drum_speed(self):
        """Message field 'drum_speed'."""
        return self._drum_speed

    @drum_speed.setter
    def drum_speed(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'drum_speed' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'drum_speed' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._drum_speed = value
