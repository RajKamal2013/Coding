def swap(a, b):
    print("Before swapping a= ", a, " b=", b);
    a, b = b, a
    print("After swapping  a= ", a, " b= ", b);


def main():
    a = input("Enter a:")
    b = input("Enter b:")
    swap(a, b)


if __name__ == '__main__':
    main()
