from tkinter import * # Import tkinter

width = 240
height = 120
        
class MainGUI:
    def __init__(self):
        window = Tk() # Create a window
        window.title("Inside the rectangle?") # Set a title
        
        self.canvas = Canvas(window, bg = "white", width = width, height = height)
        self.canvas.pack()
        self.canvas.create_rectangle(100 - 50, 60 - 20, 100 + 50, 60 + 20, tags = "rectangle")
        
        self.canvas.bind("<B1-Motion>", self.isInside)
        
        window.mainloop() # Create an event loop

    def isInside(self, event):
        self.canvas.delete("text")
        if isInsideRectangle(100, 60, 100, 40, event.x, event.y):
            self.canvas.create_text(event.x, event.y - 5, 
                               text = "Mouse pointer is in the rectangle", tags = "text")
        else:
            self.canvas.create_text(event.x, event.y - 5, 
                               text = "Mouse pointer is not in the rectangle", tags = "text")

def isInsideRectangle(xCenter, yCenter, w, h, x, y):
    return abs(xCenter - x) <= w / 2 and abs(yCenter - y) <= h / 2

MainGUI()
