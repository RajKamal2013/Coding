class ty:
    t=0
    z=1

    def __init__(self):
        print("Hi")

    def sett(self):
        self.t = 4

    def gett(self):
        return self.t


def te():
    p = ty()
    print("initial -> ", p.gett())
    p.sett();
    print("Later -> ", p.gett())

te()
