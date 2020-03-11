import math    
from tkinter import * # Import tkinter

class MainGUI:
    def __init__(self):
        window = Tk() # Create a window
        window.title("Square Function") # Set title
        
        width = 400
        height = 150
        canvas = Canvas(window, width = width, height = height)
        canvas.pack()
        
        # Draw a square function
        scaleFactor = 0.01
        left = -100
        right = 100
        p = []
        for  x in range(left, right + 1):
            p.append([x + width / 2, -scaleFactor * x * x + height / 2 + height / 4])
        
        for i in range(len(p) - 1):
            canvas.create_line(p[i], p[i + 1])
          
        # Draw X-axis
        canvas.create_line(10, height / 2 + height / 4, width - 10, height / 2 + height / 4)
        canvas.create_line(width - 10 -10, height / 2 + height / 4 + 10, width - 10, height / 2 + height / 4)
        canvas.create_line(width - 10 -10, height / 2 + height / 4 - 10, width - 10, height / 2 + height / 4)
        canvas.create_text(width - 10 + 5, height / 2 + height / 4, text = "x")
        
        # Draw Y-axis
        canvas.create_line(width / 2, 10, width / 2, height - 10)
        canvas.create_line(width / 2, 10, width / 2 - 10, 10 + 10)
        canvas.create_line(width / 2, 10, width / 2 + 10, 10 + 10)
        canvas.create_text(width / 2, 10 - 8, text = "y")
            
        window.mainloop() # Create an event loop

MainGUI()
