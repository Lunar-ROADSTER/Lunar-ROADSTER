# generated from rosidl_generator_py/resource/_idl.py.em
# with input from cg_msgs:srv/SiteMap.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SiteMap_Request(type):
    """Metaclass of message 'SiteMap_Request'."""

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
                'cg_msgs.srv.SiteMap_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__site_map__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__site_map__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__site_map__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__site_map__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__site_map__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SiteMap_Request(metaclass=Metaclass_SiteMap_Request):
    """Message class 'SiteMap_Request'."""

    __slots__ = [
    ]

    _fields_and_field_types = {
    }

    SLOT_TYPES = (
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))

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
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)


# Import statements for member types

import builtins  # noqa: E402, I100

# already imported above
# import rosidl_parser.definition


class Metaclass_SiteMap_Response(type):
    """Metaclass of message 'SiteMap_Response'."""

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
                'cg_msgs.srv.SiteMap_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__site_map__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__site_map__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__site_map__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__site_map__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__site_map__response

            from cg_msgs.msg import SiteMap
            if SiteMap.__class__._TYPE_SUPPORT is None:
                SiteMap.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SiteMap_Response(metaclass=Metaclass_SiteMap_Response):
    """Message class 'SiteMap_Response'."""

    __slots__ = [
        '_site_map',
        '_map_fully_explored',
        '_success',
    ]

    _fields_and_field_types = {
        'site_map': 'cg_msgs/SiteMap',
        'map_fully_explored': 'boolean',
        'success': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['cg_msgs', 'msg'], 'SiteMap'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from cg_msgs.msg import SiteMap
        self.site_map = kwargs.get('site_map', SiteMap())
        self.map_fully_explored = kwargs.get('map_fully_explored', bool())
        self.success = kwargs.get('success', bool())

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
        if self.site_map != other.site_map:
            return False
        if self.map_fully_explored != other.map_fully_explored:
            return False
        if self.success != other.success:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def site_map(self):
        """Message field 'site_map'."""
        return self._site_map

    @site_map.setter
    def site_map(self, value):
        if __debug__:
            from cg_msgs.msg import SiteMap
            assert \
                isinstance(value, SiteMap), \
                "The 'site_map' field must be a sub message of type 'SiteMap'"
        self._site_map = value

    @builtins.property
    def map_fully_explored(self):
        """Message field 'map_fully_explored'."""
        return self._map_fully_explored

    @map_fully_explored.setter
    def map_fully_explored(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'map_fully_explored' field must be of type 'bool'"
        self._map_fully_explored = value

    @builtins.property
    def success(self):
        """Message field 'success'."""
        return self._success

    @success.setter
    def success(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'success' field must be of type 'bool'"
        self._success = value


class Metaclass_SiteMap(type):
    """Metaclass of service 'SiteMap'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('cg_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'cg_msgs.srv.SiteMap')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__site_map

            from cg_msgs.srv import _site_map
            if _site_map.Metaclass_SiteMap_Request._TYPE_SUPPORT is None:
                _site_map.Metaclass_SiteMap_Request.__import_type_support__()
            if _site_map.Metaclass_SiteMap_Response._TYPE_SUPPORT is None:
                _site_map.Metaclass_SiteMap_Response.__import_type_support__()


class SiteMap(metaclass=Metaclass_SiteMap):
    from cg_msgs.srv._site_map import SiteMap_Request as Request
    from cg_msgs.srv._site_map import SiteMap_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
