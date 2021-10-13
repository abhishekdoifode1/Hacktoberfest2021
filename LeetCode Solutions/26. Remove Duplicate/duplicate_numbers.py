class Solution:
    def removeDuplicate(self, nums):
        output = []
        output.append(nums[0])
        for i in range(1, len(nums)):
            if(nums[i] == nums[i-1]):
                continue
            else:
                output.append(nums[i])
        print(output)


s = Solution()
s.removeDuplicate([1, 1])
