def KMPSearch(pattern, text): 
    M = len(pattern) 
    N = len(text) 
  
    
    lps = [0]*M 
    j = 0
  
    compute(pattern, M, lps) 
  
    i = 0  
    while i < N: 
        if pattern[j] == text[i]: 
            i += 1
            j += 1
  
        if j == M: 
            print ("Found pattern at index " + str(i-j)) 
            j = lps[j-1] 
  
        elif i < N and pattern[j] != text[i]: 
            if j != 0: 
                j = lps[j-1] 
            else: 
                i += 1
  
def compute(pattern, M, lps): 
    len = 0  
  
    lps[0] 
    i = 1

    while i < M: 
        if pattern[i]== pattern[len]: 
            len += 1
            lps[i] = len
            i += 1
        else: 
            if len != 0: 
                len = lps[len-1] 

            else: 
                lps[i] = 0
                i += 1
    
    for k in range(0,len(lps)):
        print(k,end=" ")
    print()            
    
    for i in lps:
        print(i,end=" ")
    print()
        
# Main Program
                
text = "ABCDABCDACBDBDA"
pattern = "AB"
KMPSearch(pattern, text) 