from tkinter import * # Import tkinter
  
width = 200
height = 100
        
class MainGUI:
    def __init__(self):
        window = Tk() # Create a window
        window.title("Moving Circle") # Set a title
        
        self.canvas = Canvas(window, bg = "white", width = width, height = height)
        self.canvas.pack()
        self.canvas.create_oval(10, 10, 30, 30, tags = "circle")
        
        self.canvas.bind("<Up>", self.up)
        self.canvas.bind("<Down>", self.down)
        self.canvas.bind("<Left>", self.left)
        self.canvas.bind("<Right>", self.right)
        self.canvas.focus_set()
        
        window.mainloop() # Create an event loop

    def left(self, event):
        self.canvas.move("circle", -5, 0)
    
    def right(self, event):
        self.canvas.move("circle", 5, 0)
    
    def down(self, event):
        self.canvas.move("circle", 0, 5)
    
    def up(self, event):
        self.canvas.move("circle", 0, -5)
        
MainGUI()
