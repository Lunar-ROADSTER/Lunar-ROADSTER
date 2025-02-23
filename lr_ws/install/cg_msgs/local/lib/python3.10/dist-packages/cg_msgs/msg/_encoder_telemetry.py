# generated from rosidl_generator_py/resource/_idl.py.em
# with input from cg_msgs:msg/EncoderTelemetry.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_EncoderTelemetry(type):
    """Metaclass of message 'EncoderTelemetry'."""

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
                'cg_msgs.msg.EncoderTelemetry')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__encoder_telemetry
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__encoder_telemetry
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__encoder_telemetry
            cls._TYPE_SUPPORT = module.type_support_msg__msg__encoder_telemetry
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__encoder_telemetry

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'STEER_POS_FRONT__DEFAULT': 0,
            'STEER_POS_REAR__DEFAULT': 0,
            'TOOL_POS__DEFAULT': 0,
            'DRIVE_VEL_FRONT__DEFAULT': 0,
            'DRIVE_VEL_REAR__DEFAULT': 0,
            'DRIVE_DELTA_FRONT__DEFAULT': 0,
            'DRIVE_DELTA_REAR__DEFAULT': 0,
            'TERM_BYTE__DEFAULT': 0,
        }

    @property
    def STEER_POS_FRONT__DEFAULT(cls):
        """Return default value for message field 'steer_pos_front'."""
        return 0

    @property
    def STEER_POS_REAR__DEFAULT(cls):
        """Return default value for message field 'steer_pos_rear'."""
        return 0

    @property
    def TOOL_POS__DEFAULT(cls):
        """Return default value for message field 'tool_pos'."""
        return 0

    @property
    def DRIVE_VEL_FRONT__DEFAULT(cls):
        """Return default value for message field 'drive_vel_front'."""
        return 0

    @property
    def DRIVE_VEL_REAR__DEFAULT(cls):
        """Return default value for message field 'drive_vel_rear'."""
        return 0

    @property
    def DRIVE_DELTA_FRONT__DEFAULT(cls):
        """Return default value for message field 'drive_delta_front'."""
        return 0

    @property
    def DRIVE_DELTA_REAR__DEFAULT(cls):
        """Return default value for message field 'drive_delta_rear'."""
        return 0

    @property
    def TERM_BYTE__DEFAULT(cls):
        """Return default value for message field 'term_byte'."""
        return 0


class EncoderTelemetry(metaclass=Metaclass_EncoderTelemetry):
    """Message class 'EncoderTelemetry'."""

    __slots__ = [
        '_header',
        '_steer_pos_front',
        '_steer_pos_rear',
        '_tool_pos',
        '_drive_vel_front',
        '_drive_vel_rear',
        '_drive_delta_front',
        '_drive_delta_rear',
        '_term_byte',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'steer_pos_front': 'int32',
        'steer_pos_rear': 'int32',
        'tool_pos': 'int32',
        'drive_vel_front': 'int32',
        'drive_vel_rear': 'int32',
        'drive_delta_front': 'int32',
        'drive_delta_rear': 'int32',
        'term_byte': 'int32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.steer_pos_front = kwargs.get(
            'steer_pos_front', EncoderTelemetry.STEER_POS_FRONT__DEFAULT)
        self.steer_pos_rear = kwargs.get(
            'steer_pos_rear', EncoderTelemetry.STEER_POS_REAR__DEFAULT)
        self.tool_pos = kwargs.get(
            'tool_pos', EncoderTelemetry.TOOL_POS__DEFAULT)
        self.drive_vel_front = kwargs.get(
            'drive_vel_front', EncoderTelemetry.DRIVE_VEL_FRONT__DEFAULT)
        self.drive_vel_rear = kwargs.get(
            'drive_vel_rear', EncoderTelemetry.DRIVE_VEL_REAR__DEFAULT)
        self.drive_delta_front = kwargs.get(
            'drive_delta_front', EncoderTelemetry.DRIVE_DELTA_FRONT__DEFAULT)
        self.drive_delta_rear = kwargs.get(
            'drive_delta_rear', EncoderTelemetry.DRIVE_DELTA_REAR__DEFAULT)
        self.term_byte = kwargs.get(
            'term_byte', EncoderTelemetry.TERM_BYTE__DEFAULT)

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
        if self.steer_pos_front != other.steer_pos_front:
            return False
        if self.steer_pos_rear != other.steer_pos_rear:
            return False
        if self.tool_pos != other.tool_pos:
            return False
        if self.drive_vel_front != other.drive_vel_front:
            return False
        if self.drive_vel_rear != other.drive_vel_rear:
            return False
        if self.drive_delta_front != other.drive_delta_front:
            return False
        if self.drive_delta_rear != other.drive_delta_rear:
            return False
        if self.term_byte != other.term_byte:
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
    def steer_pos_front(self):
        """Message field 'steer_pos_front'."""
        return self._steer_pos_front

    @steer_pos_front.setter
    def steer_pos_front(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'steer_pos_front' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'steer_pos_front' field must be an integer in [-2147483648, 2147483647]"
        self._steer_pos_front = value

    @builtins.property
    def steer_pos_rear(self):
        """Message field 'steer_pos_rear'."""
        return self._steer_pos_rear

    @steer_pos_rear.setter
    def steer_pos_rear(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'steer_pos_rear' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'steer_pos_rear' field must be an integer in [-2147483648, 2147483647]"
        self._steer_pos_rear = value

    @builtins.property
    def tool_pos(self):
        """Message field 'tool_pos'."""
        return self._tool_pos

    @tool_pos.setter
    def tool_pos(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'tool_pos' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'tool_pos' field must be an integer in [-2147483648, 2147483647]"
        self._tool_pos = value

    @builtins.property
    def drive_vel_front(self):
        """Message field 'drive_vel_front'."""
        return self._drive_vel_front

    @drive_vel_front.setter
    def drive_vel_front(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'drive_vel_front' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'drive_vel_front' field must be an integer in [-2147483648, 2147483647]"
        self._drive_vel_front = value

    @builtins.property
    def drive_vel_rear(self):
        """Message field 'drive_vel_rear'."""
        return self._drive_vel_rear

    @drive_vel_rear.setter
    def drive_vel_rear(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'drive_vel_rear' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'drive_vel_rear' field must be an integer in [-2147483648, 2147483647]"
        self._drive_vel_rear = value

    @builtins.property
    def drive_delta_front(self):
        """Message field 'drive_delta_front'."""
        return self._drive_delta_front

    @drive_delta_front.setter
    def drive_delta_front(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'drive_delta_front' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'drive_delta_front' field must be an integer in [-2147483648, 2147483647]"
        self._drive_delta_front = value

    @builtins.property
    def drive_delta_rear(self):
        """Message field 'drive_delta_rear'."""
        return self._drive_delta_rear

    @drive_delta_rear.setter
    def drive_delta_rear(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'drive_delta_rear' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'drive_delta_rear' field must be an integer in [-2147483648, 2147483647]"
        self._drive_delta_rear = value

    @builtins.property
    def term_byte(self):
        """Message field 'term_byte'."""
        return self._term_byte

    @term_byte.setter
    def term_byte(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'term_byte' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'term_byte' field must be an integer in [-2147483648, 2147483647]"
        self._term_byte = value
