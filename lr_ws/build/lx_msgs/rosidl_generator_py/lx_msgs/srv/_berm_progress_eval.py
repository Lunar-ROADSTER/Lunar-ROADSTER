# generated from rosidl_generator_py/resource/_idl.py.em
# with input from lx_msgs:srv/BermProgressEval.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_BermProgressEval_Request(type):
    """Metaclass of message 'BermProgressEval_Request'."""

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
                'lx_msgs.srv.BermProgressEval_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__berm_progress_eval__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__berm_progress_eval__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__berm_progress_eval__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__berm_progress_eval__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__berm_progress_eval__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class BermProgressEval_Request(metaclass=Metaclass_BermProgressEval_Request):
    """Message class 'BermProgressEval_Request'."""

    __slots__ = [
        '_need_metrics',
    ]

    _fields_and_field_types = {
        'need_metrics': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.need_metrics = kwargs.get('need_metrics', bool())

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
        if self.need_metrics != other.need_metrics:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def need_metrics(self):
        """Message field 'need_metrics'."""
        return self._need_metrics

    @need_metrics.setter
    def need_metrics(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'need_metrics' field must be of type 'bool'"
        self._need_metrics = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_BermProgressEval_Response(type):
    """Metaclass of message 'BermProgressEval_Response'."""

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
                'lx_msgs.srv.BermProgressEval_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__berm_progress_eval__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__berm_progress_eval__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__berm_progress_eval__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__berm_progress_eval__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__berm_progress_eval__response

            from lx_msgs.msg import BermProgress
            if BermProgress.__class__._TYPE_SUPPORT is None:
                BermProgress.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class BermProgressEval_Response(metaclass=Metaclass_BermProgressEval_Response):
    """Message class 'BermProgressEval_Response'."""

    __slots__ = [
        '_progress',
    ]

    _fields_and_field_types = {
        'progress': 'lx_msgs/BermProgress',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['lx_msgs', 'msg'], 'BermProgress'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from lx_msgs.msg import BermProgress
        self.progress = kwargs.get('progress', BermProgress())

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
        if self.progress != other.progress:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def progress(self):
        """Message field 'progress'."""
        return self._progress

    @progress.setter
    def progress(self, value):
        if __debug__:
            from lx_msgs.msg import BermProgress
            assert \
                isinstance(value, BermProgress), \
                "The 'progress' field must be a sub message of type 'BermProgress'"
        self._progress = value


class Metaclass_BermProgressEval(type):
    """Metaclass of service 'BermProgressEval'."""

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
                'lx_msgs.srv.BermProgressEval')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__berm_progress_eval

            from lx_msgs.srv import _berm_progress_eval
            if _berm_progress_eval.Metaclass_BermProgressEval_Request._TYPE_SUPPORT is None:
                _berm_progress_eval.Metaclass_BermProgressEval_Request.__import_type_support__()
            if _berm_progress_eval.Metaclass_BermProgressEval_Response._TYPE_SUPPORT is None:
                _berm_progress_eval.Metaclass_BermProgressEval_Response.__import_type_support__()


class BermProgressEval(metaclass=Metaclass_BermProgressEval):
    from lx_msgs.srv._berm_progress_eval import BermProgressEval_Request as Request
    from lx_msgs.srv._berm_progress_eval import BermProgressEval_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
