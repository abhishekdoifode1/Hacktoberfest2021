'''
Kadane's Algorithm is used to find the sum of contiguous subarray within an array of numbers with the largest sum. 
Consider an example:
l=[-2,-3,5,-1,-2,1,4,-3]
Here, the largest sum = 5 + (-1) + (-2) + (1) + (4) = 7
Hence, Maximum subarray sum = 7
'''

#Implementation
def maxSubArraySum(a,size): 
    max_so_far = -2**31   #initialize with minimum value
    max_ending_here = 0
      
    for i in range(0, size):
        max_ending_here = max_ending_here + a[i]
        if (max_so_far < max_ending_here):
            max_so_far = max_ending_here     #update value
 
        if max_ending_here < 0:
            max_ending_here = 0      #look for positive values
    return max_so_far    #final answer

a=list(input())
size=len(a)
print "Maximum subarray sum = ", maxSubArraySum(a,size)

'''
Time Complexity = O(n) as the array is traversed only once
Space Complexity = O(1) since no extra space is used
'''