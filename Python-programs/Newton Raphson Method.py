def f(x):
    return x**4-x-10
def f1(x):
    return 4*x**3-1

#initial guess
x0=float(input())
#tolerance - Something like 1e-5, 1e-3, etc
e=float(input())
c=0
print('x0\tf(x0)\tf1(x0)\tx1')
while c<5:
    c+=1
    x1=x0-f(x0)/f1(x0)
    print('%.3f\t%.3f\t%.3f\t%.3f'%(x0,f(x0),f1(x0),x1))
    x0=x1
#Converged root
print(x1)
