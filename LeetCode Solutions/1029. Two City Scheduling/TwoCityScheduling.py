class Solution:
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        FirstCity = [i for i,j in costs] #Flying everyone to one city
        Diff = [j - i for i,j in costs]  #Evaluating Differences when sent to another city
        # Now we choose the smallest differences and calculated the total after sending the half to another city
        return sum(FirstCity) + sum(sorted(Diff)[:len(costs)//2])  
