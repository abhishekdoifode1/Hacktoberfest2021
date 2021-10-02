import random

secretNumber = random.randint(1, 20)
print("I have chosen a random number between 1 and 20")

for i in range(1, 7):
    guess = int(input("Guess my number : "))
    if guess < secretNumber:
        print("Your guess is too low")
    elif guess > secretNumber:
        print("Your guess is too high")
    else:
        break

if guess == secretNumber:
    print("Congratulations!!! You successfully guessed my number in "+str(i)+" guesses.")
else:
    print("Out of guesses!!! My number was "+str(secretNumber))
