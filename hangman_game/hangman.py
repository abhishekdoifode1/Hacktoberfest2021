import random,time

name=input(" Hi! Enter your name here:")

print("\n Let's play "+name+" !")

time.sleep(1)
print("\n We have only fruits to guess in this game! Easy Right!")

words=["pear", "mango", "apple", "banana", 'apricot', 'pineapple','cantaloupe', 'grapefruit','jackfruit','papaya',"pomegranate","guava","litchi"]

word=random.choice(words)

time.sleep(1)
print("\n ---Guess the letters in the word---")

guesses= ""

chances = 14

while chances > 0:

    #counts the number of times the player fails
    failed=0

    for letter in word:
        if letter in guesses:
            print(letter)
        
        else:
            print("_")
            failed+=1
        
    if failed==0:
      
        print("\n YAY! YOU WIN")
        print("\n The word is: "+word)
        break
    
    
    guess=input("\n Guess a character :")

    guesses += guess

    if guess not in word:

        chances -= 1
        
        print("\n Wrong guess")
        print("\n You have only, "+ str(chances)," more guesses left now.")

        if chances == 0:
            print("\n OOPS! YOU LOST")


#END

