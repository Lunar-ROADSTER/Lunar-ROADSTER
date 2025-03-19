# generated from rosidl_generator_py/resource/_idl.py.em
# with input from lx_msgs:srv/Plan.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Plan_Request(type):
    """Metaclass of message 'Plan_Request'."""

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
                'lx_msgs.srv.Plan_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__plan__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__plan__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__plan__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__plan__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__plan__request

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


class Plan_Request(metaclass=Metaclass_Plan_Request):
    """Message class 'Plan_Request'."""

    __slots__ = [
        '_berm_input',
        '_berm_height',
        '_section_length',
        '_new_plan',
    ]

    _fields_and_field_types = {
        'berm_input': 'sequence<geometry_msgs/Point>',
        'berm_height': 'float',
        'section_length': 'float',
        'new_plan': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point')),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.berm_input = kwargs.get('berm_input', [])
        self.berm_height = kwargs.get('berm_height', float())
        self.section_length = kwargs.get('section_length', float())
        self.new_plan = kwargs.get('new_plan', bool())

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
        if self.berm_input != other.berm_input:
            return False
        if self.berm_height != other.berm_height:
            return False
        if self.section_length != other.section_length:
            return False
        if self.new_plan != other.new_plan:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def berm_input(self):
        """Message field 'berm_input'."""
        return self._berm_input

    @berm_input.setter
    def berm_input(self, value):
        if __debug__:
            from geometry_msgs.msg import Point
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, Point) for v in value) and
                 True), \
                "The 'berm_input' field must be a set or sequence and each value of type 'Point'"
        self._berm_input = value

    @builtins.property
    def berm_height(self):
        """Message field 'berm_height'."""
        return self._berm_height

    @berm_height.setter
    def berm_height(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'berm_height' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'berm_height' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._berm_height = value

    @builtins.property
    def section_length(self):
        """Message field 'section_length'."""
        return self._section_length

    @section_length.setter
    def section_length(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'section_length' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'section_length' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._section_length = value

    @builtins.property
    def new_plan(self):
        """Message field 'new_plan'."""
        return self._new_plan

    @new_plan.setter
    def new_plan(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'new_plan' field must be of type 'bool'"
        self._new_plan = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_Plan_Response(type):
    """Metaclass of message 'Plan_Response'."""

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
                'lx_msgs.srv.Plan_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__plan__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__plan__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__plan__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__plan__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__plan__response

            from lx_msgs.msg import PlannedTask
            if PlannedTask.__class__._TYPE_SUPPORT is None:
                PlannedTask.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Plan_Response(metaclass=Metaclass_Plan_Response):
    """Message class 'Plan_Response'."""

    __slots__ = [
        '_plan',
    ]

    _fields_and_field_types = {
        'plan': 'sequence<lx_msgs/PlannedTask>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['lx_msgs', 'msg'], 'PlannedTask')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.plan = kwargs.get('plan', [])

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
        if self.plan != other.plan:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def plan(self):
        """Message field 'plan'."""
        return self._plan

    @plan.setter
    def plan(self, value):
        if __debug__:
            from lx_msgs.msg import PlannedTask
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, PlannedTask) for v in value) and
                 True), \
                "The 'plan' field must be a set or sequence and each value of type 'PlannedTask'"
        self._plan = value


class Metaclass_Plan(type):
    """Metaclass of service 'Plan'."""

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
                'lx_msgs.srv.Plan')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__plan

            from lx_msgs.srv import _plan
            if _plan.Metaclass_Plan_Request._TYPE_SUPPORT is None:
                _plan.Metaclass_Plan_Request.__import_type_support__()
            if _plan.Metaclass_Plan_Response._TYPE_SUPPORT is None:
                _plan.Metaclass_Plan_Response.__import_type_support__()


class Plan(metaclass=Metaclass_Plan):
    from lx_msgs.srv._plan import Plan_Request as Request
    from lx_msgs.srv._plan import Plan_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
