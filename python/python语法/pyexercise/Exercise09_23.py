from tkinter import * # Import tkinter

width = 280
height = 50

class MainGUI:
    def __init__(self):
        window = Tk() # Create a window
        window.title("Radio buttons and buttons") # Set title
        
        frame1 = Frame(window)
        frame1.pack()
        
        self.v = IntVar()
        Radiobutton(frame1, text = "Red",
                    variable = self.v, value = 1, command = self.processRadiobutton).pack(side = LEFT)
        Radiobutton(frame1, text = "Yellow",
                    variable = self.v, value = 2, command = self.processRadiobutton).pack(side = LEFT)
        Radiobutton(frame1, text = "White",
                    variable = self.v, value = 3, command = self.processRadiobutton).pack(side = LEFT)
        Radiobutton(frame1, text = "Gray",
                    variable = self.v, value = 4, command = self.processRadiobutton).pack(side = LEFT)
        Radiobutton(frame1, text = "Green",
                    variable = self.v, value = 5, command = self.processRadiobutton).pack(side = LEFT)

        self.canvas = Canvas(window, bg = "white", width = width, height = height)
        self.canvas.create_text(width / 2, height / 2, text = "Welcome", tags = "text")
        self.canvas.pack()
        
        frame2 = Frame(window)
        frame2.pack()
        Button(frame2, text = "<=", command = self.left).pack(side = LEFT)
        Button(frame2, text = "=>", command = self.right).pack(side = LEFT)
        
        window.mainloop() # Create an event loop

    def processRadiobutton(self):
        if self.v.get() == 1:
            self.canvas["bg"] = "red"
        elif self.v.get() == 2:
            self.canvas["bg"] = "yellow"
        elif self.v.get() == 3:
            self.canvas["bg"] = "white"
        elif self.v.get() == 4:
            self.canvas["bg"] = "gray"
        elif self.v.get() == 5:
            self.canvas["bg"] = "green"
            
    def left(self):
        self.canvas.move("text", -5, 0)
    
    def right(self):
        self.canvas.move("text", 5, 0)
        
MainGUI()
