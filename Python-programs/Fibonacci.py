# value of n
n = int(input("Enter n : "))

# n-1 value
sum1 = 0
# n-2 value
sum2 = 0

sum = sum1 + sum2

# Fibonacci Series print
for i in range(1, n+1):
    if(i == 1):
        sum1 = 1
        print('1', end=' ')
    else:
        sum = sum1 + sum2
        sum2 = sum1
        sum1 = sum
        print(sum, end=' ')
print()
