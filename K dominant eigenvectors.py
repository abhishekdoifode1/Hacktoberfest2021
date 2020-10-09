import numpy as np

n=int(input())
k=int(input())
a=[]
for i in range(n):
    a.append([])
    for j in range(n):
        a[i].append(int(input()))
a=np.array(a)
val,vec=np.linalg.eig(a)
val1=val.copy()
val=sorted(val,key=lambda x:abs(x),reverse=True)

for i in range(k):
    print(vec[:,np.where(val1==val[i])])
    print()