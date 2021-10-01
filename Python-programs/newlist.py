t=int(input())
while(t>0):
    t=t-1
    n=int(input())
    a=input().split()
    for i in range(n):
        a[i]=int(a[i])
    b=[0]
    c=0
    d=0
    for i in range(-1,-n,-1):
        if(a[i]==a[i-1]):
            c=c+0
            d=d+1
            
        else:
            c=c+1+d
            d=0
        b.append(c)
    for i in range(-1,-n-1,-1)    :
      print(b[i],end=" ")
    print()  
        
