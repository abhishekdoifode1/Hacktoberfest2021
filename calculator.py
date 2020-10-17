a = int(input())
b = int(input())

choice = input("select:\n 1 for addition\n 2 for subtraction\n 3 for multiplication\n 4 for division\n")

if(choice == "1"):
    print("a+b=" , a+b)

if(choice == "2"):
    print("a-b=" , a-b)

if(choice == "3"):
    print("a*b=", a*b)

if(choice == "4"):
    if(b != 0):
        print("a/b=", a/b)
        print("a%b=", a%b)
    else:
        print("dividing by 0 not possible!")
