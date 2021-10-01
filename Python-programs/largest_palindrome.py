i = 100
j = 100
product = 1
largest_palindrome = 0

while i < 1000:
    j = i
    while j < 1000:
        product = i * j
        if str(product) == str(product)[::-1]:
                if product > largest_palindrome:
                    largest_palindrome = product
        j += 1
    i += 1
        
print(largest_palindrome)
print('Done')
