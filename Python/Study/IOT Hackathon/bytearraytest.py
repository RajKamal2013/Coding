import os
import random

from iotbackup.lib.IncoreIndirects import S2CIndBlock, sizeof


def test5():
    L1_ind = S2CIndBlock(97, "t.txt", 4)
    for i in range(2):
        p = random.getrandbits(48)
        v = random.getrandbits(48)
        L1_ind.put_blk(p, v)

    data = L1_ind.get()
    print()
    for item in data:
        print(sizeof(item))
        print(item.pvbn)
        print(item.vvbn)
    arr = bytearray()

    #print(data)
    path = os.getcwd()
    #block = bytearray(data)
    #print(block)
    # f = open("byte_Data.txt", "wb")
    # f.write(bytearray(data))

test5()