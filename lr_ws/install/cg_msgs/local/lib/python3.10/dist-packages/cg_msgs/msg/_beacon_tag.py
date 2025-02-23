# generated from rosidl_generator_py/resource/_idl.py.em
# with input from cg_msgs:msg/BeaconTag.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_BeaconTag(type):
    """Metaclass of message 'BeaconTag'."""

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
                'cg_msgs.msg.BeaconTag')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__beacon_tag
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__beacon_tag
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__beacon_tag
            cls._TYPE_SUPPORT = module.type_support_msg__msg__beacon_tag
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__beacon_tag

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


class BeaconTag(metaclass=Metaclass_BeaconTag):
    """Message class 'BeaconTag'."""

    __slots__ = [
        '_header',
        '_tag_id',
        '_pose_x',
        '_pose_y',
        '_pose_z',
        '_orientation_x',
        '_orientation_y',
        '_orientation_z',
        '_orientation_w',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'tag_id': 'string',
        'pose_x': 'double',
        'pose_y': 'double',
        'pose_z': 'double',
        'orientation_x': 'double',
        'orientation_y': 'double',
        'orientation_z': 'double',
        'orientation_w': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
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
        self.tag_id = kwargs.get('tag_id', str())
        self.pose_x = kwargs.get('pose_x', float())
        self.pose_y = kwargs.get('pose_y', float())
        self.pose_z = kwargs.get('pose_z', float())
        self.orientation_x = kwargs.get('orientation_x', float())
        self.orientation_y = kwargs.get('orientation_y', float())
        self.orientation_z = kwargs.get('orientation_z', float())
        self.orientation_w = kwargs.get('orientation_w', float())

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
        if self.tag_id != other.tag_id:
            return False
        if self.pose_x != other.pose_x:
            return False
        if self.pose_y != other.pose_y:
            return False
        if self.pose_z != other.pose_z:
            return False
        if self.orientation_x != other.orientation_x:
            return False
        if self.orientation_y != other.orientation_y:
            return False
        if self.orientation_z != other.orientation_z:
            return False
        if self.orientation_w != other.orientation_w:
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
    def tag_id(self):
        """Message field 'tag_id'."""
        return self._tag_id

    @tag_id.setter
    def tag_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'tag_id' field must be of type 'str'"
        self._tag_id = value

    @builtins.property
    def pose_x(self):
        """Message field 'pose_x'."""
        return self._pose_x

    @pose_x.setter
    def pose_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'pose_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'pose_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._pose_x = value

    @builtins.property
    def pose_y(self):
        """Message field 'pose_y'."""
        return self._pose_y

    @pose_y.setter
    def pose_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'pose_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'pose_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._pose_y = value

    @builtins.property
    def pose_z(self):
        """Message field 'pose_z'."""
        return self._pose_z

    @pose_z.setter
    def pose_z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'pose_z' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'pose_z' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._pose_z = value

    @builtins.property
    def orientation_x(self):
        """Message field 'orientation_x'."""
        return self._orientation_x

    @orientation_x.setter
    def orientation_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'orientation_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'orientation_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._orientation_x = value

    @builtins.property
    def orientation_y(self):
        """Message field 'orientation_y'."""
        return self._orientation_y

    @orientation_y.setter
    def orientation_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'orientation_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'orientation_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._orientation_y = value

    @builtins.property
    def orientation_z(self):
        """Message field 'orientation_z'."""
        return self._orientation_z

    @orientation_z.setter
    def orientation_z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'orientation_z' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'orientation_z' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._orientation_z = value

    @builtins.property
    def orientation_w(self):
        """Message field 'orientation_w'."""
        return self._orientation_w

    @orientation_w.setter
    def orientation_w(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'orientation_w' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'orientation_w' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._orientation_w = value
