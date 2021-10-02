"""
No. of ways to generate subset sum
Github Username :- @Anishukla
"""

x = int(input())
A = list(map(int, input().split()))

def waysSubsetSum(A, x):
    arr = [[0 for i in range(x+1)] for j in range(len(A)+1)]
    
    for j in range(len(A)+1):
        arr[j][0] = 1
        
    val = 0
        
    for i in range(1, len(A)+1):
        val= val + A[i-1]
        for j in range(1, (x+1)):
            if j<=val and A[i-1] == j-A[i-1]:
                arr[i][j] = arr[i-1][j] + arr[i][j-A[i-1]] -1
            
            elif j<=val:
                arr[i][j] = arr[i-1][j] + arr[i][j-A[i-1]]
                
            else:
                arr[i][j] = arr[i-1][j]
                
    return arr[-1][-1]

print(waysSubsetSum(A, x))
