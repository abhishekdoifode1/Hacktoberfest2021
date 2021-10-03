# Rabin-Karp algorithm in python


d = 10
def check(pattern,text,si):
    #print(si)
    i=0
    while i<len(pattern) and pattern[i]==text[si]:
        i+=1 
        si+=1
    if i==len(pattern):
        return True
    return False
    

def search(pattern, text, q):
    m=len(pattern)
    n=len(text)
    ts=0
    ps=0
    ph=0
    th=0

    for i in range(m):
        ps+=ord(pattern[i])

    ph = ps%q
    #print(ph)
    #print()


    for i in range(m):
        ts+=ord(text[i])
    th=ts%q
    if th==ph:
        if check(pattern,text,0):
            return 1


    for i in range(m,n):
        ts-=ord(text[i-m])
        #print(i)
        ts+=ord(text[i])
        
        th= ts%q
        #print(th)
        if th==ph:
            
            if check(pattern,text,m):
                return m+1
    return 'No values found'
    




text = "ABCCDDAEFG"
pattern = "AFG"
q = 10

ans=search(pattern, text, q)
print(ans)