# generated from rosidl_generator_py/resource/_idl.py.em
# with input from lx_msgs:srv/Switch.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Switch_Request(type):
    """Metaclass of message 'Switch_Request'."""

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
                'lx_msgs.srv.Switch_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__switch__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__switch__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__switch__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__switch__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__switch__request

            from lx_msgs.msg import BermSection
            if BermSection.__class__._TYPE_SUPPORT is None:
                BermSection.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Switch_Request(metaclass=Metaclass_Switch_Request):
    """Message class 'Switch_Request'."""

    __slots__ = [
        '_switch_state',
        '_current_berm_segment',
        '_prev_berm_segment',
        '_first_seg_dump',
    ]

    _fields_and_field_types = {
        'switch_state': 'boolean',
        'current_berm_segment': 'lx_msgs/BermSection',
        'prev_berm_segment': 'lx_msgs/BermSection',
        'first_seg_dump': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['lx_msgs', 'msg'], 'BermSection'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['lx_msgs', 'msg'], 'BermSection'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.switch_state = kwargs.get('switch_state', bool())
        from lx_msgs.msg import BermSection
        self.current_berm_segment = kwargs.get('current_berm_segment', BermSection())
        from lx_msgs.msg import BermSection
        self.prev_berm_segment = kwargs.get('prev_berm_segment', BermSection())
        self.first_seg_dump = kwargs.get('first_seg_dump', bool())

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
        if self.switch_state != other.switch_state:
            return False
        if self.current_berm_segment != other.current_berm_segment:
            return False
        if self.prev_berm_segment != other.prev_berm_segment:
            return False
        if self.first_seg_dump != other.first_seg_dump:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def switch_state(self):
        """Message field 'switch_state'."""
        return self._switch_state

    @switch_state.setter
    def switch_state(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'switch_state' field must be of type 'bool'"
        self._switch_state = value

    @builtins.property
    def current_berm_segment(self):
        """Message field 'current_berm_segment'."""
        return self._current_berm_segment

    @current_berm_segment.setter
    def current_berm_segment(self, value):
        if __debug__:
            from lx_msgs.msg import BermSection
            assert \
                isinstance(value, BermSection), \
                "The 'current_berm_segment' field must be a sub message of type 'BermSection'"
        self._current_berm_segment = value

    @builtins.property
    def prev_berm_segment(self):
        """Message field 'prev_berm_segment'."""
        return self._prev_berm_segment

    @prev_berm_segment.setter
    def prev_berm_segment(self, value):
        if __debug__:
            from lx_msgs.msg import BermSection
            assert \
                isinstance(value, BermSection), \
                "The 'prev_berm_segment' field must be a sub message of type 'BermSection'"
        self._prev_berm_segment = value

    @builtins.property
    def first_seg_dump(self):
        """Message field 'first_seg_dump'."""
        return self._first_seg_dump

    @first_seg_dump.setter
    def first_seg_dump(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'first_seg_dump' field must be of type 'bool'"
        self._first_seg_dump = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_Switch_Response(type):
    """Metaclass of message 'Switch_Response'."""

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
                'lx_msgs.srv.Switch_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__switch__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__switch__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__switch__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__switch__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__switch__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Switch_Response(metaclass=Metaclass_Switch_Response):
    """Message class 'Switch_Response'."""

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


class Metaclass_Switch(type):
    """Metaclass of service 'Switch'."""

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
                'lx_msgs.srv.Switch')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__switch

            from lx_msgs.srv import _switch
            if _switch.Metaclass_Switch_Request._TYPE_SUPPORT is None:
                _switch.Metaclass_Switch_Request.__import_type_support__()
            if _switch.Metaclass_Switch_Response._TYPE_SUPPORT is None:
                _switch.Metaclass_Switch_Response.__import_type_support__()


class Switch(metaclass=Metaclass_Switch):
    from lx_msgs.srv._switch import Switch_Request as Request
    from lx_msgs.srv._switch import Switch_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
