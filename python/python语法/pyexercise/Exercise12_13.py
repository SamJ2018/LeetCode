from tkinter import * # Import tkinter
import tkinter.messagebox

turn = "white"

class Cell(Canvas):
    def __init__(self, parent, width = 20, height = 20):
        Canvas.__init__(self, parent, width = width, height = height, bg = "blue", borderwidth = 2)
        self.color = "white"
        self.create_oval(4, 4, 20, 20, fill = "white")
        self.bind("<Button-1>", self.clicked)
    
    def clicked(self, event):
        global turn
        if self.color == "white":
            if turn == "white":
                self.color = "red"
                self.create_oval(4, 4, 20, 20, fill = "red")
                turn = "yellow"
            elif turn == "yellow":
                self.create_oval(4, 4, 20, 20, fill = "yellow")
                self.color = "yellow"
                turn = "red"
            elif turn == "red":
                self.color = "red"
                self.create_oval(4, 4, 20, 20, fill = "red")
                turn = "yellow"            
        
def retart():
    pass
    
window = Tk() # Create a window
window.title("Connect Four") # Set title

frame1 = Frame(window)
frame1.pack()
for i in range(6):
    for j in range(7):
        Cell(frame1, width = 20, height = 20).grid(row = i, column = j)
        
frame2 = Frame(window)
frame2.pack()
Button(frame2, text = "Start Over", command = "restart").pack()

window.mainloop() # Create an event loop
