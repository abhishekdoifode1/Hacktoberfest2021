n = int(input("Number of terms? "))
a,b = 0, 1
c = 0
if n <= 0:
   print("Only positive integers are allowed")
elif n == 1:
   print("Fibonacci sequence till",n,":")
   print(a)
else:
   print("Fibonacci sequence is:")
   while c < n:
       print(a)
       nth = a + b
       a = b
       b = nth
       c += 1
