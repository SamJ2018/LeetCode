import sys

def main():
    board = [[' ', ' ', ' '], [' ', ' ', ' '], [' ', ' ', ' ']]
    
    displayBoard(board);

    while True:
        # Prompt the first player
        makeAMove(board, 'X')
      
        displayBoard(board)
        if isWon('X', board):
            print("X player won")
            sys.exit()
        elif isDraw(board):
            print("No winner")
            sys.exit()

        # Prompt the second player
        makeAMove(board, 'O')
        displayBoard(board)

        if isWon('O', board):
            print("O player won")
            sys.exit()
        elif isDraw(board):
            print("No winner")
            sys.exit()

def makeAMove(board, player):
    done = False
    
    while not done:
        row = eval(input("Enter a row for player " + player + ": "))
        column = eval(input("Enter a column for player " + player + ": "))
    
        if board[row][column] == ' ': # an empty cell
            board[row][column] = player;
            done = True
        else:
            print("This cell is already occupied. Try a different cell");
  
def displayBoard(board):
    print("\n-------------")

    for i in range(3):
        print("| ", end = "")
        for j in range(3):
            print(board[i][j] + " | " if board[i][j] != '\u0000' else "  | ", end = "")
        print("\n-------------")

def isWon(ch, board):
    # Check rows
    for i in range(3):
        if ch == board[i][0] and ch == board[i][1] and ch == board[i][2]: 
            return True

    # Check columns
    for j in range(3):
        if ch == board[0][j] and ch == board[1][j] and ch == board[2][j]: return True

    # Check major diagonal
    if ch == board[0][0] and ch == board[1][1] and ch == board[2][2]: return True

    # Check sub diagonal
    if ch == board[0][2] and ch == board[1][1] and ch == board[2][0]: return True

    return False

def isDraw(board):
    for i in range(3):
        for j in range(3):
            if board[i][j] == ' ': return False

    return True # All cells are now occupied

main()
