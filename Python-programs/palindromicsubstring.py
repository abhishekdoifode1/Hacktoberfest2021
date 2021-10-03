class Solution:
    def countSubstrings(self, s: str) -> int:
        ans = 0
        for i in range(2*len(s)-1):
            lo = i//2
            hi = lo + i%2
            while 0 <= lo <= hi < len(s) and s[lo] == s[hi]: lo, hi = lo-1, hi+1
            ans += (hi - lo)//2
        return ans 
