# generated from rosidl_generator_py/resource/_idl.py.em
# with input from lx_msgs:msg/PlannedTask.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_PlannedTask(type):
    """Metaclass of message 'PlannedTask'."""

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
                'lx_msgs.msg.PlannedTask')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__planned_task
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__planned_task
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__planned_task
            cls._TYPE_SUPPORT = module.type_support_msg__msg__planned_task
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__planned_task

            from geometry_msgs.msg import Pose
            if Pose.__class__._TYPE_SUPPORT is None:
                Pose.__class__.__import_type_support__()

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


class PlannedTask(metaclass=Metaclass_PlannedTask):
    """Message class 'PlannedTask'."""

    __slots__ = [
        '_task_type',
        '_pose',
        '_berm_point',
    ]

    _fields_and_field_types = {
        'task_type': 'uint32',
        'pose': 'geometry_msgs/Pose',
        'berm_point': 'lx_msgs/BermSection',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Pose'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['lx_msgs', 'msg'], 'BermSection'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.task_type = kwargs.get('task_type', int())
        from geometry_msgs.msg import Pose
        self.pose = kwargs.get('pose', Pose())
        from lx_msgs.msg import BermSection
        self.berm_point = kwargs.get('berm_point', BermSection())

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
        if self.task_type != other.task_type:
            return False
        if self.pose != other.pose:
            return False
        if self.berm_point != other.berm_point:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def task_type(self):
        """Message field 'task_type'."""
        return self._task_type

    @task_type.setter
    def task_type(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'task_type' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'task_type' field must be an unsigned integer in [0, 4294967295]"
        self._task_type = value

    @builtins.property
    def pose(self):
        """Message field 'pose'."""
        return self._pose

    @pose.setter
    def pose(self, value):
        if __debug__:
            from geometry_msgs.msg import Pose
            assert \
                isinstance(value, Pose), \
                "The 'pose' field must be a sub message of type 'Pose'"
        self._pose = value

    @builtins.property
    def berm_point(self):
        """Message field 'berm_point'."""
        return self._berm_point

    @berm_point.setter
    def berm_point(self, value):
        if __debug__:
            from lx_msgs.msg import BermSection
            assert \
                isinstance(value, BermSection), \
                "The 'berm_point' field must be a sub message of type 'BermSection'"
        self._berm_point = value
