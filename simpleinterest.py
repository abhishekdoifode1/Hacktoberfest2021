# Python3 program to find simple interest 
# for given principal amount, time and 
# rate of interest. 


def simple_interest(p,t,r): 
	print('The principal is', p) 
	print('The time period is', t) 
	print('The rate of interest is',r) 
	
	si = (p * t * r)/100
	
	print('The Simple Interest is', si) 
	return si 


p_text = input ("Enter Principle: ")
p = int(p_text)

t_text = input ("Enter Time: ")
t = int(t_text)

r_text = input ("Enter Rate: ")
r = int(r_text)

simple_interest(p, t, r)

# Driver code 
# simple_interest(8, 6, 8) 
