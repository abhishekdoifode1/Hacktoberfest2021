"""
Find maximum sum of contigous subarray in an array.
This problem can be solved with Kadane's Algorithm.
In this python program  we will implement Kadane's Algorithm.
"""

"""
Input: an array of integers (can be negative also)
Output: Maximum sum of contigous subarray in the array.

Example:
Input: [2, 3, -1, -9, 1, 0, 7, -2, 11]
Output: 17

Explanation:
Selected contigous subarray is [1, 0, 7, -2, 11].
So, sum = 1+0+7+(-2)+11 = 17

"""

import math

def max_subArray_sum(arr):
    # Function implementation of Kadane's Algorithm

    
    final_max_sum = -math.inf
    max_sum_till_now = 0

    for val in arr:
        max_sum_till_now += val
        final_max_sum = max(final_max_sum, max_sum_till_now)
        max_sum_till_now = max(max_sum_till_now, 0)
    return final_max_sum

arr = list(map(int, input().split()))
print(max_subArray_sum(arr))
