
## This file defines all the book keeping maps.
## usage:
"""
1. Create an object of InoFbnLevelToCVPN -> its a map for ino, fbn, level to cvpn mapping.
2. whenever assigns a new cvpbn, you will have ino fbn level ready with you
    create a object of keyGroupForIFLMap(ino, fbn, level).
    add it into map with maps
    lets say x = InoFbnLevelToCVPN()
    grp1 = keyGroupForIFLMap(96, 0, 0)
    x.addToMap(grp1, cvpn_value)

3. fetch value of cvpn for given group:
    grp2 = keyGroupForIFLMap(96, 0, 0)
    x.getcvpn(grp2) will return cvpbn

"""
class keyGroupForIFLMap:
    inode = 0
    fbn = 0
    level = 0
    def __init__(self, ino, fbn, lev):
        self.inode = ino
        self.fbn = fbn
        self.level = lev

    def getInodeFbnLevel(self):
        return self.inode, self.fbn, self.level

    def setInodeFbnLevel(self, ino, fbn, lev):
        self.inode = ino
        self.fbn = fbn
        self.level = lev

    def compare(self, key1):
        flag = 0
        if (key1.inode == self.inode) and (key1.fbn == self.fbn) and (key1.level == self.level):
            print("keys match")
            flag = 1

        return flag



class InoFbnLevelToCVPN:
    InoToCvpnMap = dict()

    ### this should have ["inode, fbn, level"] = cvpn mapping
    def addToMap(self, key, val):
        self.InoToCvpnMap[key] = val

    def getcvpn(self, x):
        for keys, value in self.InoToCvpnMap.items():
            if (keys.compare(x) == 1):
                value = self.InoToCvpnMap[keys]

        return value

