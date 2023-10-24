#https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/monk-and-welcome-problem/
from sys import stdin
n=int(input())
A=list(map(int,stdin.readline().split()))
B=list(map(int,stdin.readline().split()))
print(" ".join([str(A[i]+B[i]) for i in range(n)]))
