'''
Recursive Staicarse := Count possible ways to reach ground floor if only 1 or 2 steps are allowed

i/p = 4 (No of steps)
o/p = 5 (No of all possible ways)

'''

#Recursive Solution
def rec_num_ways(n):
    if n<0:
        return 0
    if n==1 or n==0:
        return 1
    else:
        return rec_num_ways(n-1) + rec_num_ways(n-2)

# D-P Solution    
def dp_num_ways(n):
    if n==0 or n==1:
        return 1
    dp = [0] * (n+1)
    dp[0] = 1
    dp[1] =1
    for i in range(2,n+1):
        dp[i] = dp[i-1] + dp[i-2]
    
    return dp[n]

n = int(input("Enter Floor "))
print("Possible ways are ", rec_num_ways(n))
print("Possible ways are " , dp_num_ways(n))