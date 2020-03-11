from tkinter import * # Import tkinter

class MainGUI:
    def __init__(self):
        window = Tk() # Create a window
        window.title("Checkerboard") # Set a title
        
        size = 30
        for i in range(0, 8):
            frame = Frame(window)
            frame.pack()
            for j in range(0, 4):
                if i % 2 == 0:
                    canvas = Canvas(frame, bg = "white", width = size, height = size)
                    canvas.pack(side = LEFT)
                    canvas = Canvas(frame, bg = "black", width = size, height = size)
                    canvas.pack(side = LEFT)
                else:
                    canvas = Canvas(frame, bg = "black", width = size, height = size)
                    canvas.pack(side = LEFT)
                    canvas = Canvas(frame, bg = "white", width = size, height = size)
                    canvas.pack(side = LEFT)
        
        window.mainloop() # Create an event loop
        
MainGUI()
