# # Time Complexity: Primality

#     A prime is a natural number greater than  that has no positive divisors other than  and itself. Given  integers, determine the primality of each integer and print whether it is Prime or Not prime on a new line.

#     Note: If possible, try to come up with an  primality algorithm, or see what sort of optimizations you can come up with for an  algorithm. Be sure to check out the Editorial after submitting your code!

#     Function Description
#         Complete the primality function in the editor below. It should return Prime if  is prime, or Not prime.
#         primality has the following parameter(s):
#         n: an integer to test for primality

#     Input Format
#         The first line contains an integer, , denoting the number of integers to check for primality.
#         Each of the  subsequent lines contains an integer, , the number you must test for primality.

#     Output Format
#         For each integer, print whether  is Prime or Not prime on a new line.

#     Sample Input
#         3
#         12
#         5
#         7

#     Sample Output
#         Not prime
#         Prime
#         Prime

#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the primality function below.


def primality(n):
    if (n < 2):
        return "Not prime"
    if (n == 2 or n == 3 or n == 5 or n == 7):
        return "Prime"

    for i in range(2, (int)(math.sqrt(n))+1):
        if (n % i == 0):
            return "Not prime"

    return "Prime"


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    p = int(input())

    for p_itr in range(p):
        n = int(input())

        result = primality(n)

        fptr.write(result + '\n')

    fptr.close()
