# generated from rosidl_generator_py/resource/_idl.py.em
# with input from robot_localization:srv/FromLL.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_FromLL_Request(type):
    """Metaclass of message 'FromLL_Request'."""

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
            module = import_type_support('robot_localization')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'robot_localization.srv.FromLL_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__from_ll__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__from_ll__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__from_ll__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__from_ll__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__from_ll__request

            from geographic_msgs.msg import GeoPoint
            if GeoPoint.__class__._TYPE_SUPPORT is None:
                GeoPoint.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class FromLL_Request(metaclass=Metaclass_FromLL_Request):
    """Message class 'FromLL_Request'."""

    __slots__ = [
        '_ll_point',
    ]

    _fields_and_field_types = {
        'll_point': 'geographic_msgs/GeoPoint',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['geographic_msgs', 'msg'], 'GeoPoint'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from geographic_msgs.msg import GeoPoint
        self.ll_point = kwargs.get('ll_point', GeoPoint())

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
        if self.ll_point != other.ll_point:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def ll_point(self):
        """Message field 'll_point'."""
        return self._ll_point

    @ll_point.setter
    def ll_point(self, value):
        if __debug__:
            from geographic_msgs.msg import GeoPoint
            assert \
                isinstance(value, GeoPoint), \
                "The 'll_point' field must be a sub message of type 'GeoPoint'"
        self._ll_point = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_FromLL_Response(type):
    """Metaclass of message 'FromLL_Response'."""

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
            module = import_type_support('robot_localization')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'robot_localization.srv.FromLL_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__from_ll__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__from_ll__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__from_ll__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__from_ll__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__from_ll__response

            from geometry_msgs.msg import Point
            if Point.__class__._TYPE_SUPPORT is None:
                Point.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class FromLL_Response(metaclass=Metaclass_FromLL_Response):
    """Message class 'FromLL_Response'."""

    __slots__ = [
        '_map_point',
    ]

    _fields_and_field_types = {
        'map_point': 'geometry_msgs/Point',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from geometry_msgs.msg import Point
        self.map_point = kwargs.get('map_point', Point())

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
        if self.map_point != other.map_point:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def map_point(self):
        """Message field 'map_point'."""
        return self._map_point

    @map_point.setter
    def map_point(self, value):
        if __debug__:
            from geometry_msgs.msg import Point
            assert \
                isinstance(value, Point), \
                "The 'map_point' field must be a sub message of type 'Point'"
        self._map_point = value


class Metaclass_FromLL(type):
    """Metaclass of service 'FromLL'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('robot_localization')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'robot_localization.srv.FromLL')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__from_ll

            from robot_localization.srv import _from_ll
            if _from_ll.Metaclass_FromLL_Request._TYPE_SUPPORT is None:
                _from_ll.Metaclass_FromLL_Request.__import_type_support__()
            if _from_ll.Metaclass_FromLL_Response._TYPE_SUPPORT is None:
                _from_ll.Metaclass_FromLL_Response.__import_type_support__()


class FromLL(metaclass=Metaclass_FromLL):
    from robot_localization.srv._from_ll import FromLL_Request as Request
    from robot_localization.srv._from_ll import FromLL_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
