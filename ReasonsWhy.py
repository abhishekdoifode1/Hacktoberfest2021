# Raghav is currently watching Netflix. He is feeling thrilled after watching Seasons 1, 2 and 3 of 13 Reasons Why, and is desperately waiting for release of Season 4. But the makers of the show are in no mood to release the next season anytime soon.

# The makers of 13 Reasons Why give Raghav a challenge to solve. If he solves this challenge, then they will give exclusive copy of Season 4 to him.

# But Raghav is feeling lazy. Can you help him solve this challenge?

# Given 3 integers A, B, C. Do the following steps-

# Swap A and B.
# Multiply A by C.
# Add C to B.
# Output new values of A and B.
# SAMPLE INPUT
# 13 5 2
# SAMPLE OUTPUT
# 10 15
# Explanation
# Steps-

# After swap, A = 5 and B = 13.
# A is multiplied by 2. So, A = 10.
# 2 is added to B. So, B = 15.


# Write your code here
B, A, C = [int(x) for x in input().split()]

print(A*C, end=" ")
print(B+C, end=" ")
