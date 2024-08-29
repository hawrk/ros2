# generated from rosidl_generator_py/resource/_idl.py.em
# with input from service_interface_ws:srv/BlackMonkey.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_BlackMonkey_Request(type):
    """Metaclass of message 'BlackMonkey_Request'."""

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
            module = import_type_support('service_interface_ws')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'service_interface_ws.srv.BlackMonkey_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__black_monkey__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__black_monkey__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__black_monkey__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__black_monkey__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__black_monkey__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class BlackMonkey_Request(metaclass=Metaclass_BlackMonkey_Request):
    """Message class 'BlackMonkey_Request'."""

    __slots__ = [
        '_hit_type',
        '_injury',
    ]

    _fields_and_field_types = {
        'hit_type': 'int32',
        'injury': 'uint32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.hit_type = kwargs.get('hit_type', int())
        self.injury = kwargs.get('injury', int())

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
        if self.hit_type != other.hit_type:
            return False
        if self.injury != other.injury:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def hit_type(self):
        """Message field 'hit_type'."""
        return self._hit_type

    @hit_type.setter
    def hit_type(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'hit_type' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'hit_type' field must be an integer in [-2147483648, 2147483647]"
        self._hit_type = value

    @builtins.property
    def injury(self):
        """Message field 'injury'."""
        return self._injury

    @injury.setter
    def injury(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'injury' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'injury' field must be an unsigned integer in [0, 4294967295]"
        self._injury = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_BlackMonkey_Response(type):
    """Metaclass of message 'BlackMonkey_Response'."""

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
            module = import_type_support('service_interface_ws')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'service_interface_ws.srv.BlackMonkey_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__black_monkey__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__black_monkey__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__black_monkey__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__black_monkey__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__black_monkey__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class BlackMonkey_Response(metaclass=Metaclass_BlackMonkey_Response):
    """Message class 'BlackMonkey_Response'."""

    __slots__ = [
        '_beat',
        '_real_injury',
        '_words',
    ]

    _fields_and_field_types = {
        'beat': 'boolean',
        'real_injury': 'uint32',
        'words': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.beat = kwargs.get('beat', bool())
        self.real_injury = kwargs.get('real_injury', int())
        self.words = kwargs.get('words', str())

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
        if self.beat != other.beat:
            return False
        if self.real_injury != other.real_injury:
            return False
        if self.words != other.words:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def beat(self):
        """Message field 'beat'."""
        return self._beat

    @beat.setter
    def beat(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'beat' field must be of type 'bool'"
        self._beat = value

    @builtins.property
    def real_injury(self):
        """Message field 'real_injury'."""
        return self._real_injury

    @real_injury.setter
    def real_injury(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'real_injury' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'real_injury' field must be an unsigned integer in [0, 4294967295]"
        self._real_injury = value

    @builtins.property
    def words(self):
        """Message field 'words'."""
        return self._words

    @words.setter
    def words(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'words' field must be of type 'str'"
        self._words = value


class Metaclass_BlackMonkey(type):
    """Metaclass of service 'BlackMonkey'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('service_interface_ws')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'service_interface_ws.srv.BlackMonkey')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__black_monkey

            from service_interface_ws.srv import _black_monkey
            if _black_monkey.Metaclass_BlackMonkey_Request._TYPE_SUPPORT is None:
                _black_monkey.Metaclass_BlackMonkey_Request.__import_type_support__()
            if _black_monkey.Metaclass_BlackMonkey_Response._TYPE_SUPPORT is None:
                _black_monkey.Metaclass_BlackMonkey_Response.__import_type_support__()


class BlackMonkey(metaclass=Metaclass_BlackMonkey):
    from service_interface_ws.srv._black_monkey import BlackMonkey_Request as Request
    from service_interface_ws.srv._black_monkey import BlackMonkey_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
