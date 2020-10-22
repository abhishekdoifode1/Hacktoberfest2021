class Solution:
    def sortedSquares(self, A: List[int]) -> List[int]:
        squared=[]
        for i in A:
            squared.append(i**2)
            
        squared.sort()
        return squared
         
