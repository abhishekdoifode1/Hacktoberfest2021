t=int(input())
for _ in range(t):
    N,p,q,r=map(int,input().split())
    if (p==q or q==r or p==r) and p<N and q<N and r<N:
        print(0)
    else:
        count=0
        for  i in range(1,N+1):
            if (i%p==0 and i%q==0) or (i%q==0 and i%r==0) or (i%p==0 and i%r==0):
                continue
            elif i%p==0 or i%q==0 or i%r==0:
                count+=1
        print(count)
