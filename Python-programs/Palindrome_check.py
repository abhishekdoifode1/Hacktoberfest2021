#to check weather the given number is a palindrome number or not
#palindrome number is a number which equal to it's reverse
num=int(input("Enter the number to be checked: "))          #taking input
temp=num                                                    #storing number in a temporary vaariable called temp
remainder=0
reverse=0
#calculating reverse using while loop
while num>0:
    remainder=num%10
    reverse=(reverse*10)+remainder
    num=int(num/10)
#checking if the number is equal to it's reverse
if reverse==temp :
    print(temp,"is a palindrome")
elif temp<0 :
    print("Please enter a positive number")
else :
    print(temp,"is a not palindrome")
    