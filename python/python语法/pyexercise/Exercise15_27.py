SIZE = 8 # The size of the chessboard
queens = 8 * [SIZE] # Queen positions 

# Check if a queen can be placed at row i and column j 
def isValid(row, column):
    for i in range(1, row + 1):
        if (queens[row - i] == column # Check column
            or queens[row - i] == column - i # Check upleft diagonal
            or queens[row - i] == column + i): # Check upright diagonal
            return False # There is a conflict
    return True # No conflict

# Search for a solution starting from a specified row 
def search(row):
    if row == SIZE: # Stopping condition
        return True # A solution found to place 8 queens in 8 rows

    for column in range(SIZE):
        queens[row] = column # Place a queen at (row, column)
        if isValid(row, column) and search(row + 1):
            return True # Found, thus return true to exit for loop   
      
    # No solution for a queen placed at any column of this row
    return False

search(0) # Search for a solution from row 0
    
print(queens)
# Display solution

from tkinter import * # Import tkinter
window = Tk() # Create a window
window.title("Eight Queens") # Set a title

image = PhotoImage(file = "image/queen.gif")
for i in range(8):
    for j in range(8):
        if queens[i] == j:
            Label(window, image = image).grid(row = i, column = j)
        else:
            Label(window, width = 5, height = 2, bg = "red").grid(row = i, column = j)
        
window.mainloop() # Create an event loop
