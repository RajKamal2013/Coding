from iot_directory_format import *

dirName = directoryName()
dirName.nameBitFields.entryNametype = 0x1
dirName.nameBitFields.entryNametype = 0x2
dirName.nameBitFields.entryNamelen = 0x128
dirName.entryName = 'foo'

dir = directoryEntry()
dir.bitFields.entrySize = 0x100
dir.bitFields.fgIndex = 0x10
dir.bitFields.nameOffset = 0x200
dir.nameInformation = dirName

print (dir.nameInformation.nameBitFields.entryNametype)
print (dir.nameInformation.nameBitFields.entryNamelen)
print (dir.nameInformation.entryName)