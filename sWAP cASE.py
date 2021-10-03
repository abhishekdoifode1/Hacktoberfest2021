def swap_case(s): //function to swap
    num = ""
    for let in s:
        if let.isupper() == True: //if character is upper case
            num+=(let.lower())
        else:
            num+=(let.upper()) //if character is lower case
    return num      //return swapped result 

if __name__ == '__main__':
    s = input()
    result = swap_case(s) //calling function to swap
    print(result)