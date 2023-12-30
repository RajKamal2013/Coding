import ctypes
c_uint32 = ctypes.c_uint32

class Flags_bits(ctypes.LittleEndianStructure):
    _fields_ = [
            ("logout", c_uint32, 3),
            ("userswitch", c_uint32, 2),
            ("suspend", c_uint32, 2),
            ("idle", c_uint32, 2),
        ]

class Flags(ctypes.Union):
    _fields_ = [("b", Flags_bits),
                ("asbyte", c_uint32)]

flags = Flags()
flags.asbyte = 0xffff

print(flags.b.idle)
print(flags.b.suspend)
print(flags.b.userswitch)
print(flags.b.logout)