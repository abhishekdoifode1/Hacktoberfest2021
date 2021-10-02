#https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/monk-and-rotation-3/
for _ in range(int(input())):
    n,k=map(int,input().split())
    k=k%n
    A=input().split()
    B=A[-k:n+1]
    for i in range(k):
        A.pop(-1)
    B=B+A
    print(' '.join(B))
