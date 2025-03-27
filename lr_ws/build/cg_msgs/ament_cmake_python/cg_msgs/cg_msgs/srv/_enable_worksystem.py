# generated from rosidl_generator_py/resource/_idl.py.em
# with input from cg_msgs:srv/EnableWorksystem.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_EnableWorksystem_Request(type):
    """Metaclass of message 'EnableWorksystem_Request'."""

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
                'cg_msgs.srv.EnableWorksystem_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__enable_worksystem__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__enable_worksystem__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__enable_worksystem__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__enable_worksystem__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__enable_worksystem__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class EnableWorksystem_Request(metaclass=Metaclass_EnableWorksystem_Request):
    """Message class 'EnableWorksystem_Request'."""

    __slots__ = [
        '_enable_worksystem',
    ]

    _fields_and_field_types = {
        'enable_worksystem': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.enable_worksystem = kwargs.get('enable_worksystem', bool())

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
        if self.enable_worksystem != other.enable_worksystem:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def enable_worksystem(self):
        """Message field 'enable_worksystem'."""
        return self._enable_worksystem

    @enable_worksystem.setter
    def enable_worksystem(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'enable_worksystem' field must be of type 'bool'"
        self._enable_worksystem = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_EnableWorksystem_Response(type):
    """Metaclass of message 'EnableWorksystem_Response'."""

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
                'cg_msgs.srv.EnableWorksystem_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__enable_worksystem__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__enable_worksystem__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__enable_worksystem__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__enable_worksystem__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__enable_worksystem__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class EnableWorksystem_Response(metaclass=Metaclass_EnableWorksystem_Response):
    """Message class 'EnableWorksystem_Response'."""

    __slots__ = [
        '_worksystem_enabled',
    ]

    _fields_and_field_types = {
        'worksystem_enabled': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.worksystem_enabled = kwargs.get('worksystem_enabled', bool())

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
        if self.worksystem_enabled != other.worksystem_enabled:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def worksystem_enabled(self):
        """Message field 'worksystem_enabled'."""
        return self._worksystem_enabled

    @worksystem_enabled.setter
    def worksystem_enabled(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'worksystem_enabled' field must be of type 'bool'"
        self._worksystem_enabled = value


class Metaclass_EnableWorksystem(type):
    """Metaclass of service 'EnableWorksystem'."""

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
                'cg_msgs.srv.EnableWorksystem')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__enable_worksystem

            from cg_msgs.srv import _enable_worksystem
            if _enable_worksystem.Metaclass_EnableWorksystem_Request._TYPE_SUPPORT is None:
                _enable_worksystem.Metaclass_EnableWorksystem_Request.__import_type_support__()
            if _enable_worksystem.Metaclass_EnableWorksystem_Response._TYPE_SUPPORT is None:
                _enable_worksystem.Metaclass_EnableWorksystem_Response.__import_type_support__()


class EnableWorksystem(metaclass=Metaclass_EnableWorksystem):
    from cg_msgs.srv._enable_worksystem import EnableWorksystem_Request as Request
    from cg_msgs.srv._enable_worksystem import EnableWorksystem_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
