#Lagrange's Interpolation
#Uses the fact that (x-x1)(x-x2)(x-x3)....(x-xn) = x^n - s1*x^n-1 + s2*x^n-2 ....... + sn where
# s1= (x1 + x2 + ... + xn) (Sum taken one at a time)
# s2= (x1*x2 + x1*x3 + x1*x4 + ....+ xn-1*xn) (Sum taken two at a time) and so on

def f(x,eq):
    fx=0
    n=len(eq)
    for i in range(n):
        fx+=(eq[i]*(x**(n-i-1)))
    return fx

from itertools import combinations #To get all possible combinations of an array 
n=int(input("Enter no. of points in the data set : "))
x=[]
y=[]

for i in range(n):
    x.append(int(input()))
    y.append(int(input())) 

eq=[0 for x in range(n)]

for i in range(n):
    x1=x.copy()
    p=1
    o=x1[i]
    del x1[i]
    for j in range(n-1):
        p*=(o-x1[j])
    coeff=[1]
    for j in range(1,n):
        comb=list(combinations(x1,j))
        s=0
        for k in range(len(comb)):
            prod=1
            for l in range(len(comb[k])):
                prod*=comb[k][l]
            s+=prod
        s*=((-1)**j)
        coeff.append(s)
    for j in range(len(coeff)):
        coeff[j]/=p
        coeff[j]*=y[i]
        eq[j]+=coeff[j]
        
print("The curve on which the given points lie on is : ",end='')

for i in eq:
    n-=1
    if i==0:
        continue
    elif i>0:
        print("+{}x^{}".format(i,n),end=' ')      
    else:
        print("{}x^{}".format(i,n),end=' ')