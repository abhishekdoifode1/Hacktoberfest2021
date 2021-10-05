def palindrome(word):
  if word[::1] == word:
    print("Yes, word is palindrome")
  else:
    print("No, word is not palindrome")
    
word = input("Enter your word : ")
palindrome(word)
