import ctypes
c_uint32 = ctypes.c_uint32

class directoryNameBitFields(ctypes.LittleEndianStructure):
        _fields_ = [("entryNameType", c_uint32, 4),
                    ("entryNameLen", c_uint32, 12),
                    ("padding", c_uint32, 16)
        ]

class directoryName():
        nameBitFields = directoryNameBitFields()
        entryName = []

class directoryBitFields(ctypes.LittleEndianStructure):
        _fields_ = [
            ("entrySize", c_uint32, 12),
            ("nameOffset", c_uint32, 6),
            ("entryIndex", c_uint32, 8),
            ("numNames", c_uint32, 6),
            ("inodeNum", c_uint32, 32),
            ("inodeGen", c_uint32, 32),
            ("fgIndex", c_uint32, 32),
            ("fgFileType", c_uint32, 32),
            ("nameInfoFlag", c_uint32, 8),
        ]

class directoryEntry():
        bitFields = directoryBitFields()
        nameInformation = directoryName()


