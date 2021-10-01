#Program for validating a password to create a strong password
#Password is validated only if it is 7 characters long and has 2 numbers , 2 special characters
ch=0 #Counts total no of characters in the given password
n=0 #Counts number of digits
sch=0 #Counts number of special characters
valid="False" #Shows the status of password
while(valid=="False"):
    Password=input("Enter the password:")
    password=Password.lower() #As the password does not consider upper and lowercase characters separately,it makes counting letters easier
    passList=list(password)
    for i in range(len(passList)):#Counts the number of digits , characters and special characters
        if(ord(passList[i])>=48)and(ord(passList[i])<=57):
            n+=1 
        elif(ord(passList[i])>=97)and(ord(passList[i])<=122):
            ch+=1
        else:
            sch+=1
    if (len(passList)>=7):
        if(n>=2)and(sch>=2):
            print("Valid password")
            valid="True"
        else:
            print("Invalid password...should contain atleast two numbers and two special characters..Try again")
            
    else:
        print("Invalid password...should have atleast 7 characters...try again")
        
        
