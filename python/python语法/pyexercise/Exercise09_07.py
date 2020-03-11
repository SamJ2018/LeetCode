from tkinter import * # Import tkinter

class MainGUI:
    def __init__(self):
        window = Tk() # Create a window
        window.title("TicTacToe") # Set a title
        
        width = 100
        height = 100
        canvas = Canvas(window, bg = "white", width = width, height = height)
        canvas.pack()
        
        for i in range(8): # Draw 8 horizontal lines
            canvas.create_line(0, i * height / 8, width, i * height / 8, fill = "blue")
            canvas.create_line(i * width / 8, 0, i * width / 8, height, fill = "red")
        
        window.mainloop() # Create an event loop

MainGUI()
