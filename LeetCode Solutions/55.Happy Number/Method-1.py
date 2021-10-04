# Method-1

def isHappy(n):
    visit = set()
    
    while n not in visit:
        visit.add(n)
        n = sumOfSquare(n)
        
        if n == 1:
            return True
            
    return False
    
def sumOfSquare(n):
    result = 0
    
    while n:
        result += (n % 10) ** 2
        n //= 10
        
    return result
    
# Time Complexity : O(nlogn)
# Space Complexity : O(n)