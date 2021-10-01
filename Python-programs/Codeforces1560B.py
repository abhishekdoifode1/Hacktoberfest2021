
for _ in range(int(input())):
    a,b,c = list(map(int,input().split()))
    x = abs(a-b)
    y = 2*x
    if (c+x<=y and c+x>=1) and c+x!=a and c+x!=b and max(a,b,c)<=y:
        print(c+x)
    elif c-x<=y and c-x>=1 and c-x!=a and c-x!=b and max(a,b,c)<=y:
        print(c-x)
    else:
        print(-1)