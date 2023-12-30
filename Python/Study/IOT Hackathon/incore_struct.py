# This file contains the structure definitions of all incore structures required to convert
# local filesystem data to C2C format

import time
import enum
import ctypes
from ctypes import *

# Common header for any metaadata block.
from lib.PvPair import dualPV, vbn48, WaflDualVBN64

from iotbackup.lib.IncoreIndirects import S2CIndBlock


class S2CInofileEmbeddedHdr(ctypes.LittleEndianStructure):
    ebhType = ctypes.c_uint8
    majorVersion = ctypes.c_uint8
    minorVersion = ctypes.c_uint8
    spares = ctypes.c_uint8

    def __init__(self, type):
        self.ebhType = type
        self.majorVersion = 1
        self.minorVersion = 1
        self.spares = 1
    def setValues(self, type):
        self.ebhType = type
    def getValues(self):
        return self.ebhType

# Inofile Clasees starts here.....

class t64class(ctypes.LittleEndianStructure):
    __fields__ = [
        ("pvbn64", vbn48 * 10),
        ("spares", ctypes.c_uint8 * 4)
    ]


class d64class(ctypes.LittleEndianStructure):
    __fields__ = [
        ("vbns64", WaflDualVBN64 * 5),
        ("spares", ctypes.c_uint8 * 4)
    ]


class S2CInodeIndirectBlock(ctypes.LittleEndianStructure):
    __fields__ = [
        ("vbn32", dualPV * 8),
        ("t64", t64class ),
        ("d64", d64class)
    ]


class S2CInofileHdr(ctypes.LittleEndianStructure):
    ehdr = S2CInofileEmbeddedHdr(1) ### right now hard coding it for inofile.
    baseInum = ctypes.c_uint32
    entSize = ctypes.c_uint16
    numUsed = ctypes.c_uint8
    spare = ctypes.c_uint8


class inodeCred(ctypes.LittleEndianStructure):
    uid = ctypes.c_uint32 # userid of file
    gid = ctypes.c_uint32 # group id of file


class S2CInofileEntry(ctypes.LittleEndianStructure):
    index = ctypes.c_uint8
    startOffset = ctypes.c_uint32
    endOffset = ctypes.c_uint32
    version = ctypes.c_uint8

    #ondisk info here copied in below members
    type     = ctypes.c_uint8
    subtype = ctypes.c_uint8
    blkInitFunc = ctypes.c_uint8
    iofInfo = ctypes.c_uint8
    perm = ctypes.c_uint16
    avGenNum = ctypes.c_uint16
    tid = ctypes.c_uint32
    nlink = ctypes.c_uint32
    xinode = ctypes.c_uint32
    sinode = ctypes.c_uint32
    generations = ctypes.c_uint32
    diskflags = ctypes.c_int64
    logicalSize = ctypes.c_int64
    spnParenDirInode = ctypes.c_uint32
    spnCookie = ctypes.c_uint32
    aTime = ctypes.c_int64(time.time_ns())
    mTime = ctypes.c_int64(time.time_ns())
    cTime = ctypes.c_int64(time.time_ns())
    crtTime = ctypes.c_int64(time.time_ns())
    cred = inodeCred()
    wiib = S2CInodeIndirectBlock()
    #def --init, methods.

class S2CInofileL0(ctypes.LittleEndianStructure):
    __fields__ = [
        ("hdr" , S2CInofileHdr),
        ("entries", S2CInofileEntry *14)
    ]

# Inofile classes end here.

# Fsinfo Classes
class S2CFsinfo():
    spares = ctypes.c_char[4096]

class S2CUserL0:
    data = ctypes.c_char[4096]

class S2CObjectFields():
    '''
    Contains object structure and APIs to read/write to S2C object
    '''
    S2CSlotCount = 1024
    S2CObjectHdrSize = 36
    S2CObjectElemSize = 4096

class S2CObjectHdr(Structure):
    spares = ctypes.c_char[S2CObjectFields.S2CObjectHdrSize]

class S2CObjectData:
    spares = ctypes.c_char[S2CObjectFields.S2CObjectElemSize]

class S2CCloudObject():
    '''
    Contains the definition of ondisk S2CObject that would be given
    as input to create_blob_from_bytes
    '''
    def __init__(self, type):
        self.hdr = [] * S2CObjectFields.S2CSlotCount
        self.data = [] * S2CObjectFields.S2CSlotCount
        self.curIdx = 0
        self.type = type

    def putSlotInCloudObj(self, hdr, data):
        self.hdr.insert(self.curIdx, hdr)
        self.data.insert(self.curIdx, data)
        self.curIdx = self.curIdx + 1
        assert(self.curIdx < S2CObjectFields.S2CSlotCount)

    def getCurIdx(self):
        return self.curIdx

class S2CObject():
    fields = S2CObjectFields()
    data = S2CCloudObject()


class S2CDirL0(object):
    pass


class S2CObjectSlot(Union):
    _fields_ = [("userL0", S2CUserL0),
              #  ("ind", S2CIndBlock),
              #  ("dirL0", S2CDirL0),
                ("inofileL0", S2CInofileL0),
                ("fsinfo", S2CFsinfo)]

class CloudPvbn():
    cpvbn = 0
    def __init__(self) :
        self.cpvbn = 0

    def getCPvbn(self) :
        return self.cpvbn

    def getNextCPvbn(self) :
        self.cpvbn = self.cpvbn + 1  # type: blks_t
        return self.cpvbn

