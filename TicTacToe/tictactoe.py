board = [[1,2,3], [4,5,6], [7,8,9]]
global moves
moves = 9

#This function doesn't let the user's sign to be bigger than 1 character :)
def chooseSign(x):
    inp = input("Player {} choose your sign: ".format(x))
    if len(inp) > 1:
        inp = inp[0]

    return inp

#This loop doesn't let both signs to be the same
while True:
    p1 = chooseSign(1)
    print(f"Player 1's sign is {p1}")
    p2 = chooseSign(2)
    print(f"Player 2's sign is {p2}")

    if p1 == p2:
        print("Signs cannot be the same.")
    else:
        break

#This function prints the board according to the values of 'board' list
def printBoard():
    for i in range(3):
            print(str(board[i][0]) + '   |   ' + str(board[i][1]) + '   |   ' + str(board[i][2]) + '\n__________________')

def check():
    global running
    running = True

    for i in range(3):
        if board[i][0] == board[i][1]  == board[i][2]:
            print("Player 1 wins!") if board[i][0] == p1 else print("Player 2 wins!")
            running = False
            return
    
    for i in range(3):
        if board[0][i] == board[1][i] == board[2][i]:
            print("Player 1 wins!") if board[0][i] == p1 else print("Player 2 wins!")
            running = False
            return

    if board[0][0] == board[1][1] == board[2][2] or board[0][2] == board[1][1] == board[2][0]:
        print("Player 1 wins!") if board[1][1] == p1 else print("Player 2 wins!")
        running = False
        return

    if moves == 0:
        print("It is a draw")
        running = False

check()

#Prints the empty board
printBoard()

#Game loop
while running == True:

    #[PLAYER1]This block of code doesn't let user choose a block that doesn't exist. Like 0 or 14 and handles value error
    safe1 = False
    while safe1 == False:
        try:
            play1 = int(input("Player 1's chance: "))
            if play1 < 1 or play1 > 9:
                print("Please enter a number from 1 to 9")
            else:
                safe1 = True
                moves -= 1
        except Exception as err:
            print("Please enter a number from 1 to 9")
            print(err)

    #Fills in the board with player 1's sign
    for a in range(1, 10):
        if play1 == a:
            for i in range(3):
                for j in range(3):
                    if board[i][j] == play1:
                        board[i][j] = p1
                        break
    #Update the board
    printBoard()
    check()
    if running == False:
        break

    #[PLAYER2]This block of code doesn't let user choose a block that doesn't exist. Like 0 or 14 and handles value error
    safe2 = False
    while safe2 == False:
        try:
            play2 = int(input("Player 2's chance: "))
            if play2 < 1 or play2 > 9:
                print("Please enter a number from 1 to 9")
            else:
                safe2 = True
                moves -= 1
        except:
            print("Please enter a number from 1 to 9")

    #Fills in the board with player 2's sign
    for a in range(1, 10):
        if play2 == a:
            for i in range(3):
                for j in range(3):
                    if board[i][j] == play2:
                        board[i][j] = p2
                        break    
    #Update the board
    printBoard()
    check()
