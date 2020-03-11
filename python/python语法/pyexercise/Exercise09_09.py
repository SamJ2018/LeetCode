from tkinter import * # Import tkinter

width = 400
height = 150

class MainGUI:
    def drawABar(self, x, percent, color, title):
        self.canvas.create_line(0, height - 10, width, height - 10)
        self.canvas.create_rectangle(x, (1 - percent) * (height - 30), x + width / 4.3 - 5, height - 10, fill = color)
        self.canvas.create_text((x + x + width / 4.3 - 5) / 2, (1 - percent) * (height - 30) - 10,
                            text = title)

    def __init__(self):
        window = Tk() # Create a window
        window.title("Bar Chart") # Set a title
        
        self.canvas = Canvas(window, bg = "white", width = width, height = height)
        self.canvas.pack()
        
        x = 10
        self.drawABar(x, 0.4, "red", "Project -- 20%")
          
        x += width / 4.3 - 5 + 10  
        self.drawABar(x, 0.1, "blue", "Quizzes -- 10%")
        
        x += width / 4.3 - 5 + 10  
        self.drawABar(x, 0.3, "green", "Midterm -- 30%")
        
        x += width / 4.3 - 5 + 10  
        self.drawABar(x, 0.4, "orange", "Final -- 40%")
        
        window.mainloop() # Create an event loop
        
MainGUI()
