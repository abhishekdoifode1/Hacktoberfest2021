# import the random module
import random

def validate(hand):
    if hand < 0 or hand > 3:
        return False
    return True

def print_hand(hand, name='Guest'):
    hands = ['Rock', 'Paper', 'Scissors']
    print(name + ' picked: ' + hands[hand])

def judge(player, computer):
    if player == computer:
        return 'Draw'
    elif player == 0 and computer == 1:
        return 'Lost'
    elif player == 1 and computer == 2:
        return 'Lost'
    elif player == 2 and computer == 0:
        return 'Lost'
    else:
        return 'Won'

def main():
    print('Starting the Rock Paper Scissors game!')
    player_name = input('Please enter your name: ')
    player_hand = 0
    comp_score = 0
    player_score = 0
    while(player_hand !=3):
        print('\nPick a hand: (0: Rock, 1: Paper, 2: Scissors, 3: Exit)')
        player_hand = int(input('Please enter a number (0-2): '))

        if validate(player_hand):
            # Assign a random number between 0 and 2 to computer_hand using randint
            if player_hand == 3:
                break
            else:
                computer_hand = random.randint(0,2)
                
                print_hand(player_hand, player_name)
                print_hand(computer_hand, 'Computer')

                result = judge(player_hand, computer_hand)
                print('You ' + result+ ' this round.')
                if result == "Won":
                    player_score+=1
                if result == "Lost":
                    comp_score+=1
        else:
            print('Please enter a valid number')
    print("\n----------FINAL SCORE----------")
    print(player_name+ " = " +str(player_score) +"\nComputer = "+str(comp_score))
    print("-------------------------------")

    if player_score>comp_score:
        print("Yayy! "+player_name+" won the game!")
    elif player_score<comp_score:
        print("Alas! Computer won!")
    else:
        print("It was a draw.\nPlay again!")

main()

    
