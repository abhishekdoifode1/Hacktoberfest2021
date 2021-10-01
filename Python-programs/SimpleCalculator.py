import math

#Program will run as long as this is True
calc = True

#This list will store all user history statements till program is terminated
uHist = []

#This function will take user input at end of each operation to decide if code will be run again or program will be terminated
def YorN():
    global calc
    ans = str(input("\nContinue? (Y or N) ").upper())
    while ans not in ("N", "Y"):
        ans = str(input("\nUnrecognized input! Please enter Y to continue or N to quit: ").upper())
        continue
    if ans == "Y":
        calc = True
    elif ans == "N":
        calc = False

#Main body        
print("\nWelcome to the Calculator!")
while calc:

    print("\n---" + "Type " + "ADD " + "for addition.")
    print("---" + "Type " + "SUB " + "for subtraction.")
    print("---" + "Type " + "MUL " + "for multiplication.")
    print("---" + "Type " + "DIV " + "for division.")
    print("---" + "Type " + "MOD " + "for modulus.")
    print("---" + "Type " + "ABSO " + "for absolute value.")    
    print("---" + "Type " + "HIST " + "for usage history.")    
    print("---" + "Type " + "QUIT " + "to quit.")

    uInput = input("\nWhat do you want to do? ").upper()

    #For addition
    if uInput == "ADD":

        try:
            vals = list(map(float, input("\nPlease enter the numbers you want to add with a space in between each one: ").split()))
            ans = sum(vals)
            print("\nThe answer is: ", ans)
            uStatement = ["You added the numbers ", ", ".join(map(str, vals)), " and the answer was ", ans] #Creates a list which contains all parts of the user history statement, present for all operations
            uStr = ' '.join([str(elem) for elem in uStatement]) #Concatenates uStatement members into str to make printing easy
            uHist.append(uStr) #Appends uStr to uHist list
            YorN()

        except:     #This except block is present on every statement, to accomodate invalid inputs like string addition
            print("\nSomething went wrong!")
            YorN()

    #For subtraction            
    elif uInput == "SUB":

        try:
            val1 = float(input("\nPlease enter the number you want to subtract from: "))
            val2 = float(input("Please enter the number to be subtracted: "))
            ans = val1 - val2
            print("\nThe answer is: ", ans)
            uStatement = ["You subtracted ", val2, " from ", val1, " and the answer was ", ans]
            uStr = ' '.join([str(elem) for elem in uStatement])
            uHist.append(uStr)
            YorN()
                
        except:
            print("\nSomething went wrong!")
            YorN()
                
    #For multiplication
    elif uInput == "MUL":

        try:
            vals = list(map(float, input("\nPlease enter the numbers you want to multiply with a space in between each one: ").split()))
            ans = math.prod(vals)
            print("\nThe answer is: ", ans)
            uStatement = ["You multiplied the numbers ", ", ".join(map(str, vals)), " and the answer was ", ans]
            uStr = ' '.join([str(elem) for elem in uStatement])
            uHist.append(uStr)
            YorN()    
            
        except:
            print("\nSomething went wrong!")
            YorN()

    #For division            
    elif uInput == "DIV":

        try:
            val1 = float(input("\nPlease enter the dividend: "))
            val2 = float(input("Please enter the divisor: "))
            ans = round(val1/val2, ndigits = 2)
            uStatement = ["You divided ", val1, " by ", val2, " and the answer was ", ans]
            uStr = ' '.join([str(elem) for elem in uStatement])
            uHist.append(uStr)
            print("\nThe answer is: ", ans)
            YorN()

        except:
            print("\nSomething went wrong! Did you try to divide by zero?")
            YorN()

    #For python modulus operation
    elif uInput == "MOD":

        try:
            val1 = float(input("\nPlease enter the dividend: "))
            val2 = float(input("Please enter the divisor: "))
            ans = val1%val2
            print("\nThe answer is: ", ans)
            uStatement = ["You calculated modulus of the numbers ", val1, " and ", val2, " and the answer was ", ans]
            uStr = ' '.join([str(elem) for elem in uStatement])
            uHist.append(uStr)
            YorN()
                
        except:
            print("\nSomething went wrong!")
            YorN()

    #For absolute value
    elif uInput == "ABSO":

        try:
            val = float(input("\nPlease enter the number you want absolute for: "))
            ans = abs(val)
            print("\nThe answer is: ", ans)
            uStatement = ["You calculated absolute value of ", val, " and the answer was ", ans]
            uStr = ' '.join([str(elem) for elem in uStatement])
            uHist.append(uStr)
            YorN()

        except:
            print("\nSomething went wrong!")
            YorN()

    #For user history
    elif uInput == "HIST":

        try:
            if len(uHist) == 0:
                print("\nNo usage history so far.") #This is printed if user has not performed any task successfully yet
                YorN()
   
            else:
                print("\nHistory: ")
                print(*uHist, sep = "\n") #Prints every element of uHist array in new line
                YorN()
                
        except:
            print("\nSomething went wrong!")
            YorN()

    #This is in case user chooses to stop the program        
    elif uInput == "QUIT":
        break

    #Deals with invalid input for calculator features   
    else:
        print("\nUnrecognized input! Please enter an input from the listed inputs.")

