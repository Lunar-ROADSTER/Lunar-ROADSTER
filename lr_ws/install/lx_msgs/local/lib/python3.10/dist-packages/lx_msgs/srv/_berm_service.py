# generated from rosidl_generator_py/resource/_idl.py.em
# with input from lx_msgs:srv/BermService.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_BermService_Request(type):
    """Metaclass of message 'BermService_Request'."""

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
                'lx_msgs.srv.BermService_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__berm_service__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__berm_service__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__berm_service__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__berm_service__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__berm_service__request

            from lx_msgs.msg import BermConfig
            if BermConfig.__class__._TYPE_SUPPORT is None:
                BermConfig.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class BermService_Request(metaclass=Metaclass_BermService_Request):
    """Message class 'BermService_Request'."""

    __slots__ = [
        '_berm',
    ]

    _fields_and_field_types = {
        'berm': 'lx_msgs/BermConfig',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['lx_msgs', 'msg'], 'BermConfig'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from lx_msgs.msg import BermConfig
        self.berm = kwargs.get('berm', BermConfig())

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
        if self.berm != other.berm:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def berm(self):
        """Message field 'berm'."""
        return self._berm

    @berm.setter
    def berm(self, value):
        if __debug__:
            from lx_msgs.msg import BermConfig
            assert \
                isinstance(value, BermConfig), \
                "The 'berm' field must be a sub message of type 'BermConfig'"
        self._berm = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_BermService_Response(type):
    """Metaclass of message 'BermService_Response'."""

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
                'lx_msgs.srv.BermService_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__berm_service__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__berm_service__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__berm_service__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__berm_service__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__berm_service__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class BermService_Response(metaclass=Metaclass_BermService_Response):
    """Message class 'BermService_Response'."""

    __slots__ = [
        '_success',
    ]

    _fields_and_field_types = {
        'success': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
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
        if self.success != other.success:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

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


class Metaclass_BermService(type):
    """Metaclass of service 'BermService'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('lx_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'lx_msgs.srv.BermService')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__berm_service

            from lx_msgs.srv import _berm_service
            if _berm_service.Metaclass_BermService_Request._TYPE_SUPPORT is None:
                _berm_service.Metaclass_BermService_Request.__import_type_support__()
            if _berm_service.Metaclass_BermService_Response._TYPE_SUPPORT is None:
                _berm_service.Metaclass_BermService_Response.__import_type_support__()


class BermService(metaclass=Metaclass_BermService):
    from lx_msgs.srv._berm_service import BermService_Request as Request
    from lx_msgs.srv._berm_service import BermService_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
