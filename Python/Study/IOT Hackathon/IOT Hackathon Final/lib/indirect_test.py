from PvPair import *
from IncoreIndirects import *
from OndiskIndirects import *
import random


def test():
    ind = OnDiskIndirect()
    for i in range(255):
        p = random.getrandbits(64)
        v = random.getrandbits(64)
        ind.add(p,v)

    data = ind.get()

    for item in data:
        print(p, ", ", v)
        print("    ")

def test1():
    L1_ind = S2CIndBlock(97, "t.txt", 4)
    for i in range(255):
        p = random.getrandbits(48)
        v = random.getrandbits(48)
        L1_ind.put_blk(p,v)

    data = L1_ind.get()

    for i in range(255):
        print("P ->", data[i].pvbn)
        print("V ->", data[i].vvbn)


test1()


