import random
import sys

listword=["hello","computer","python","java","html","world","apple","windows"]

guessword=[]
random_word=random.choice(listword)
lenghtword=len(random_word)
alphabet="abcdefghijklmnopqrstuvwxyz"
letter_storage=[]

def intro():
	print("\tHello and Welcome to Hangman (A word prediction game)")
	
	while True:
		name=input("Enter your name:\n").strip()
		if name=="":
			print("Enter a valid name\n")
		else:
			break
	print("\n\t\tSo %s  welcome to the Game :) " % name)
intro()

def game():

	while True:
		String=input("So you ready to play :\n ")
		if String=="yes" or String=="Y" or String=="y":
			break
		elif String=="No" or String=="N" or String=="n":
			sys.exit()
		else:
			print("Please Enter something ")
			continue
game()

def rules():

    for character in random_word: 
                guessword.append("_")
		
    print("Ok, so the word You need to guess has", lenghtword, "characters")

    print("Be aware that You can enter only 1 letter from a-z\n\n")

    print(guessword)

def guessing():
	guess_no=1
	while guess_no<10:
		guess=input("\nPick a letter : ")
		if not guess in alphabet:
			print("pick a letter from a-z ")
			
		elif guess in letter_storage:
			print("Already guessed this letter.")
		else:
		
			letter_storage.append(guess)
			if guess in random_word:
				print("You guessed correctly")
				for x in range(0,lenghtword):
					if random_word[x]==guess:
						guessword[x]=guess
				print(guessword)
				if not '_' in guessword:
					print("You won")
					break
			else:
				print("Guessed letter not in the word")
				guess_no+=1
				if guess_no==10:
					print("Sorry, you have used all your chances. YOU LOST !!")

rules()
guessing()

print("\tGAME OVER !! ")


# By: Darsh Asawa (https://github.com/DarshAsawa)
	
		
