# generated from rosidl_generator_py/resource/_idl.py.em
# with input from kindr_msgs:msg/VectorAtPosition.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_VectorAtPosition(type):
    """Metaclass of message 'VectorAtPosition'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'TYPE_TYPELESS': 0,
        'TYPE_JERK': 6,
        'TYPE_ACCELERATION': 7,
        'TYPE_VELOCITY': 8,
        'TYPE_POSITION': 9,
        'TYPE_FORCE': 10,
        'TYPE_MOMEMTUM': 11,
        'TYPE_ANGULAR_JERK': 12,
        'TYPE_ANGULAR_ACCELERATION': 13,
        'TYPE_ANGULAR_VELOCITY': 14,
        'TYPE_TORQUE': 16,
        'TYPE_ANGULAR_MOMEMTUM': 17,
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('kindr_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'kindr_msgs.msg.VectorAtPosition')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__vector_at_position
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__vector_at_position
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__vector_at_position
            cls._TYPE_SUPPORT = module.type_support_msg__msg__vector_at_position
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__vector_at_position

            from geometry_msgs.msg import Point
            if Point.__class__._TYPE_SUPPORT is None:
                Point.__class__.__import_type_support__()

            from geometry_msgs.msg import Vector3
            if Vector3.__class__._TYPE_SUPPORT is None:
                Vector3.__class__.__import_type_support__()

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'TYPE_TYPELESS': cls.__constants['TYPE_TYPELESS'],
            'TYPE_JERK': cls.__constants['TYPE_JERK'],
            'TYPE_ACCELERATION': cls.__constants['TYPE_ACCELERATION'],
            'TYPE_VELOCITY': cls.__constants['TYPE_VELOCITY'],
            'TYPE_POSITION': cls.__constants['TYPE_POSITION'],
            'TYPE_FORCE': cls.__constants['TYPE_FORCE'],
            'TYPE_MOMEMTUM': cls.__constants['TYPE_MOMEMTUM'],
            'TYPE_ANGULAR_JERK': cls.__constants['TYPE_ANGULAR_JERK'],
            'TYPE_ANGULAR_ACCELERATION': cls.__constants['TYPE_ANGULAR_ACCELERATION'],
            'TYPE_ANGULAR_VELOCITY': cls.__constants['TYPE_ANGULAR_VELOCITY'],
            'TYPE_TORQUE': cls.__constants['TYPE_TORQUE'],
            'TYPE_ANGULAR_MOMEMTUM': cls.__constants['TYPE_ANGULAR_MOMEMTUM'],
        }

    @property
    def TYPE_TYPELESS(self):
        """Message constant 'TYPE_TYPELESS'."""
        return Metaclass_VectorAtPosition.__constants['TYPE_TYPELESS']

    @property
    def TYPE_JERK(self):
        """Message constant 'TYPE_JERK'."""
        return Metaclass_VectorAtPosition.__constants['TYPE_JERK']

    @property
    def TYPE_ACCELERATION(self):
        """Message constant 'TYPE_ACCELERATION'."""
        return Metaclass_VectorAtPosition.__constants['TYPE_ACCELERATION']

    @property
    def TYPE_VELOCITY(self):
        """Message constant 'TYPE_VELOCITY'."""
        return Metaclass_VectorAtPosition.__constants['TYPE_VELOCITY']

    @property
    def TYPE_POSITION(self):
        """Message constant 'TYPE_POSITION'."""
        return Metaclass_VectorAtPosition.__constants['TYPE_POSITION']

    @property
    def TYPE_FORCE(self):
        """Message constant 'TYPE_FORCE'."""
        return Metaclass_VectorAtPosition.__constants['TYPE_FORCE']

    @property
    def TYPE_MOMEMTUM(self):
        """Message constant 'TYPE_MOMEMTUM'."""
        return Metaclass_VectorAtPosition.__constants['TYPE_MOMEMTUM']

    @property
    def TYPE_ANGULAR_JERK(self):
        """Message constant 'TYPE_ANGULAR_JERK'."""
        return Metaclass_VectorAtPosition.__constants['TYPE_ANGULAR_JERK']

    @property
    def TYPE_ANGULAR_ACCELERATION(self):
        """Message constant 'TYPE_ANGULAR_ACCELERATION'."""
        return Metaclass_VectorAtPosition.__constants['TYPE_ANGULAR_ACCELERATION']

    @property
    def TYPE_ANGULAR_VELOCITY(self):
        """Message constant 'TYPE_ANGULAR_VELOCITY'."""
        return Metaclass_VectorAtPosition.__constants['TYPE_ANGULAR_VELOCITY']

    @property
    def TYPE_TORQUE(self):
        """Message constant 'TYPE_TORQUE'."""
        return Metaclass_VectorAtPosition.__constants['TYPE_TORQUE']

    @property
    def TYPE_ANGULAR_MOMEMTUM(self):
        """Message constant 'TYPE_ANGULAR_MOMEMTUM'."""
        return Metaclass_VectorAtPosition.__constants['TYPE_ANGULAR_MOMEMTUM']


class VectorAtPosition(metaclass=Metaclass_VectorAtPosition):
    """
    Message class 'VectorAtPosition'.

    Constants:
      TYPE_TYPELESS
      TYPE_JERK
      TYPE_ACCELERATION
      TYPE_VELOCITY
      TYPE_POSITION
      TYPE_FORCE
      TYPE_MOMEMTUM
      TYPE_ANGULAR_JERK
      TYPE_ANGULAR_ACCELERATION
      TYPE_ANGULAR_VELOCITY
      TYPE_TORQUE
      TYPE_ANGULAR_MOMEMTUM
    """

    __slots__ = [
        '_header',
        '_type',
        '_name',
        '_vector',
        '_position',
        '_position_frame_id',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'type': 'uint8',
        'name': 'string',
        'vector': 'geometry_msgs/Vector3',
        'position': 'geometry_msgs/Point',
        'position_frame_id': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Vector3'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.type = kwargs.get('type', int())
        self.name = kwargs.get('name', str())
        from geometry_msgs.msg import Vector3
        self.vector = kwargs.get('vector', Vector3())
        from geometry_msgs.msg import Point
        self.position = kwargs.get('position', Point())
        self.position_frame_id = kwargs.get('position_frame_id', str())

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
        if self.type != other.type:
            return False
        if self.name != other.name:
            return False
        if self.vector != other.vector:
            return False
        if self.position != other.position:
            return False
        if self.position_frame_id != other.position_frame_id:
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

    @builtins.property  # noqa: A003
    def type(self):  # noqa: A003
        """Message field 'type'."""
        return self._type

    @type.setter  # noqa: A003
    def type(self, value):  # noqa: A003
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'type' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'type' field must be an unsigned integer in [0, 255]"
        self._type = value

    @builtins.property
    def name(self):
        """Message field 'name'."""
        return self._name

    @name.setter
    def name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'name' field must be of type 'str'"
        self._name = value

    @builtins.property
    def vector(self):
        """Message field 'vector'."""
        return self._vector

    @vector.setter
    def vector(self, value):
        if __debug__:
            from geometry_msgs.msg import Vector3
            assert \
                isinstance(value, Vector3), \
                "The 'vector' field must be a sub message of type 'Vector3'"
        self._vector = value

    @builtins.property
    def position(self):
        """Message field 'position'."""
        return self._position

    @position.setter
    def position(self, value):
        if __debug__:
            from geometry_msgs.msg import Point
            assert \
                isinstance(value, Point), \
                "The 'position' field must be a sub message of type 'Point'"
        self._position = value

    @builtins.property
    def position_frame_id(self):
        """Message field 'position_frame_id'."""
        return self._position_frame_id

    @position_frame_id.setter
    def position_frame_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'position_frame_id' field must be of type 'str'"
        self._position_frame_id = value
