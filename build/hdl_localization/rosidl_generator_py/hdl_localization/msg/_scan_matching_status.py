# generated from rosidl_generator_py/resource/_idl.py.em
# with input from hdl_localization:msg/ScanMatchingStatus.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ScanMatchingStatus(type):
    """Metaclass of message 'ScanMatchingStatus'."""

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
            module = import_type_support('hdl_localization')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'hdl_localization.msg.ScanMatchingStatus')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__scan_matching_status
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__scan_matching_status
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__scan_matching_status
            cls._TYPE_SUPPORT = module.type_support_msg__msg__scan_matching_status
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__scan_matching_status

            from geometry_msgs.msg import Transform
            if Transform.__class__._TYPE_SUPPORT is None:
                Transform.__class__.__import_type_support__()

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

            from std_msgs.msg import String
            if String.__class__._TYPE_SUPPORT is None:
                String.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ScanMatchingStatus(metaclass=Metaclass_ScanMatchingStatus):
    """Message class 'ScanMatchingStatus'."""

    __slots__ = [
        '_header',
        '_has_converged',
        '_matching_error',
        '_inlier_fraction',
        '_relative_pose',
        '_prediction_labels',
        '_prediction_errors',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'has_converged': 'boolean',
        'matching_error': 'float',
        'inlier_fraction': 'float',
        'relative_pose': 'geometry_msgs/Transform',
        'prediction_labels': 'sequence<std_msgs/String>',
        'prediction_errors': 'sequence<geometry_msgs/Transform>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Transform'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'String')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Transform')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.has_converged = kwargs.get('has_converged', bool())
        self.matching_error = kwargs.get('matching_error', float())
        self.inlier_fraction = kwargs.get('inlier_fraction', float())
        from geometry_msgs.msg import Transform
        self.relative_pose = kwargs.get('relative_pose', Transform())
        self.prediction_labels = kwargs.get('prediction_labels', [])
        self.prediction_errors = kwargs.get('prediction_errors', [])

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
        if self.has_converged != other.has_converged:
            return False
        if self.matching_error != other.matching_error:
            return False
        if self.inlier_fraction != other.inlier_fraction:
            return False
        if self.relative_pose != other.relative_pose:
            return False
        if self.prediction_labels != other.prediction_labels:
            return False
        if self.prediction_errors != other.prediction_errors:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
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

    @property
    def has_converged(self):
        """Message field 'has_converged'."""
        return self._has_converged

    @has_converged.setter
    def has_converged(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'has_converged' field must be of type 'bool'"
        self._has_converged = value

    @property
    def matching_error(self):
        """Message field 'matching_error'."""
        return self._matching_error

    @matching_error.setter
    def matching_error(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'matching_error' field must be of type 'float'"
        self._matching_error = value

    @property
    def inlier_fraction(self):
        """Message field 'inlier_fraction'."""
        return self._inlier_fraction

    @inlier_fraction.setter
    def inlier_fraction(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'inlier_fraction' field must be of type 'float'"
        self._inlier_fraction = value

    @property
    def relative_pose(self):
        """Message field 'relative_pose'."""
        return self._relative_pose

    @relative_pose.setter
    def relative_pose(self, value):
        if __debug__:
            from geometry_msgs.msg import Transform
            assert \
                isinstance(value, Transform), \
                "The 'relative_pose' field must be a sub message of type 'Transform'"
        self._relative_pose = value

    @property
    def prediction_labels(self):
        """Message field 'prediction_labels'."""
        return self._prediction_labels

    @prediction_labels.setter
    def prediction_labels(self, value):
        if __debug__:
            from std_msgs.msg import String
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
                 all(isinstance(v, String) for v in value) and
                 True), \
                "The 'prediction_labels' field must be a set or sequence and each value of type 'String'"
        self._prediction_labels = value

    @property
    def prediction_errors(self):
        """Message field 'prediction_errors'."""
        return self._prediction_errors

    @prediction_errors.setter
    def prediction_errors(self, value):
        if __debug__:
            from geometry_msgs.msg import Transform
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
                 all(isinstance(v, Transform) for v in value) and
                 True), \
                "The 'prediction_errors' field must be a set or sequence and each value of type 'Transform'"
        self._prediction_errors = value
