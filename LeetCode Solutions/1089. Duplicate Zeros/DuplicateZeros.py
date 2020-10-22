class Solution:
    def duplicateZeros(self, arr: List[int]) -> None:
        i=0
        while i<len(arr):
            if arr[i]!= 0:
                i+=1
            else:
                arr.insert(i+1,0)
                i+=2
                arr.pop()
                
        
       
