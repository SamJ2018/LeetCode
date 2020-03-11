from tkinter import * # Import tkinter

width = 200
height = 150
        
class MainGUI:
    def __init__(self):
        window = Tk() # Create a window
        window.title("Traffic Lights") # Set title

        self.h = height * 0.85
        self.w = self.h / 3
        self.radius = self.w * 0.9 / 2
        
        self.canvas = Canvas(window, bg = "white", width = width, height = height)
        self.canvas.pack()
        self.displayBasic()
        
        frame1 = Frame(window)
        frame1.pack()
        
        self.v = IntVar()
        Radiobutton(frame1, text = "Red",
                    variable = self.v, value = 1, command = self.displayFigure).pack(side = LEFT)
        Radiobutton(frame1, text = "Yellow",
                    variable = self.v, value = 2, command = self.displayFigure).pack(side = LEFT)
        Radiobutton(frame1, text = "Green",
                    variable = self.v, value = 3, command = self.displayFigure).pack(side = LEFT)
        
        window.mainloop() # Create an event loop

    def displayFigure(self):
        self.canvas.delete("light")
        self.displayBasic()
        
        if self.v.get() == 1:
            self.canvas.create_oval(width / 2 - self.radius, height / 2 - self.radius - self.w, width / 2 + self.radius, height / 2 + self.radius - self.w, 
                fill = "red", tags = "light")       
        elif self.v.get() == 2:
            self.canvas.create_oval(width / 2 - self.radius, height / 2 - self.radius, width / 2 + self.radius, height / 2 + self.radius, 
                fill = "yellow", tags = "light")
        else:
            self.canvas.create_oval(width / 2 - self.radius, height / 2 - self.radius + self.w, width / 2 + self.radius, height / 2 + self.radius + self.w, 
                fill = "green", tags = "light")
        
    def displayBasic(self):
        self.canvas.create_rectangle(width / 2 - self.w / 2, height / 2 - self.h / 2, 
            width / 2 + self.w / 2, height / 2 + self.h / 2, tags = "light")
        self.canvas.create_oval(width / 2 - self.radius, height / 2 - self.radius, width / 2 + self.radius, height / 2 + self.radius, 
            tags = "light")
        self.canvas.create_oval(width / 2 - self.radius, height / 2 - self.radius - self.w, width / 2 + self.radius, height / 2 + self.radius - self.w, 
            tags = "light")
        self.canvas.create_oval(width / 2 - self.radius, height / 2 - self.radius + self.w, width / 2 + self.radius, height / 2 + self.radius + self.w, 
            tags = "light")  

MainGUI()
