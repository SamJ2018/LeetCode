from tkinter import * # Import tkinter

class Cell(Label):
    def __init__(self, container):
        Label.__init__(self, container, image = imageEmpty)
        self.bind("<Button-1>", self.flip)
        self.token = " "
      
    def flip(self, event):
        global currentToken
        if self.token == " " and currentToken != "Over":
            if currentToken == "X":
                currentToken = "O"
                self["image"] = imageX   
                self.token = "X"
            else:   
                currentToken = "X"
                self["image"] = imageO   
                self.token = "O"
                
        checkStatus(self.token)

def checkStatus(token):
    global currentToken
    if isWon(token):
        statusLabel["text"] = token + " won! The game is over"
        currentToken = "Over"
    elif isFull():
        statusLabel["text"] = "Draw! The game is over"
        currentToken = "Over"
        
# Determine whether the cells are all occupied 
def isFull():
    for i in range(3):
        for j in range(3):
            if cells[i][j].token == ' ':
                return False

    return True

# Determine whether the player with the specified token wins 
def isWon(token):
    for i in range(3):
        if cells[i][0].token == token and cells[i][1].token == token \
            and cells[i][2].token == token:
            return True

    for j in range(3):
      if cells[0][j].token == token and cells[1][j].token == token \
          and cells[2][j].token == token:
        return True

    if cells[0][0].token == token and cells[1][1].token == token \
        and cells[2][2].token == token:
      return True

    if cells[0][2].token == token and cells[1][1].token == token \
        and cells[2][0].token == token:
      return True

    return False

window = Tk() # Create a window
window.title("TicTacToe") # Set title

imageX = PhotoImage(file = "image/x.gif")
imageO = PhotoImage(file = "image/o.gif")
imageEmpty = PhotoImage(file = "image/empty.gif")
currentToken = "X"
    
frame = Frame(window)
frame.pack()

cells = []
for i in range(3):
    cells.append([])
    for j in range(3):
        cells[i].append(Cell(frame))
        cells[i][j].grid(row = i, column = j)

statusLabel = Label(window, text = "Game status: continue")
statusLabel.pack()

window.mainloop() # Create an event loop
