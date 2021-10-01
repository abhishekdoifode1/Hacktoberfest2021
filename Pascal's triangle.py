#Pascal's triangle

class Solution:
    def generate(self, r: int) -> List[List[int]]:
        if r == 1:
            return [[1]]
        res = [[1],[1,1]]
        for i in range(2, r):
            m = [res[i-1][j-1]+res[i-1][j] for j in range(1, i)]
            m.insert(0, 1)
            m.append(1)
            res.append(m)   
        return res
