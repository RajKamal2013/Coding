from PvPair import *
class OnDiskIndirect:
    entry = []

    def __init__(self):
        self.entry=[]
    def add(self, P=None, V=None):
        pair = pv(P, V)
        self.entry.append(pair)
    def get(self):
        return self.entry

