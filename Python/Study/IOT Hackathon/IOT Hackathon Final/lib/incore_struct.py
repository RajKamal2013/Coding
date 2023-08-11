# This file contains the structure definitions of all incore structures required to convert
# local filesystem data to C2C format

import time
import enum
import ctypes

# Common header for any metaadata block.
class inofileEmbeddedHdr:
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


class hdrType(enum.Enum):
    S2C_EMBEDDED_HDR_TYPE_INVALID = 0
    S2C_EMBEDDED_HDR_TYPE_INOFILE = 1
    S2C_EMBEDDED_HDR_TYPE_DIRECTORY = 2
    S2C_EMBEDDED_HDR_TYPE_ACL = 3
    S2C_EMBEDDED_HDR_TYPE_QTREE_METAFILE = 4
    S2C_EMBEDDED_HDR_TYPE_LUN_SYS_ATTRS = 5
    S2C_EMBEDDED_HDR_TYPE_LUN_NAMED_ATTRS  = 6
    S2C_EMBEDDED_HDR_TYPE_VTOC_BPLUS = 7
    S2C_EMBEDDED_HDR_TYPE_VTOC_APP_HDR = 8
    S2C_EMBEDDED_HDR_TYPE_I2P = 9
    S2C_EMBEDDED_HDR_TYPE_MAX = 10


# Inofile Clasees starts here.....
class inofileHdr:
    ehdr = inofileEmbeddedHdr(hdrType.S2C_EMBEDDED_HDR_TYPE_INOFILE)
    baseInum = ctypes.c_uint32
    entSize = ctypes.c_uint16
    numUsed = ctypes.c_uint8
    spare = ctypes.c_uint8

    #def __init__(self):
    # define constructor
    # def getInofileHdr(self):
    #def other related methods.
    def __init__(self):
        self.ehdr = inofileEmbeddedHdr(hdrType.S2C_EMBEDDED_HDR_TYPE_INOFILE)
        self.baseInum = 0
        self.entSize = 0
        self.numUsed = 0

class inodeCred:
    uid = ctypes.c_uint32 # userid of file
    gid = ctypes.c_uint32 # group id of file


class inofileEntry:
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

    #def --init, methods.

time.time
class inofileL0Blk:
    hdr = inofileHdr
    n = 14 # find exact count for list of entries
    entries = [inofileEntry() for __ in  range(n)]

# Inofile classes end here.

class S2CObjectFields():
    '''
    Contains object structure and APIs to read/write to S2C object
    '''
    S2CObjectCount = 1024
    S2CObjectHdrSize = 36
    S2CObjectElemSize = 4096

class S2CObjectOnDisk():
    '''
    Contains the definition of ondisk S2CObject that would be given
    as input to create_blob_from_bytes
    '''
    def __init__(self):
        self.S2CObjectHdr = [-1] * S2CObjectFields.S2CObjectHdrSize * S2CObjectFields.S2CObjectCount #36K
        self.S2CObjectData = [-1] * S2CObjectFields.S2CObjectElemSize * S2CObjectFields.S2CObjectCount #4MB


class S2CObject():
    fields = S2CObjectFields()
    data = S2CObjectOnDisk()

class CloudPvbn():
    cpvbn = 0
    def __init__(self) :
        self.cpvbn = 0

    def getCPvbn(self) :
        return self.cpvbn

    def getNextCPvbn(self) :
        self.cpvbn = self.cpvbn + 1  # type: blks_t
        return self.cpvbn
