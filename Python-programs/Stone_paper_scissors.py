#Program for an interactive game of "rock paper scissors", player can play as many times as the player wants
from random import randint
things=["rock","paper","scissors"] #For the choices of AI
thingsP={"R":"rock","P":"paper","S":"scissors"} #For the choices of player , so that player,s choice can be displayed , makes game more interactive
a="Y"
P=0
C=0
while(a=="Y" or a=="y"):
    ch=input("Enter R for rock , P for paper and S for scissors:")
    ch=ch.upper()  #So that the game is not case-sensitive , will kill all the fun!
    pch=thingsP[ch]
    chAI=things[randint(0,2)] #Choice of the AI
    print("You chose",pch,"and AI chose",chAI) #Showing the choices of both the player and game
    if(chAI):
        if(ch=="R"): 
            if(chAI=="paper"):
                P-=1
                c=+1
                print("Oh no!!!You lost to AI!")
                print("AI's score:",C)
            elif(chAI=="scissors"):
                P+=1
                c=-1
                print("Yes!!!You beat the AI!")
                print("Your score:",P)
                print("AI's score:",C)
            else:
                print("Nothing happens")
                print("Your score:",P)
                print("AI's score:",C)
        elif(ch=="P"):
            if(chAI=="scissors"):
                P-=1
                c=+1
                print("Oh no!!!You lost to AI!")
                print("Your score:",P)
                print("AI's score:",C)
            elif(chAI=="rock"):
                P+=1
                c=-1
                print("Yes!!!You beat the AI!")
                print("Your score:",P)
                print("AI's score:",C)
            else:
                print("Nothing happens")
                print("Your score:",P)
                print("AI's score:",C)
        elif(ch=="S"):
            if(chAI=="rock"):
                P-=1
                c=+1
                print("Oh no!!!You lost to AI!")
                print("Your score:",P)
                print("AI's score:",C)
            elif(chAI=="paper"):
                P+=1
                c=-1
                print("Yes!!!You beat the AI!")
                print("Your score:",P)
                print("AI's score:",C)
            else:
                print("Nothing happens")
                print("Your score:",P)
                print("AI's score:",C)
    a=input("Play Again? Press n/N for no...else press Y/y  to continue:")  #Provides the choice for the player to play again as many times as they want
    

