

class Employee:
    def __init__(self, name = " ", degree= " ", id = -1):
        self.name = name
        self.degree = degree
        self.id = id

    def __str__(self):
        str  = "Name:" + self.name + " Degree:" + self.degree
        return str


class Employees:
    def __init__(self):
        self.directory = dict()

    def __str__(self):
        for k, v in self.directory.items():
            data = data + Employee + "\n"

        return data

    def add(self, person:Employee):
        self.directory[person.id] = person

    def search(self, id:int):
        try:
            return self.directory[id]
        except KeyError:
            print("This key does not exist in the dictionary")
            return None

    @staticmethod
    def test(id):
        ret = True
        if (ret == None):
            print("Item does not exist")
        else:
            print ("Employee exist ", ret)


def main():
    emp1 = Employee("Raj", "B-Tech", 1)
    emp2 = Employee("Kamal", "B-Tech", 2)
    company = Employees()
    company.add(emp1)
    company.add(emp2)
    id = 1
    Employees.test(id)
    id = 3
    Employees.test(id)


main()
