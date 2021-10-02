# This program performs palindrome check for a string #
# function which return reverse of a string
def isPalindrome(s):
# Calling reverse function
    if (len(s) <= 1) :
        return True
    if s[0] == s[len(s) - 1] :
        return isPalindrome(s[1:len(s) - 1])
    else :
        return False

# Driver code edit in code
'''
Palindrome_input_Variable = [ ' AnnA ' , ' SoloS ' , ' RotatoR ' , ' RadaR ' , ' SagaS ' , ' RotoR ' , ' TenT ' , ' RepapeR ' , ' CiviC ' , ' KayaK ' , ' Lever ' , ' MadaM ' , ' RacecaR ' , ' StatS ' , ' Redder ' , ' Wow ' , ' MoM ' , ' RefeR ' , ' NooN '] 
print( " PALINDROME CHECK PROGRAM " )
for i in Palindrome_input_Variable:
    ans = isPalindrome(i)
    if ans == 1:
        print( " The given string  ", "'" , i , "' ","is a palindrome")
    else:
        print( " The given string  " , "'" , i , "' ","is not a palindrome")
'''

#Driver code to Access via CLI
response =True
while(response):
    print('\n\n\n ------------------------------------------------------------------------------------------------')
    print("Enter the string you want to check :")
    user_input = input()
    m=isPalindrome(user_input)
    if m ==True:
        print('\n ********** The word is a Palindrom **********')
    else:
        print('\n*******The word you entered is NOT a Palindrome *********')
    print('\n Would you like to check another string? \n 1. Yes \n 2. No')
    k=input()
    if k=='Yes' or k=='yes' or k=='1' :
        response= True
    else:
        response= False
