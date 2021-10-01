# Program to check if a number is prime or not

# To take input from the user
num = int(input("Enter a number: "))
l=[]
for i in range(1,num+1):
   if num%i==0:
      l.append(i)
if len(l)==2:
   print(num,"is a prime number")
else:
   print(num,"is not a prime number")
