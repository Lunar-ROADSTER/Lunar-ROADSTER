# generated from rosidl_generator_py/resource/_idl.py.em
# with input from cg_msgs:msg/MuxMode.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_MuxMode(type):
    """Metaclass of message 'MuxMode'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'IDLE': 0,
        'AUTOGRADER': 1,
        'FULL_AUTONOMY': 2,
        'FULL_TELEOP': 3,
        'HIGHEST_VALID_MODE': 3,
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
                'cg_msgs.msg.MuxMode')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__mux_mode
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__mux_mode
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__mux_mode
            cls._TYPE_SUPPORT = module.type_support_msg__msg__mux_mode
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__mux_mode

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'IDLE': cls.__constants['IDLE'],
            'AUTOGRADER': cls.__constants['AUTOGRADER'],
            'FULL_AUTONOMY': cls.__constants['FULL_AUTONOMY'],
            'FULL_TELEOP': cls.__constants['FULL_TELEOP'],
            'HIGHEST_VALID_MODE': cls.__constants['HIGHEST_VALID_MODE'],
            'MODE__DEFAULT': 3,
        }

    @property
    def IDLE(self):
        """Message constant 'IDLE'."""
        return Metaclass_MuxMode.__constants['IDLE']

    @property
    def AUTOGRADER(self):
        """Message constant 'AUTOGRADER'."""
        return Metaclass_MuxMode.__constants['AUTOGRADER']

    @property
    def FULL_AUTONOMY(self):
        """Message constant 'FULL_AUTONOMY'."""
        return Metaclass_MuxMode.__constants['FULL_AUTONOMY']

    @property
    def FULL_TELEOP(self):
        """Message constant 'FULL_TELEOP'."""
        return Metaclass_MuxMode.__constants['FULL_TELEOP']

    @property
    def HIGHEST_VALID_MODE(self):
        """Message constant 'HIGHEST_VALID_MODE'."""
        return Metaclass_MuxMode.__constants['HIGHEST_VALID_MODE']

    @property
    def MODE__DEFAULT(cls):
        """Return default value for message field 'mode'."""
        return 3


class MuxMode(metaclass=Metaclass_MuxMode):
    """
    Message class 'MuxMode'.

    Constants:
      IDLE
      AUTOGRADER
      FULL_AUTONOMY
      FULL_TELEOP
      HIGHEST_VALID_MODE
    """

    __slots__ = [
        '_mode',
    ]

    _fields_and_field_types = {
        'mode': 'uint8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.mode = kwargs.get(
            'mode', MuxMode.MODE__DEFAULT)

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
        if self.mode != other.mode:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def mode(self):
        """Message field 'mode'."""
        return self._mode

    @mode.setter
    def mode(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'mode' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'mode' field must be an unsigned integer in [0, 255]"
        self._mode = value
