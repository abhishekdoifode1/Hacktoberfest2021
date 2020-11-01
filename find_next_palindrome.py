def palindrome(number):
    return  number == number[::-1]

if  __name__ == '__main__':
    init = int(input())
    number = init + 1
    while not palindrome(str(number)):
        number += 1
    print(number - init)