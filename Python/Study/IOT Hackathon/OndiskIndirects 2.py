from PvPair import *

from iotbackup.lib.PvPair import pv


class OnDiskIndirect:
    entry = []

    def __init__(self):
        self.entry=[]
    def add(self, P=None, V=None):
        pair = pv(P, V)
        self.entry.append(pair)
    def get(self):
        return self.entry

