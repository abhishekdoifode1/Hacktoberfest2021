'''
Lowest Common Subsequence := Are the common words in both strings

eg := string1 = 'abcdsdwe' , string2 = 'acdwear'
o/p = 5 (acdwe)

'''

def mem_lcs(s1 , s2 , n ,m , t):
    if n ==0 or m==0:
        return 0
    if t[n][m] != -1:
        return t[n][m]
    
    if s1[n-1]==s2[m-1]:
        t[n][m] = 1 + mem_lcs(s1 , s2 , n-1 , m-1 , t)
        return t[n][m]
    else:
        t[n][m] = max(mem_lcs(s1 , s2 , n-1 , m , t) , mem_lcs(s1 , s2 , n , m-1 , t))
        return t[n][m]



def recursive_lcs(s1 , s2 , n ,m):
    if n ==0 or m==0:
        return 0
    if s1[n-1]==s2[m-1]:
        return 1+recursive_lcs(s1 , s2 , n-1 , m-1)
    else:
        return max(recursive_lcs(s1 , s2 , n-1 , m) , recursive_lcs(s1 , s2 , n , m-1))
    
def top_down_lcs(text1,text2,n,m):
    t = [[0 for _ in range(m+1)] for _ in range(n+1)]
    for i in range(1,n+1):
        for j in range(1,m+1):
            if text1[i-1] == text2[j-1]:
                t[i][j] = 1+t[i-1][j-1]
            else:
                t[i][j] = max(t[i-1][j] ,t[i][j-1])
                    
    return t[n][m]  

s1 = input('Enter String 1 :- ')
s2 =  input("enter String 2:- ")
n = len(s1)
m = len(s2)
t = [[-1 for _ in range(m+1)] for _ in range(n+1)]


print("LCS is ", top_down_lcs(s1,s2,n,m))
print("LCS is ", recursive_lcs(s1,s2,n,m))
