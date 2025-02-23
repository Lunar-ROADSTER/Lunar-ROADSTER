# generated from rosidl_generator_py/resource/_idl.py.em
# with input from cg_msgs:msg/Pose2D.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Pose2D(type):
    """Metaclass of message 'Pose2D'."""

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
                'cg_msgs.msg.Pose2D')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__pose2_d
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__pose2_d
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__pose2_d
            cls._TYPE_SUPPORT = module.type_support_msg__msg__pose2_d
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__pose2_d

            from cg_msgs.msg import Point2D
            if Point2D.__class__._TYPE_SUPPORT is None:
                Point2D.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'YAW__DEFAULT': 0.0,
        }

    @property
    def YAW__DEFAULT(cls):
        """Return default value for message field 'yaw'."""
        return 0.0


class Pose2D(metaclass=Metaclass_Pose2D):
    """Message class 'Pose2D'."""

    __slots__ = [
        '_pt',
        '_yaw',
    ]

    _fields_and_field_types = {
        'pt': 'cg_msgs/Point2D',
        'yaw': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['cg_msgs', 'msg'], 'Point2D'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from cg_msgs.msg import Point2D
        self.pt = kwargs.get('pt', Point2D())
        self.yaw = kwargs.get(
            'yaw', Pose2D.YAW__DEFAULT)

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
        if self.pt != other.pt:
            return False
        if self.yaw != other.yaw:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def pt(self):
        """Message field 'pt'."""
        return self._pt

    @pt.setter
    def pt(self, value):
        if __debug__:
            from cg_msgs.msg import Point2D
            assert \
                isinstance(value, Point2D), \
                "The 'pt' field must be a sub message of type 'Point2D'"
        self._pt = value

    @builtins.property
    def yaw(self):
        """Message field 'yaw'."""
        return self._yaw

    @yaw.setter
    def yaw(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'yaw' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'yaw' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._yaw = value
