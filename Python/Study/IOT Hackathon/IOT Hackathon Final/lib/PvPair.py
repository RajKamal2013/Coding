import ctypes
from ctypes import *

class WaflDualVBN64(Structure):
    _fields_ = [("pvbn", ctypes.c_uint64, 48),
                ("vvbn", ctypes.c_uint64, 48)
                ]

class vbn48(Structure):
    _fields_ = [("pvbn", ctypes.c_uint64, 48)]


class WaflDualVbn64Array(Array):
        _type_ = WaflDualVBN64
        _length_ = 255

class pv:
    p=("pvbn", ctypes.c_uint64, 48)
    v=("vvbn", ctypes.c_uint64, 48)
    def __init__(self, P=0, V=0):
        self.p = P
        self.v = V
    def setPV(self, P=0, V=0):
        self.p = P
        self.v = V
    def getP(self):
        return self.p
    def getV(self):
        return self.v

class dualPV:
    p = ctypes.c_uint32
    v = ctypes.c_uint32
    def __init__(self, P=0, V=0):
        self.p = P
        self.v = V
