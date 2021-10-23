# Import string and random module
import random

# Randomly generate a ascii value
# from 'a' to 'z' and 'A' to 'Z'
randomLowerLetter = chr(random.randint(ord('a'), ord('z')))
randomUpperLetter = chr(random.randint(ord('A'), ord('Z')))
print(randomLowerLetter, randomUpperLetter)
