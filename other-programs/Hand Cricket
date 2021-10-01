import random #this is a HAND CRICKET game.

# these are the rules for the game.
print("""Welcome to the HAND CRICKET GAME!
        here are the rules:
        1)At the toss, select '1' for HEADS and '2' for TAILS.
        2)If you win, you can choose either BATTING or BOWLING
            if you choose BATTING:
                1) the game is of 5 over of 30 balls.
                2) upon prompt, select any one number between 0(dot) and 6
                3) the numbers you enter will directly be added to your score sheet.
                4) you will be OUT if you and the computer enter the same number, you will be OUT and the computer will be bowling and the computer will chase the target set by you.
            5) if the  computer can chase the target, the computer WINS. If not, You WIN
            if you choose BOWLING:
                1) the computer will be batting so your objective will be to oust the commputer by guessing a number that the computer might guess.
                2) once the computer is out, you bat and the above rules apply.
        3) you have only one wiccket so play carefully
        that's it. GET READY TO PLAY HAND CRICKET!!!\n\n""")

# this part is for the toss
toss = ''
toss_user = ''
toss_randomiser = random.randint(1,2)
if toss_randomiser == 1:
    toss = 'HEADS'
elif toss_randomiser == 2:
    toss = 'TAILS'

toss_input = int(input("PRESS '1' for HEADS and '2' for TAILS \n"))
if toss_input == 1:
    toss_user = 'HEADS'
elif toss_input == 2:
    toss_user = 'TAILS'

# batting and bowling choice maker
toss_status = False
user_choice = 0
if toss_input == toss_randomiser:
    user_choice = int(input("YOU WON the TOSS!! press '1' for BATTING or '2' for BOWLING: \n"))
    toss_status = True
elif toss_input != toss_randomiser:
    comp_int = random.randint(1,2)
    if comp_int == 1:
        comp_choice = 'BATTING'
    elif comp_int == 2:
        comp_choice = 'BOWLING'
    toss_status = False
    print(f"The Computer won the TOSS.\nThe Computer chooses '{comp_choice}'")

# GAME PLAY

if toss_status is True:
    runs = 0
    total_runs = 0
    out = False
    comp_out = False
    if user_choice == 1: #the user is now batting
        print("YOU ARE NOW BATTING!")
        for overs in range (1, 6):
            for in_over in range (1,7):
                while out is False:
                    runs = int(input("ENTER YOUR NUMBER(BETWEEN 0(DOT) AND 6) "))
                    total_runs += runs
                    comp_runs = random.randint(0,6)
                    print(f"  YOUR RUN: {runs}\n  COMPUTER'S RUN: {comp_runs}\n OVER: {overs}.{in_over}")
                    if runs == comp_runs:
                        print("YOU'RE OUT!!")
                        total_runs = total_runs - runs
                        target = total_runs + 1
                        print(f"YOUR TOTAL SCORE = {total_runs}\nTHE COMPUTER'S TARGET: {target}")
                        out = True
                        break
            in_over = in_over + 1
        overs = overs+1
        total_runs = 0
        print("COMPUTER IS NOW BATTING!\n YOU ARE BOWLING!")
        for overs in range(1, 6):
            for in_over in range(1, 7):
                while comp_out is False:
                    runs = int(input("ENTER YOUR NUMBER(BETWEEN 0(DOT) AND 6) "))
                    comp_runs = random.randint(0, 6)
                    total_runs += comp_runs
                    print(f"  COMPUTER'S RUN: {comp_runs}\n  YOUR RUN: {runs}")
                    if runs == comp_runs:
                        print("BRAVO COMPUTER IS OUT!!")
                        comp_out = True
                    if total_runs >= target:
                        exit("OH NO!!! YOU LOST!! THANKS FOR PLAYING.")
                    if comp_out is True:
                        exit("CONGRATULATIONS!!! YOU WONN!! THANKS FOR PLAYING!!")
                    print(f"  COMPUTER'S TOTAL SCORE : {total_runs}\n YOUR TOTAL SCORE : {target}\n")

    elif user_choice == 2: #the user is now bowling:
        print("COMPUTER IS NOW BATTING!")
        for overs in range (1, 6):
            for in_over in range (1,7):
                while comp_out is False:
                    runs = int(input("\nENTER YOUR NUMBER(BETWEEN 0(DOT) AND 6) "))
                    comp_runs = random.randint(0, 6)
                    total_runs += comp_runs
                    print(f"  COMPUTER'S RUN: {comp_runs}\n  YOUR RUN: {runs}")
                    if runs == comp_runs:
                        total_runs = total_runs - comp_runs
                        target = total_runs + 1
                        print("BRAVO COMPUTER IS OUT!!")
                        print(f"  COMPUTER'S TOTAL SCORE = {total_runs}\n  YOUR TARGET: {target}")
                        comp_out = True
                        break
        total_runs = 0
        print("COMPUTER IS NOW BOWLING!\n YOU ARE BATTING!")
        for overs in range(1, 6):
            for in_over in range(1, 7):
                while out is False:
                    runs = int(input("ENTER YOUR NUMBER(BETWEEN 0(DOT) AND 6) "))
                    comp_runs = random.randint(0, 6)
                    total_runs += runs
                    print(f"  COMPUTER'S RUN: {comp_runs}\n  YOUR RUN: {runs}")
                    if comp_runs == runs:
                        print("OH NO!! YOU'RE OUT!!")
                        out = True
                    if total_runs >= target:
                        exit("CONGRATULATIONS!!! YOU WONN!! THANKS FOR PLAYING!!")
                    if out is True:
                        exit("OH NO!!! YOU LOST!! THANKS FOR PLAYING.")
                    print(f"  COMPUTER'S TOTAL SCORE : {target}\n YOUR TOTAL SCORE : {total_runs}\n")


