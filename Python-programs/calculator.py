import math

choice = input("select:\n 1 for addition\n 2 for subtraction\n 3 for multiplication\n 4 for division\n 5 for squareroot\n 6 for sin\n 7 for cos\n 8 for tan\n      ")

while True:

    if choice in ('1', '2', '3', '4'):
        a = float(input("Enter first number: "))
        b = float(input("Enter second number: "))

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
        
    next_calc = input("Would you like to perform another calculation? (yes/no) ").lower
    if next_calc == "no":
        break
    
    
if(choice == '5'):
    x = int(input("Enter the Number"))
    print("square root of number is:",math.squareroot(x))
    
elif(choice == '6'):
    x = int(input("Enter your Number: "))
    print(math.sin(x))
    
elif(choice == '7'):
    x = int(input("Enter your Number: "))
    print(math.cos(x))

elif(choice == '8'):
    x = int(input("Enter your Number: "))
    print(math.tan(x))

else:
    print("invalid input")
