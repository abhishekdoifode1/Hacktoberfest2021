T=int(input())
for _ in range(T):
    n=int(input())
    l=sorted(list(map(int,input().split())))
    count=0
    for a in range(n-1):
        count+=l[a]
    if count>l[-1]:
        print("Yes")
    else:
        print("No")
