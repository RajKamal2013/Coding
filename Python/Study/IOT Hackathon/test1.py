import ctypes
import os
import random
import struct

from iotbackup.lib.PvPair import vbn48


def test1():
    buffer=bytearray()
    var1 = ctypes.c_int16
    var2 = ctypes.c_int32
    var = ctypes.c_char
    path = os.getcwd()
    f = open("byte_.txt", "wb")
    pvbn = ctypes.c_uint64
    pvbn1 = 100000000
    pvbn2 = 34000

    p = 1108152157446
    print()
    print("hex ", hex(p))
    print()
    buf = struct.pack("hi", ((p & 0xffff00000000)>>32) , (p & 0x0000ffffffff))
    print("Is Buffer ", buf)
    f.write(buf)

    #var = pvbn1 & 0xff0000000000
    #buf = struct.pack("<b", var)
    #print(var)
    #f.write(buf)
    #buffer.extend(buf)

    #var = ctypes.c_byte(pvbn1 & 0x00ff00000000).value
    #buf = struct.pack("<b", var)
    #print(var)
    #f.write(buf)
    #buffer.extend(buf)

    #var = ctypes.c_byte(pvbn1 & 0x0000ff000000).value
    #buf = struct.pack("<b", var)
    #print(var)
    #f.write(buf)
    #buffer.extend(buf)

    #var = ctypes.c_byte(pvbn1 & 0x000000ff0000).value
    #buf = struct.pack("<b", var)
    #print(var)
    #f.write(buf)
    #buffer.extend(buf)

    #var = ctypes.c_byte(pvbn1 & 0x00000000ff00).value
    #buf = struct.pack("<b", var)
    #print(var)
    #f.write(buf)
    #buffer.extend(buf)

    #var = ctypes.c_byte(pvbn1 & 0x0000000000ff).value
    #buf = struct.pack("<b", var)
    #print(var)
    #f.write(buf)
    #buffer.extend(buf)




    #var2 = ctypes.c_int(pvbn1&0xffffffff0000).value
    #buf = struct.pack(">i", var2)
    #f.write(buf)
    #buffer.extend(buf)
    #var1 = ctypes.c_short(pvbn1&0x00000000ffff).value
    #buf = struct.pack("<h", var1)
    #f.write(buf)
    #buffer.extend(buf)

    #buf = struct.pack("ih", pvbn1 & 0x00000000ffff, pvbn1 & 0xffffffff0000)

    #buf = struct.pack("<i", pvbn2 & 0xffffffff0000)
    #f.write(buf)
    #buffer.extend(buf)
    #buf = struct.pack(">h", pvbn2 & 0x00000000ffff)
    #f.write(buf)
    #buffer.extend(buf)

    #buf = struct.pack("<ih", pvbn2 & 0xffffffff0000, pvbn2 & 0x00000000ffff)
    #print(buf)
    #f.write(buf)
   # f.write(buffer)
    f.close()



test1()