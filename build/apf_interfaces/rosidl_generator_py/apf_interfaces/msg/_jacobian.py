# generated from rosidl_generator_py/resource/_idl.py.em
# with input from apf_interfaces:msg/Jacobian.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'flat_jacobian'
# Member 'flat_jacobian5'
# Member 'flat_jacobian3'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Jacobian(type):
    """Metaclass of message 'Jacobian'."""

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
                'apf_interfaces.msg.Jacobian')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__jacobian
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__jacobian
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__jacobian
            cls._TYPE_SUPPORT = module.type_support_msg__msg__jacobian
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__jacobian

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Jacobian(metaclass=Metaclass_Jacobian):
    """Message class 'Jacobian'."""

    __slots__ = [
        '_flat_jacobian',
        '_col_num',
        '_flat_jacobian5',
        '_col_num5',
        '_flat_jacobian3',
        '_col_num3',
    ]

    _fields_and_field_types = {
        'flat_jacobian': 'sequence<double>',
        'col_num': 'int32',
        'flat_jacobian5': 'sequence<double>',
        'col_num5': 'int32',
        'flat_jacobian3': 'sequence<double>',
        'col_num3': 'int32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.flat_jacobian = array.array('d', kwargs.get('flat_jacobian', []))
        self.col_num = kwargs.get('col_num', int())
        self.flat_jacobian5 = array.array('d', kwargs.get('flat_jacobian5', []))
        self.col_num5 = kwargs.get('col_num5', int())
        self.flat_jacobian3 = array.array('d', kwargs.get('flat_jacobian3', []))
        self.col_num3 = kwargs.get('col_num3', int())

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
        if self.flat_jacobian != other.flat_jacobian:
            return False
        if self.col_num != other.col_num:
            return False
        if self.flat_jacobian5 != other.flat_jacobian5:
            return False
        if self.col_num5 != other.col_num5:
            return False
        if self.flat_jacobian3 != other.flat_jacobian3:
            return False
        if self.col_num3 != other.col_num3:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def flat_jacobian(self):
        """Message field 'flat_jacobian'."""
        return self._flat_jacobian

    @flat_jacobian.setter
    def flat_jacobian(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'flat_jacobian' array.array() must have the type code of 'd'"
            self._flat_jacobian = value
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
                "The 'flat_jacobian' field must be a set or sequence and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._flat_jacobian = array.array('d', value)

    @builtins.property
    def col_num(self):
        """Message field 'col_num'."""
        return self._col_num

    @col_num.setter
    def col_num(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'col_num' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'col_num' field must be an integer in [-2147483648, 2147483647]"
        self._col_num = value

    @builtins.property
    def flat_jacobian5(self):
        """Message field 'flat_jacobian5'."""
        return self._flat_jacobian5

    @flat_jacobian5.setter
    def flat_jacobian5(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'flat_jacobian5' array.array() must have the type code of 'd'"
            self._flat_jacobian5 = value
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
                "The 'flat_jacobian5' field must be a set or sequence and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._flat_jacobian5 = array.array('d', value)

    @builtins.property
    def col_num5(self):
        """Message field 'col_num5'."""
        return self._col_num5

    @col_num5.setter
    def col_num5(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'col_num5' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'col_num5' field must be an integer in [-2147483648, 2147483647]"
        self._col_num5 = value

    @builtins.property
    def flat_jacobian3(self):
        """Message field 'flat_jacobian3'."""
        return self._flat_jacobian3

    @flat_jacobian3.setter
    def flat_jacobian3(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'flat_jacobian3' array.array() must have the type code of 'd'"
            self._flat_jacobian3 = value
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
                "The 'flat_jacobian3' field must be a set or sequence and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._flat_jacobian3 = array.array('d', value)

    @builtins.property
    def col_num3(self):
        """Message field 'col_num3'."""
        return self._col_num3

    @col_num3.setter
    def col_num3(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'col_num3' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'col_num3' field must be an integer in [-2147483648, 2147483647]"
        self._col_num3 = value
