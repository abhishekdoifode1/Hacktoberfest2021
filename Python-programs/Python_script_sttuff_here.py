#!/bin/python3

import math
import os
import random
import re
import sys
import string

symbols_low = string.ascii_lowercase
symbols_up = string.ascii_uppercase

def caesarCipher(s, k):
    res = []
    for c in s:
        if c.isupper():
            res.append(symbols_up[(symbols_up.index(c)+k)%len(symbols_up)])
        elif c.islower():
            res.append(symbols_low[(symbols_low.index(c)+k)%len(symbols_low)])
        else:
            res.append(c)
                       
    return "".join(map(str, res))
    
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    s = input()

    k = int(input().strip())

    result = caesarCipher(s, k)

    fptr.write(result + '\n')

    fptr.close()
