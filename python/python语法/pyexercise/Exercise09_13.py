from tkinter import * # Import tkinter

width = 220
height = 100

class MainGUI:
    def __init__(self):
        window = Tk() # Create a window
        window.title("Mouse Position") # Set a title
        
        self.canvas = Canvas(window, bg = "white", width = width, height = height)
        self.canvas.pack()
        
        # Bind canvas with mouse events
        self.canvas.bind("<Button-1>", self.displayPosition)
        
        window.mainloop() # Create an event loop
        
    def displayPosition(self, event):
        self.canvas.delete("text")
        self.canvas.create_text(event.x, event.y - 4, 
            text = "(" + str(event.x) + ", " + str(event.y) + ")", tags = "text")
    
MainGUI()
