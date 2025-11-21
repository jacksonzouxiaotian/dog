# generated from rosidl_generator_py/resource/_idl.py.em
# with input from hdl_global_localization:srv/QueryGlobalLocalization.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_QueryGlobalLocalization_Request(type):
    """Metaclass of message 'QueryGlobalLocalization_Request'."""

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
            module = import_type_support('hdl_global_localization')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'hdl_global_localization.srv.QueryGlobalLocalization_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__query_global_localization__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__query_global_localization__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__query_global_localization__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__query_global_localization__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__query_global_localization__request

            from sensor_msgs.msg import PointCloud2
            if PointCloud2.__class__._TYPE_SUPPORT is None:
                PointCloud2.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class QueryGlobalLocalization_Request(metaclass=Metaclass_QueryGlobalLocalization_Request):
    """Message class 'QueryGlobalLocalization_Request'."""

    __slots__ = [
        '_max_num_candidates',
        '_cloud',
    ]

    _fields_and_field_types = {
        'max_num_candidates': 'int64',
        'cloud': 'sensor_msgs/PointCloud2',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['sensor_msgs', 'msg'], 'PointCloud2'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.max_num_candidates = kwargs.get('max_num_candidates', int())
        from sensor_msgs.msg import PointCloud2
        self.cloud = kwargs.get('cloud', PointCloud2())

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
        if self.max_num_candidates != other.max_num_candidates:
            return False
        if self.cloud != other.cloud:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def max_num_candidates(self):
        """Message field 'max_num_candidates'."""
        return self._max_num_candidates

    @max_num_candidates.setter
    def max_num_candidates(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'max_num_candidates' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'max_num_candidates' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._max_num_candidates = value

    @property
    def cloud(self):
        """Message field 'cloud'."""
        return self._cloud

    @cloud.setter
    def cloud(self, value):
        if __debug__:
            from sensor_msgs.msg import PointCloud2
            assert \
                isinstance(value, PointCloud2), \
                "The 'cloud' field must be a sub message of type 'PointCloud2'"
        self._cloud = value


# Import statements for member types

# Member 'inlier_fractions'
# Member 'errors'
import array  # noqa: E402, I100

# already imported above
# import rosidl_parser.definition


class Metaclass_QueryGlobalLocalization_Response(type):
    """Metaclass of message 'QueryGlobalLocalization_Response'."""

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
            module = import_type_support('hdl_global_localization')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'hdl_global_localization.srv.QueryGlobalLocalization_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__query_global_localization__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__query_global_localization__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__query_global_localization__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__query_global_localization__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__query_global_localization__response

            from geometry_msgs.msg import Pose
            if Pose.__class__._TYPE_SUPPORT is None:
                Pose.__class__.__import_type_support__()

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


class QueryGlobalLocalization_Response(metaclass=Metaclass_QueryGlobalLocalization_Response):
    """Message class 'QueryGlobalLocalization_Response'."""

    __slots__ = [
        '_header',
        '_globalmap_header',
        '_inlier_fractions',
        '_errors',
        '_poses',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'globalmap_header': 'std_msgs/Header',
        'inlier_fractions': 'sequence<double>',
        'errors': 'sequence<double>',
        'poses': 'sequence<geometry_msgs/Pose>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Pose')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        from std_msgs.msg import Header
        self.globalmap_header = kwargs.get('globalmap_header', Header())
        self.inlier_fractions = array.array('d', kwargs.get('inlier_fractions', []))
        self.errors = array.array('d', kwargs.get('errors', []))
        self.poses = kwargs.get('poses', [])

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
        if self.globalmap_header != other.globalmap_header:
            return False
        if self.inlier_fractions != other.inlier_fractions:
            return False
        if self.errors != other.errors:
            return False
        if self.poses != other.poses:
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
    def globalmap_header(self):
        """Message field 'globalmap_header'."""
        return self._globalmap_header

    @globalmap_header.setter
    def globalmap_header(self, value):
        if __debug__:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'globalmap_header' field must be a sub message of type 'Header'"
        self._globalmap_header = value

    @property
    def inlier_fractions(self):
        """Message field 'inlier_fractions'."""
        return self._inlier_fractions

    @inlier_fractions.setter
    def inlier_fractions(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'inlier_fractions' array.array() must have the type code of 'd'"
            self._inlier_fractions = value
            return
        if __debug__:
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
                 all(isinstance(v, float) for v in value) and
                 True), \
                "The 'inlier_fractions' field must be a set or sequence and each value of type 'float'"
        self._inlier_fractions = array.array('d', value)

    @property
    def errors(self):
        """Message field 'errors'."""
        return self._errors

    @errors.setter
    def errors(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'errors' array.array() must have the type code of 'd'"
            self._errors = value
            return
        if __debug__:
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
                 all(isinstance(v, float) for v in value) and
                 True), \
                "The 'errors' field must be a set or sequence and each value of type 'float'"
        self._errors = array.array('d', value)

    @property
    def poses(self):
        """Message field 'poses'."""
        return self._poses

    @poses.setter
    def poses(self, value):
        if __debug__:
            from geometry_msgs.msg import Pose
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
                 all(isinstance(v, Pose) for v in value) and
                 True), \
                "The 'poses' field must be a set or sequence and each value of type 'Pose'"
        self._poses = value


class Metaclass_QueryGlobalLocalization(type):
    """Metaclass of service 'QueryGlobalLocalization'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('hdl_global_localization')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'hdl_global_localization.srv.QueryGlobalLocalization')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__query_global_localization

            from hdl_global_localization.srv import _query_global_localization
            if _query_global_localization.Metaclass_QueryGlobalLocalization_Request._TYPE_SUPPORT is None:
                _query_global_localization.Metaclass_QueryGlobalLocalization_Request.__import_type_support__()
            if _query_global_localization.Metaclass_QueryGlobalLocalization_Response._TYPE_SUPPORT is None:
                _query_global_localization.Metaclass_QueryGlobalLocalization_Response.__import_type_support__()


class QueryGlobalLocalization(metaclass=Metaclass_QueryGlobalLocalization):
    from hdl_global_localization.srv._query_global_localization import QueryGlobalLocalization_Request as Request
    from hdl_global_localization.srv._query_global_localization import QueryGlobalLocalization_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
