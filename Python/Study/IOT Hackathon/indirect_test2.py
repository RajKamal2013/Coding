import random
import os

from iotbackup.lib.IncoreIndirects import S2CIndBlock, S2CIndirects


def test5():
    L1_ind = S2CIndirects(97, 4)
    for i in range(255):
        p = i
        v = i
        L1_ind.put_blk(p, v)


    obj = L1_ind.getInd_blk()
    vbns = obj.wib_data.wib_vbns64

    obj1 = vbns[1]
    path = os.getcwd()
    f = open("byte_.txt", "wb")
    f.write(bytes(obj1))
    f.close()
    #for item in vbns:
     #   print("p", item.pvbn)
     #   print("v", item.vvbn)