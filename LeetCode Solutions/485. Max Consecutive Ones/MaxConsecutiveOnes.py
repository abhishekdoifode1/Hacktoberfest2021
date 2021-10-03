class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        
        cons_count=0
        max_count=0
        
        for i in nums:
            if i==1:
                cons_count+=1
            else :
                if(cons_count>max_count): 
                    max_count=cons_count  
                cons_count=0
                    
                        
        return max(max_count,cons_count)
