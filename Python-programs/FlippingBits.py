# # Flipping Bits
#     You will be given a list of 32 bit unsigned integers. Flip all the bits ( and ) and print the result as an unsigned integer.

#     Function Description
#         Complete the flippingBits function in the editor below. It should return the unsigned decimal integer result.

#     flippingBits has the following parameter(s):
#         n: an integer

#     Input Format
#         The first line of the input contains the number of queries.
#         Each of the next  lines contain an integer to process.


#     Output Format
#         Output one line per element from the list with the decimal value of the resulting unsigned integer.

#     Sample Input 0
#         3
#         2147483647
#         1
#         0

#     Sample Output 0
#         2147483648
#         4294967294
#         4294967295


#     Sample Input 1
#         2
#         4
#         123456

#     Sample Output 1
#         4294967291
  
#         4294843839


#     Sample Input 2
#         3
#         0
#         802743475
#         35601423

#     Sample Output 2
#         4294967295
#         3492223820
#         4259365872

# !/bin/python

import math
import os
import random
import re
import sys

# Complete the flippingBits function below.
def flippingBits(n):
    num = [0 for x in range(32)]
    i = 0
    while(n != 0):
        num[i] = n % 2
        i = i + 1 
        n /= 2
    res = 0
    base = 1
    for i in range(32):
        if (num[i] == 0):
            res = res + base
        base = base * 2
    return res

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(raw_input())

    for q_itr in xrange(q):
        n = int(raw_input())

        result = flippingBits(n)

        fptr.write(str(result) + '\n')

    fptr.close()
