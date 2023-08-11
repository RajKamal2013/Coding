from PvPair import *
from IncoreIndirects import *
from OndiskIndirects import *
import random
import pickle
import codecs
import base64
import ctypes
from struct import Struct
from ctypes import *
import os
import sys

from iotbackup.lib.IncoreIndirects import S2CIndBlock
from iotbackup.lib.OndiskIndirects import OnDiskIndirect


class directoryNameBitFields(ctypes.LittleEndianStructure):
    _fields_ = [("entryNameType", c_uint32, 4),
            ("entryNameLen", c_uint32, 12),
            ("padding", c_uint32, 16)
            ]

class Packet(Union):
    _fields_ = [("bits", directoryNameBitFields),
                ("binary_data",ctypes.c_uint32)]


def test5():
    L1_ind = S2CIndBlock(97, "t.txt", 4)
    for i in range(2):
        p = random.getrandbits(48)
        v = random.getrandbits(48)
        L1_ind.put_blk(p, v)

    data = L1_ind.get()
    print(data)
    path = os.getcwd()
    block = bytearray(data)
    print(block)
    # f = open("byte_Data.txt", "wb")
    # f.write(bytearray(data))

def test4():
    packet = Packet()
    packet.bits.entryNameType = 0b1011
    packet.bits.entryNameLen = 0b000000111111
    packet.bits.padding = 0b0101010101011111

def test3():
    temp = directoryNameBitFields()
    temp.entryNameType = 0b1010
    temp.entryNameLen = 0b000000111111
    temp.padding = 0b0101010101011111
    MyStruct = Struct('B')

    d = memoryview(temp)
    #print(d)

    #data = MyStruct.pack(temp.entryNameType, temp.entryNameLen, temp.padding)
    #data = MyStruct.pack(temp)
    #print(data)
    #print(MyStruct.unpack(data))

    bin_dump = pickle.dumps(temp)
    b64_dump = codecs.encode(bin_dump, 'base64')
    b64_extract = base64.decodebytes(b64_dump)
    temp2 = pickle.loads(b64_extract)


    #print(bin(bin_dump))
    #print(bin(b64_dump))
    #print(b64_extract)

    #print(bin(temp2.entryNameType))
    #print(bin(temp2.entryNameLen))
    #print(bin(temp2.padding))

def test():
    ind = OnDiskIndirect()
    for i in range(255):
        p = random.getrandbits(64)
        v = random.getrandbits(64)
        ind.add(p,v)

    data = ind.get()
    #for item in data:
    #    print(p, ", ", v)
    #    print("    ")

def test1():
    L1_ind = S2CIndBlock(97, "t.txt", 4)
    for i in range(255):
        p = random.getrandbits(48)
        v = random.getrandbits(48)
        L1_ind.put_blk(p,v)

    bin_dump = pickle.dumps(L1_ind)
    b64_dump = codecs.encode(bin_dump, 'base64')
    b64_extract = base64.decodebytes(b64_dump)
    L1_ind_Extract = pickle.loads(b64_extract)

    #print("Obj", L1_ind)
    #print("BinDump ", bin_dump)
    #print("B64 dump", b64_dump)
    #print("B64 extract", b64_extract)
    #print("object extracted", L1_ind_Extract)

    #print("Before Serialize")
    data = L1_ind.get()
    for i in range(2):
        c = bytes(data[i])
       # print("P ->", data[i].pvbn)
       # print("V ->", data[i].vvbn)


    #print("After Serialize")
    data = L1_ind_Extract.get()
    for i in range(2):
        c = bytes(data[i])
    #    print("Byte : ", c[2])
    #    print("Byte array", c)
    #    print("size = ", sizeof(data[i]))
    #    print("P ->", data[i].pvbn)
    #    print("V ->", data[i].vvbn)




test5()




