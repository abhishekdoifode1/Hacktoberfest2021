# Program to find wether a number is perfect or not.

# A perfect number is a positive integer that is equal to the sum of its positive divisors excluding the number itself.

# Eg - 6 is a Perfect Number beacuse its factors are (1, 2 and 3) and 1 + 2 + 3 = 6

# Program
# Define the Function
def perfect_number(num):
  
    # Initialise sum with 0
    sum = 0
    
    # For loop to find the factors, excluding the number itself.
    for i in range(1, num):
      
        # Check if i is a factor by validating if the remainder is 0.
        if num % i == 0:
          
            # Add it to the sum variable.
            sum += i
    
    # Check and return the solution.
    return sum == num

  
print(perfect_number(6))  # True
