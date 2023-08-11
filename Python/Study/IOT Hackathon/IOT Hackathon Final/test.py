#from lib.PvPair import *
#from lib.IncoreIndirects import *
from lib.PvPair.py import *
from lib.IncoreIndirects.py import *
if __name__ == '__main__':
    id  = pv(2, 3)
    print(id.getV(), id.getP())
    obj = InCoreIndirect("L1", 12, 255, 1, "t.txt")
    obj.putData(0, 2, 3)
    print("Current Index :", obj.getCurrentIndex())

