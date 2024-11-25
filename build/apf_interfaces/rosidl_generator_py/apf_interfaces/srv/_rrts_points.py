# generated from rosidl_generator_py/resource/_idl.py.em
# with input from apf_interfaces:srv/RRTSPoints.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'obstacle_points'
# Member 'start_point'
# Member 'end_point'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_RRTSPoints_Request(type):
    """Metaclass of message 'RRTSPoints_Request'."""

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
                'apf_interfaces.srv.RRTSPoints_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__rrts_points__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__rrts_points__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__rrts_points__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__rrts_points__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__rrts_points__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class RRTSPoints_Request(metaclass=Metaclass_RRTSPoints_Request):
    """Message class 'RRTSPoints_Request'."""

    __slots__ = [
        '_obstacle_points',
        '_obstacle_count',
        '_start_point',
        '_end_point',
    ]

    _fields_and_field_types = {
        'obstacle_points': 'sequence<double>',
        'obstacle_count': 'int64',
        'start_point': 'sequence<double>',
        'end_point': 'sequence<double>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.obstacle_points = array.array('d', kwargs.get('obstacle_points', []))
        self.obstacle_count = kwargs.get('obstacle_count', int())
        self.start_point = array.array('d', kwargs.get('start_point', []))
        self.end_point = array.array('d', kwargs.get('end_point', []))

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
        if self.obstacle_points != other.obstacle_points:
            return False
        if self.obstacle_count != other.obstacle_count:
            return False
        if self.start_point != other.start_point:
            return False
        if self.end_point != other.end_point:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def obstacle_points(self):
        """Message field 'obstacle_points'."""
        return self._obstacle_points

    @obstacle_points.setter
    def obstacle_points(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'obstacle_points' array.array() must have the type code of 'd'"
            self._obstacle_points = value
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
                "The 'obstacle_points' field must be a set or sequence and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._obstacle_points = array.array('d', value)

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
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'obstacle_count' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._obstacle_count = value

    @builtins.property
    def start_point(self):
        """Message field 'start_point'."""
        return self._start_point

    @start_point.setter
    def start_point(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'start_point' array.array() must have the type code of 'd'"
            self._start_point = value
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
                "The 'start_point' field must be a set or sequence and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._start_point = array.array('d', value)

    @builtins.property
    def end_point(self):
        """Message field 'end_point'."""
        return self._end_point

    @end_point.setter
    def end_point(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'end_point' array.array() must have the type code of 'd'"
            self._end_point = value
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
                "The 'end_point' field must be a set or sequence and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._end_point = array.array('d', value)


# Import statements for member types

# Member 'result_points'
# already imported above
# import array

# already imported above
# import builtins

# already imported above
# import math

# already imported above
# import rosidl_parser.definition


class Metaclass_RRTSPoints_Response(type):
    """Metaclass of message 'RRTSPoints_Response'."""

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
                'apf_interfaces.srv.RRTSPoints_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__rrts_points__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__rrts_points__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__rrts_points__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__rrts_points__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__rrts_points__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class RRTSPoints_Response(metaclass=Metaclass_RRTSPoints_Response):
    """Message class 'RRTSPoints_Response'."""

    __slots__ = [
        '_result_points',
        '_point_count',
    ]

    _fields_and_field_types = {
        'result_points': 'sequence<double>',
        'point_count': 'int64',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.result_points = array.array('d', kwargs.get('result_points', []))
        self.point_count = kwargs.get('point_count', int())

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
        if self.result_points != other.result_points:
            return False
        if self.point_count != other.point_count:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def result_points(self):
        """Message field 'result_points'."""
        return self._result_points

    @result_points.setter
    def result_points(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'result_points' array.array() must have the type code of 'd'"
            self._result_points = value
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
                "The 'result_points' field must be a set or sequence and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._result_points = array.array('d', value)

    @builtins.property
    def point_count(self):
        """Message field 'point_count'."""
        return self._point_count

    @point_count.setter
    def point_count(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'point_count' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'point_count' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._point_count = value


class Metaclass_RRTSPoints(type):
    """Metaclass of service 'RRTSPoints'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('apf_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'apf_interfaces.srv.RRTSPoints')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__rrts_points

            from apf_interfaces.srv import _rrts_points
            if _rrts_points.Metaclass_RRTSPoints_Request._TYPE_SUPPORT is None:
                _rrts_points.Metaclass_RRTSPoints_Request.__import_type_support__()
            if _rrts_points.Metaclass_RRTSPoints_Response._TYPE_SUPPORT is None:
                _rrts_points.Metaclass_RRTSPoints_Response.__import_type_support__()


class RRTSPoints(metaclass=Metaclass_RRTSPoints):
    from apf_interfaces.srv._rrts_points import RRTSPoints_Request as Request
    from apf_interfaces.srv._rrts_points import RRTSPoints_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