elif toss_status is False:
    runs = 0
    total_runs = 0
    out = False
    comp_out = False
    if comp_int == 1: # the computer is now batting.
        print("COMPUTER IS NOW BATTING!")
        for overs in range(1, 6):
            for in_over in range(1, 7):
                while comp_out is False:
                    runs = int(input("\nENTER YOUR NUMBER(BETWEEN 0(DOT) AND 6) "))
                    comp_runs = random.randint(0, 6)
                    total_runs += comp_runs
                    print(f"  COMPUTER'S RUN: {comp_runs}\n  YOUR RUN: {runs}")
                    if runs == comp_runs:
                        total_runs = total_runs - comp_runs
                        target = total_runs + 1
                        print("BRAVO COMPUTER IS OUT!!")
                        print(f"  COMPUTER'S TOTAL SCORE = {total_runs}\n  YOUR TARGET: {target}")
                        comp_out = True
                        break
        total_runs = 0
        print("COMPUTER IS NOW BOWLING!\n YOU ARE BATTING!")
        for overs in range(1, 6):
            for in_over in range(1, 7):
                while out is False:
                    runs = int(input("ENTER YOUR NUMBER(BETWEEN 0(DOT) AND 6) "))
                    comp_runs = random.randint(0, 6)
                    total_runs += runs
                    print(f"  COMPUTER'S RUN: {comp_runs}\n  YOUR RUN: {runs}")
                    if comp_runs == runs:
                        print("OH NO!! YOU'RE OUT!!")
                        out = True
                    if total_runs >= target:
                        exit("CONGRATULATIONS!!! YOU WONN!! THANKS FOR PLAYING!!")
                    if out is True:
                        exit("OH NO!!! YOU LOST!! THANKS FOR PLAYING.")
                    print(f"  COMPUTER'S TOTAL SCORE : {target}\n YOUR TOTAL SCORE : {total_runs}\n")

    elif comp_int == 2:
        print("YOU ARE NOW BATTING!")
        for overs in range(1, 6):
            for in_over in range(1, 7):
                while out is False:
                    runs = int(input("ENTER YOUR NUMBER(BETWEEN 0(DOT) AND 6) "))
                    total_runs += runs
                    comp_runs = random.randint(0, 6)
                    print(f"  YOUR RUN: {runs}\n  COMPUTER'S RUN: {comp_runs}")
                    if runs == comp_runs:
                        print("YOU'RE OUT!!")
                        total_runs = total_runs - runs
                        target = total_runs + 1
                        print(f"YOUR TOTAL SCORE = {total_runs}\nTHE COMPUTER'S TARGET: {target}")
                        out = True
                        break
        total_runs = 0
        print("COMPUTER IS NOW BATTING!\n YOU ARE BOWLING!")
        for overs in range(1, 6):
            for in_over in range(1, 7):
                while comp_out is False:
                    runs = int(input("ENTER YOUR NUMBER(BETWEEN 0(DOT) AND 6) "))
                    comp_runs = random.randint(0, 6)
                    total_runs += comp_runs
                    print(f"  COMPUTER'S RUN: {comp_runs}\n  YOUR RUN: {runs}")
                    if runs == comp_runs:
                        print("BRAVO COMPUTER IS OUT!!")
                        comp_out = True
                    if total_runs >= target:
                        exit("OH NO!!! YOU LOST!! THANKS FOR PLAYING.")
                    if comp_out is True:
                        exit("CONGRATULATIONS!!! YOU WONN!! THANKS FOR PLAYING!!")
                    print(f"  COMPUTER'S TOTAL SCORE : {total_runs}\n YOUR TOTAL SCORE : {target}\n")

exit()

#list  of variables and uses:
# toss  = toss generator variable that returns the toss result
# toss_randomiser = randomises toss using a random number betwee 1(heads) and 2(tails). using an if statement, this is then assigned accordingly to "toss".
# toss_input = asks user for a toss choice: 1 for heads and 2 for tails accordingly assigns it to "toss_user"
# toss_user  = basically, takes an input from the "toss_input" variable from the user and gets assigned to heads or tails.
# user_choice = upon winning the toss, this variable stores your play choce i.e. 1 for batting and 2 for bowling.
# comp_int = takes a random integer between 1 and 2 and assigns it to batting or bowling accordingly and stores it in the "comp_choice" variable.
# comp_choice = takes input from "comp_int" and gets assigned as the computers choice of play i.e batting or bowling when the player loses the toss.
# runs = calculates the runs of the user when they are batting. temporary and altered every user input within an over
# total_runs = total runs of the user in the game. calculated overall.
# overs = total overs i.e. 5 used for iteration using a for loop for 5 overs.
# in_overs = used for 6 balls within the over iteration.
# out = boolean value deciding whether player is out or not.
# comp_out = boolean value deidinng whether computer is out or not
# toss_status = status of toss whether player won the toss or the computer wonn
# target = total runs scored + 1.
# comp_out = checks the status of the computer whether it is out or not.
