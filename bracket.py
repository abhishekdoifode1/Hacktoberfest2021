# Python3 program to check if two expressions
# evaluate to same.
MAX_CHAR = 26;

# Return local sign of the operand. For example,
# in the expr a-b-(c), local signs of the operands
# are +a, -b, +c
def adjSign(s, i):
if (i == 0):
	return True;
if (s[i - 1] == '-'):
	return False;
return True;

# Evaluate expressions into the count vector of
# the 26 alphabets.If add is True, then add count
# to the count vector of the alphabets, else remove
# count from the count vector.
def eval(s, v, add):

# stack stores the global sign
# for operands.
stk = []
stk.append(True);

# + means True
# global sign is positive initially
i = 0;

while (i < len(s)):

	if (s[i] == '+' or s[i] == '-'):
	i += 1
	continue;
	
	if (s[i] == '('):
	
	# global sign for the bracket is
	# pushed to the stack
	if (adjSign(s, i)):
		stk.append(stk[-1]);
	else:
		stk.append(not stk[-1]);
	
	# global sign is popped out which
	# was pushed in for the last bracket
	elif (s[i] == ')'):
	stk.pop();
	else:
	
	# global sign is positive (we use different
	# values in two calls of functions so that
	# we finally check if all vector elements
	# are 0.
	if (stk[-1]):
		v[ord(s[i]) - ord('a')] += (1 if add else -1) if adjSign(s, i) else (-1 if add else 1)
	
	# global sign is negative here
	else:
		v[ord(s[i]) - ord('a')] += (-1 if add else 1) if adjSign(s, i) else (1 if add else -1)
	
	i += 1

# Returns True if expr1 and expr2 represent
# same expressions
def areSame(expr1, expr2):

# Create a vector for all operands and
# initialize the vector as 0.
v = [0 for i in range(MAX_CHAR)];

# Put signs of all operands in expr1
eval(expr1, v, True);

# Subtract signs of operands in expr2
eval(expr2, v, False);

# If expressions are same, vector must
# be 0.
for i in range(MAX_CHAR):
	if (v[i] != 0):
	return False;
return True;

# Driver Code
if __name__=='__main__':
expr1 = "-(a+b+c)"
expr2 = "-a-b-c";
if (areSame(expr1, expr2)):
	print("Yes");
else:
	print("No");

	# This code is contributed by rutvik_56.
