import math

a = int(input("Please Enter First Number of an G.P Series: : "))
n = int(input("Please Enter the Total Numbers in this G.P Series: : "))
r = int(input("Please Enter the Common Ratio : "))

total = (a * (1 - math.pow(r, n ))) / (1- r)
tn = a * (math.pow(r, n - 1))

print("\nThe Sum of Geometric Progression Series = " , total)
print("The tn Term of Geometric Progression Series = " , tn)
