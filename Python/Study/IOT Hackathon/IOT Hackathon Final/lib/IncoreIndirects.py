from PvPair import *
import threading
from threading import Thread, Lock
import ctypes
from ctypes import *


class Ind64(Structure):
    _fields_ = [("wit_CP_count", ctypes.c_uint32),
                ("wit_fbn", vbn48),
                ("wit_version", ctypes.c_uint8)
                ]

class Ind32(Structure):
    _fields_ = [("wit_fbn", vbn48),
               ("wit_CP_count", ctypes.c_uint32),
               ("wit_spare1", ctypes.c_uint8),
               ("wit_version", ctypes.c_uint8)
               ]

class ind(Union):
        _fields_ = [("ind64", Ind64),
                    ("ind32", Ind32)
                    ]


class WaflIndirectTrailer(Structure):
    _fields_ = [("wit_magic", ctypes.c_int32),
                ("u", ind),
                ("wit_indirect_type", ctypes.c_char_p)
                ]


class WaflIndirectInfo(Structure):
    _fields_ = [("wib_level", ctypes.c_uint32),
                ("wib_fid", ctypes.c_uint32),
                ("wib_fileName", ctypes.c_char_p),
                ("wib_parentID", ctypes.c_uint64)
                ]
"""
class WaflIndirectBlock(Structure):
    _fields_ = [("wib_vbns64", * 255),
                ("wib_trailer", WaflIndirectTrailer)
                ]
"""

class S2CIndBlock:
    wib_vbns64 = [] * 255
    wib_trailer =  WaflIndirectTrailer
    wib_info = WaflIndirectInfo
    wib_idx = -1

    def __init__(self, level=None, fileId=None, fileName= None, parentId=None):
        self.wib_vbns64 = [] * 255
        self.wib_idx = 0
        self.wib_info.wib_level = level
        self.wib_info.wib_fid = fileId
        self.wib_info.wib_fileName = fileName
        self.wib_info.wib_parentId = parentId
    def put_blk(self, p=None, v=None):
        self._mutex = threading.Lock()
        self._mutex.acquire()
        blk = WaflDualVBN64()
        blk.pvbn = p
        blk.vvbn = v
        #self.wib_vbns64.insert(self.wib_idx, blk)
        self.wib_vbns64.insert(self.wib_idx, blk)
        #self.wib_vbns64[self.wib_idx].vvbn = v
        self.wib_idx = self.wib_idx + 1
        self._mutex.release()

    def get_idx(self):
        self._mutex = threading.Lock()
        self._mutex.acquire()
        idx = self.wib_idx
        self._mutex.release()
        return idx

    def put_blk_idx(self, p= None, v= None, idx = None):
        self._mutex = threading.Lock()
        self._mutex.acquire()
        self.wib_vbns64[idx].pvbn = p
        self.wib_vbns64[idx].vvbn = v
        self._mutex.release()

    def get(self):
        return self.wib_vbns64


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
        #self._mutex = threading.Lock()

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



