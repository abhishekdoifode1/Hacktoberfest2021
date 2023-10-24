n=int(input())
for i in range(n):
    brackets = input()
    stack=[]
    dictt={'(':')', '[':']', '{':'}'}
    flag=0
    for b in brackets:
        #print(stack)
        if (len(stack)==0) and b in dictt.values():
            flag=1
            break
        elif (len(stack)==0) or b in dictt.keys():
            stack.append(b)
        else: 
            if (b in dictt.values()) and (b == dictt[stack[-1]]):
                del stack[-1]
 
    if len(stack)==0 and flag!=1:
        print("YES")
    else:
        print("NO")
