'''
Printing all subsets of an array
eg:= 
i/p = [1,2]
o/p = ('' ,'1' ,'2' ,'12')

'''

def solve(inp ,op):
    if len(inp)==0:
        print(f'Subset is -> {op}')
        return
    op1 = op
    op2 = inp[0]+op
    inp = inp[1:]
    solve(inp,op1)
    solve(inp,op2)
    
if __name__=='__main__':
    arr = list(map(int,input("Enter an Array ")))
    inp = ''.join(str(a) for a in arr)
    op = ''
    solve(inp,op)