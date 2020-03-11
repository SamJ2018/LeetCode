from tkinter import * # Import tkinter
from random import randint

width = 300
height = 150
         
class MainGUI:
    def __init__(self):      
        window = Tk() # Create a window
        window.title("Random an Arrow Line") # Set title
        
        self.canvas = Canvas(window, width = width, height = height)
        self.canvas.pack()
        self.drawAnArrowLine()
        
        Button(window, text = "Draw a Random Arrow Line", 
                             command = self.drawAnArrowLine).pack()
        
        window.mainloop() # Create an event loop
        
    def drawAnArrowLine(self):
        x1 = randint(0, width - 1)
        y1 = randint(0, height - 1)
        x2 = randint(0, width - 1)
        y2 = randint(0, height - 1)
        
        self.canvas.delete("line")
        self.canvas.create_line(x1, y1, x2, y2, arrow = "last", tags = "line")

MainGUI()
