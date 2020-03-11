from tkinter import * # Import tkinter
from random import randint

class MainGUI:
    def __init__(self):
        window = Tk() # Create a window
        window.title("TicTacToe") # Set a title
        
        self.imageX = PhotoImage(file = "image/x.gif")
        self.imageO = PhotoImage(file = "image/o.gif")
        
        frame = Frame(window)
        frame.pack()
        
        self.matrix = []
        for i in range(3):
            self.matrix.append([])
            for j in range(3):
                self.matrix[i].append(Label(frame, image = self.imageX if randint(0, 1) == 0 else self.imageO))
                self.matrix[i][j].grid(row = i, column = j)
        
        frame1 = Frame(window)
        frame1.pack()
        Button(frame1, text = "Refresh", command = self.refresh).pack()
        
        window.mainloop() # Create an event loop

    def refresh(self):
        for i in range(3):
            for j in range(3):
                self.matrix[i][j]["image"] = self.imageX if randint(0, 1) == 0 else self.imageO

MainGUI()
