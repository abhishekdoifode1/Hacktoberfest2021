def reverse_for_loop(s):
s1 = ''
for c in s:
s1 = c + s1
return s1
my_number = '123456'
if __name__ == "__main__":
print('Reversing the given number using for loop =', reverse_for_loop(my_number)
