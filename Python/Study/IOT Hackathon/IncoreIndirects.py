from PvPair import *
import threading
from threading import Thread, Lock
import ctypes
from ctypes import *

from iotbackup.lib.PvPair import WaflDualVBN64, vbn48, pv


class Ind64(ctypes.Structure):
    __pack__ = 1
    _fields_ = [("wit_CP_count", ctypes.c_uint32),
                ("wit_fbn", ctypes.c_uint64, 48),
                ("wit_version", ctypes.c_uint8)
                ]

class Ind32(ctypes.Structure):
    _fields_ = [("wit_fbn", vbn48),
               ("wit_CP_count", ctypes.c_uint32),
               ("wit_spare1", ctypes.c_uint8),
               ("wit_version", ctypes.c_uint8)
               ]

class Indirect(ctypes.Union):
        __pack__ = 1
        _fields_ = [("ind64", Ind64),
                    ("ind32", Ind32)
                    ]


class WaflIndirectTrailer(ctypes.Structure):
    __pack__ = 1
    _fields_ = [("wit_magic", ctypes.c_int32),
                ("u", Indirect),
                ("wit_indirect_type", ctypes.c_uint8)
                ]

class WaflIndirectInfo(ctypes.LittleEndianStructure):
    __pack__ = 1
    _fields_ = [("wib_level", ctypes.c_uint32),
                ("wib_fid", ctypes.c_uint32),
                ("wib_parentID", ctypes.c_uint64)
                ]

class WaflIndSpares(ctypes.LittleEndianStructure):
    __pack__ = 1
    _fields_ = [("wib_spares", c_char * 1020)]

class S2CIndirectBlock(ctypes.LittleEndianStructure):
    __pack__ = 1
    _fields_ = [("wib_vbns64",  WaflDualVBN64 * 255),
                ("wib_trailer", WaflIndirectTrailer),
                ("wib_spares", WaflIndSpares)
                ]

class S2CIndBlock(ctypes.Union):
    __pack__ = 1
    _fields_ = [("wib_data", S2CIndirectBlock),
                ("buf", ctypes.c_char * 4096)
                ]

class S2CIndirects:
    wib_vbns64 = [] * 255
    wib_trailer = WaflIndirectTrailer()
    wib_info = WaflIndirectInfo()
    wib_spares = WaflIndSpares()
    wib_idx = -1
    IndBlk = S2CIndirectBlock()
    IndirectBlk = S2CIndBlock()


    def __init__(self, level=None, fileId=None):
        self.wib_vbns64 = [] * 255
        self.wib_idx = 0
        self.wib_info.wib_level = level
        self.wib_info.wib_fid = 23
        self.wib_info.wib_parentId = -1
        self.wib_trailer.wit_magic = 0xffffff34
        self.wib_trailer.wit_indirect_type = level
        self.wib_trailer.u.ind64 = Ind64()
        self.wib_trailer.u.ind64.wit_CP_count = 2
        self.wib_trailer.u.ind64.wit_vbn = 2
        self.wib_trailer.u.ind64.wit_version = 2
        self.wib_spares = WaflIndSpares()
        self.IndBlk.wib_trailer = self.wib_trailer
        self.IndBlk.wib_spares = self.wib_spares
        self.IndirectBlk = S2CIndBlock()


    def put_blk(self, p=None, v=None):
        blk = WaflDualVBN64()
        blk.pvbn = p
        blk.vvbn = v
        self.wib_vbns64.insert(self.wib_idx, blk)
        self.IndBlk.wib_vbns64[self.wib_idx] = blk
        self.wib_idx = self.wib_idx + 1

    def get_idx(self):
        idx = self.wib_idx
        return idx

    def put_blk_idx(self, p= None, v= None, idx = None):
        self._mutex = threading.Lock()
        self._mutex.acquire()
        blk = WaflDualVBN64()
        blk.pvbn = p
        blk.vvbn = v
        self.wib_vbns64.insert(self.wib_idx, blk)
        self._mutex.release()

    def get(self):
        return self.wib_vbns64

    def getInd_blk(self):
        #IndBlk = S2CIndirectBlock()
        #idx = 0
        #for idx in range(self.wib_idx):
        #    IndBlk.wib_vbns64[idx] = self.wib_vbns64[idx]
        #IndBlk.wib_trailer = self.wib_trailer
        #IndBlk.wib_spares =  self.wib_spares
        #IndirectBlk = S2CIndBlock()
        self.IndirectBlk.wib_data = self.IndBlk
        return self.IndirectBlk

class waflIndirectBlock:
    IndirectName=" "
    fileID = ctypes.c_uint32
    parentID = ctypes.c_uint32
    fileName=""
    blkCount=ctypes.c_uint32
    index=ctypes.c_uint
    trailer = WaflIndirectTrailer

    def __init__(self, Lname = None, LfileId = None, Lcount=None, LparentId=None, LfileName=None):
        self.IndirectName = Lname
        self.fileID = LfileId
        self.parentId = LparentId
        self.fileName = LfileName
        if (Lcount == None):
            self.blkCount = c_int(255)
        else:
            self.blkCount = Lcount
        self.index = 0
        self.entry=[]

    def getCurrentIndex(self):
        self._mutex = threading.RLock()
        self._mutex.acquire()
        curr_index = self.index;
        self._mutex.release()
        return curr_index

    def putData(self, data_index, p, v):
        self._mutex = threading.Lock()
        self._mutex.acquire()
        self.index = data_index
        pair = pv(p, v)
        self.entry.insert(self.index, pair)
        self._mutex.release()

    def put(self, p, v):
        self._mutex.acquire()
        self.index = self.index + 1
        pair = pv(p,v)
        self.entry.append(self.index, pair)
        self._mutex.release()



