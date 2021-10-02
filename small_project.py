def play():
    import random
    guessesTaken=0
    print("Hello!What is your name?")
    name=input()
    num=random.randint(1,10)
    while guessesTaken<6:
        print("Take a guess.")
        guess=int(input())
        guessesTaken=guessesTaken+1
        if guess>num:
            print("Your guess is too low.")
        elif guess>num:
            print("Your guess is too high.")
        else:
            break
        if guessesTaken==6:
            print("out of moves")
        if guess==num:
            guessesTaken=str(guessesTaken)
            print("Good job, "+name+" !You guessed my number in "+guessesTaken+" guesses!")
        if guess !=num:
            num=str(num)
            print("Nope. The number i was thinking of was "+num)
        again=input("play again : ")
        if again=='yes':
            play()
        else:
            exit()
        Play()
