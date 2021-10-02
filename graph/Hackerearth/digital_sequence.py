#https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/digitial-sequence-ee0ea080/#c226080
n=int(input())
A=input().split()
c=[0]
for j in range(1,10):
    cnt=0
    for i in range(n):
        if str(j) in A[i]:
            cnt+=1
    c.append(cnt)
print(max(c))
