from tkinter import * # Import tkinter

width = 300
height = 50

class MainGUI:
    def displayFigure(self):
        self.canvas.delete("shape")
        if self.filled.get() == 1:
            if self.v.get() == 1:
                self.canvas.create_rectangle(width / 2 - width * 0.4, height / 2 - height * 0.4, 
                    width / 2 + width * 0.4, height / 2 + height * 0.4, fill = "red", tags = "shape")
            else:
                self.canvas.create_oval(width / 2 - width * 0.4, height / 2 - height * 0.4, 
                    width / 2 + width * 0.4, height / 2 + height * 0.4, fill = "red", tags = "shape")
        else:
            if self.v.get() == 1:
                self.canvas.create_rectangle(width / 2 - width * 0.4, height / 2 - height * 0.4, 
                    width / 2 + width * 0.4, height / 2 + height * 0.4, tags = "shape")
            else:
                self.canvas.create_oval(width / 2 - width * 0.4, height / 2 - height * 0.4, 
                    width / 2 + width * 0.4, height / 2 + height * 0.4, tags = "shape")
    
    def left(self):
        self.canvas.move("text", -5, 0)
    
    def right(self):
        self.canvas.move("text", 5, 0)

    def __init__(self):
        window = Tk() # Create a window
        window.title("Radiobuttons and Checkbuttons") # Set title
        
        self.canvas = Canvas(window, bg = "white", width = width, height = height)
        self.canvas.create_rectangle(width / 2 - width * 0.4, height / 2 - height * 0.4, 
            width / 2 + width * 0.4, height / 2 + height * 0.4, tags = "shape")
        self.canvas.pack()
        
        frame1 = Frame(window)
        frame1.pack()
        
        self.v = IntVar()
        Radiobutton(frame1, text = "Rectangle",
                    variable = self.v, value = 1, command = self.displayFigure).pack(side = LEFT)
        Radiobutton(frame1, text = "Oval",
                    variable = self.v, value = 2, command = self.displayFigure).pack(side = LEFT)
                    
        self.filled = IntVar()
        Checkbutton(frame1, text = "Filled",
                    variable = self.filled, command = self.displayFigure).pack(side = LEFT)
        
        window.mainloop() # Create an event loop

MainGUI()
