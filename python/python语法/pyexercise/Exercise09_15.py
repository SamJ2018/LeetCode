from tkinter import * # Import tkinter

class MainGUI:
    def __init__(self):
        window = Tk() # Create a window
        window.title("Fan") # Set a title
        
        width = 200
        height = 200
        radius = 80
        
        canvas = Canvas(window, bg = "white", width = width, height = height)
        canvas.pack()
        
        canvas.create_arc(width / 2 - radius, height / 2 - radius, width / 2 + radius, height / 2 + radius,
            start = 0, extent = 30, fill = "red", tags = "fan")
        
        canvas.create_arc(width / 2 - radius, height / 2 - radius, width / 2 + radius, height / 2 + radius,
            start = 90, extent = 30, fill = "red", tags = "fan")
        
        canvas.create_arc(width / 2 - radius, height / 2 - radius, width / 2 + radius, height / 2 + radius,
            start = 180, extent = 30, fill = "red", tags = "fan")
        
        canvas.create_arc(width / 2 - radius, height / 2 - radius, width / 2 + radius, height / 2 + radius,
            start = 270, extent = 30, fill = "red", tags = "fan")
        
        window.mainloop() # Create an event loop
        
MainGUI()
