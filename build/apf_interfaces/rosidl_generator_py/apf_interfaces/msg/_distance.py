# generated from rosidl_generator_py/resource/_idl.py.em
# with input from apf_interfaces:msg/Distance.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'obstacle_distance'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Distance(type):
    """Metaclass of message 'Distance'."""

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
            module = import_type_support('apf_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'apf_interfaces.msg.Distance')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__distance
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__distance
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__distance
            cls._TYPE_SUPPORT = module.type_support_msg__msg__distance
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__distance

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


class Distance(metaclass=Metaclass_Distance):
    """Message class 'Distance'."""

    __slots__ = [
        '_end_point',
        '_direction_vector',
        '_target_point',
        '_end_distance',
        '_end_angle_distance',
        '_obstacle_distance',
        '_obstacle_direction_vector',
        '_obstacle_count',
        '_link_count',
    ]

    _fields_and_field_types = {
        'end_point': 'geometry_msgs/Point',
        'direction_vector': 'geometry_msgs/Point',
        'target_point': 'geometry_msgs/Point',
        'end_distance': 'double',
        'end_angle_distance': 'geometry_msgs/Point',
        'obstacle_distance': 'sequence<double>',
        'obstacle_direction_vector': 'sequence<geometry_msgs/Point>',
        'obstacle_count': 'int32',
        'link_count': 'int32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point')),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from geometry_msgs.msg import Point
        self.end_point = kwargs.get('end_point', Point())
        from geometry_msgs.msg import Point
        self.direction_vector = kwargs.get('direction_vector', Point())
        from geometry_msgs.msg import Point
        self.target_point = kwargs.get('target_point', Point())
        self.end_distance = kwargs.get('end_distance', float())
        from geometry_msgs.msg import Point
        self.end_angle_distance = kwargs.get('end_angle_distance', Point())
        self.obstacle_distance = array.array('d', kwargs.get('obstacle_distance', []))
        self.obstacle_direction_vector = kwargs.get('obstacle_direction_vector', [])
        self.obstacle_count = kwargs.get('obstacle_count', int())
        self.link_count = kwargs.get('link_count', int())

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
        if self.end_point != other.end_point:
            return False
        if self.direction_vector != other.direction_vector:
            return False
        if self.target_point != other.target_point:
            return False
        if self.end_distance != other.end_distance:
            return False
        if self.end_angle_distance != other.end_angle_distance:
            return False
        if self.obstacle_distance != other.obstacle_distance:
            return False
        if self.obstacle_direction_vector != other.obstacle_direction_vector:
            return False
        if self.obstacle_count != other.obstacle_count:
            return False
        if self.link_count != other.link_count:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def end_point(self):
        """Message field 'end_point'."""
        return self._end_point

    @end_point.setter
    def end_point(self, value):
        if __debug__:
            from geometry_msgs.msg import Point
            assert \
                isinstance(value, Point), \
                "The 'end_point' field must be a sub message of type 'Point'"
        self._end_point = value

    @builtins.property
    def direction_vector(self):
        """Message field 'direction_vector'."""
        return self._direction_vector

    @direction_vector.setter
    def direction_vector(self, value):
        if __debug__:
            from geometry_msgs.msg import Point
            assert \
                isinstance(value, Point), \
                "The 'direction_vector' field must be a sub message of type 'Point'"
        self._direction_vector = value

    @builtins.property
    def target_point(self):
        """Message field 'target_point'."""
        return self._target_point

    @target_point.setter
    def target_point(self, value):
        if __debug__:
            from geometry_msgs.msg import Point
            assert \
                isinstance(value, Point), \
                "The 'target_point' field must be a sub message of type 'Point'"
        self._target_point = value

    @builtins.property
    def end_distance(self):
        """Message field 'end_distance'."""
        return self._end_distance

    @end_distance.setter
    def end_distance(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'end_distance' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'end_distance' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._end_distance = value

    @builtins.property
    def end_angle_distance(self):
        """Message field 'end_angle_distance'."""
        return self._end_angle_distance

    @end_angle_distance.setter
    def end_angle_distance(self, value):
        if __debug__:
            from geometry_msgs.msg import Point
            assert \
                isinstance(value, Point), \
                "The 'end_angle_distance' field must be a sub message of type 'Point'"
        self._end_angle_distance = value

    @builtins.property
    def obstacle_distance(self):
        """Message field 'obstacle_distance'."""
        return self._obstacle_distance

    @obstacle_distance.setter
    def obstacle_distance(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'obstacle_distance' array.array() must have the type code of 'd'"
            self._obstacle_distance = value
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
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'obstacle_distance' field must be a set or sequence and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._obstacle_distance = array.array('d', value)

    @builtins.property
    def obstacle_direction_vector(self):
        """Message field 'obstacle_direction_vector'."""
        return self._obstacle_direction_vector

    @obstacle_direction_vector.setter
    def obstacle_direction_vector(self, value):
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
                "The 'obstacle_direction_vector' field must be a set or sequence and each value of type 'Point'"
        self._obstacle_direction_vector = value

    @builtins.property
    def obstacle_count(self):
        """Message field 'obstacle_count'."""
        return self._obstacle_count

    @obstacle_count.setter
    def obstacle_count(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'obstacle_count' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'obstacle_count' field must be an integer in [-2147483648, 2147483647]"
        self._obstacle_count = value

    @builtins.property
    def link_count(self):
        """Message field 'link_count'."""
        return self._link_count

    @link_count.setter
    def link_count(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'link_count' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'link_count' field must be an integer in [-2147483648, 2147483647]"
        self._link_count = value
