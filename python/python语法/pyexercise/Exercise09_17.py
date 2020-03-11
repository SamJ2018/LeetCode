from tkinter import * # Import tkinter

width = 200
height = 100
radius = 80

class MainGUI:
    def __init__(self):
        window = Tk() # Create a window
        window.title("Racing Car") # Set a title
        
        self.canvas = Canvas(window, bg = "white", width = width, height = height)
        self.canvas.pack()
        
        self.x = 0
        self.y = 100
        self.sleepTime = 100
        
        # Bind canvas with key events
        self.canvas.bind("<Up>", self.faster)
        self.canvas.bind("<Down>", self.slower)
        self.canvas.focus_set()
        
        while True:
            if self.x < width:
                self.displayCar()
                self.x += 2
            else:
                self.x = 0
                
            self.canvas.after(self.sleepTime) # Sleep for 100 milliseconds
            self.canvas.update()
        
        window.mainloop() # Create an event loop

    def displayCar(self):
        self.canvas.delete("car") 
    
        self.canvas.create_oval(self.x + 10, self.y - 10, self.x + 20,  self.y, fill = "black", tags = "car")
        self.canvas.create_oval(self.x + 30, self.y - 10, self.x + 40,  self.y, fill = "black", tags = "car")
        self.canvas.create_rectangle(self.x, self.y - 20, self.x + 50,  self.y - 10, fill = "green", tags = "car")
        self.canvas.create_polygon(self.x + 10, self.y - 20, self.x + 20,  self.y - 30, 
                              self.x + 30, self.y - 30, self.x + 40, self.y - 20, fill = "red", tags = "car")
    
    def faster(self, event):
        print(sleepTime)
        if self.sleepTime > 15:
            self.sleepTime -= 15
    
    def slower(self, event):
        print(sleepTime)
        self.sleepTime += 15

MainGUI()
