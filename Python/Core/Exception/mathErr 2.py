

def add(a:int, b:int) -> int:
    return a + b 

def divide(a:int, b:int) -> int: 
    try:
        c =  a/b
    except Exception as ex:
        print("Exception Occured: ", ex)
        raise ex

def divide1(a:int, b:int) -> int: 
    c =  a/b

def calculate(op:str, a:int, b:int) -> int:
    if (op == "add"):
        return add(a, b)
    elif (op ==  "divide"):
        return (a/b)

def test():
    a = 5
    b = 0
    c = 0
    try:
        c= divide(a, b)
    except Exception as ex:
        print("Exception Occured in Test: ", ex)
        b = 10
        c = divide(a, b)
    finally:
        print("Divide:", c)

def main():
    test()

main()