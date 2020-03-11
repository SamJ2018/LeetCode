from tkinter import * # Import tkinter
import tkinter.simpledialog
import random

class MainGUI:
    def __init__(self):
        window = Tk() # Create a window
        window.title("24-Point Game") # Set title
        
        self.index = [x for x in range(52)]
        
        self.imageList = [] # Store images for cards
        for i in range(1, 53):
            self.imageList.append(PhotoImage(file = "image/card/" 
                   + str(i) + ".gif"))
        
        frame1 = Frame(window)
        frame1.pack()
        Button(frame1, text = "Refresh", command = self.refresh).pack()
        
        frame2 = Frame(window) # Hold four labels for displaying cards
        frame2.pack()
        
        self.labelList = [] # A list of four labels
        for i in range(4):
            self.labelList.append(Label(frame2, image = self.imageList[i]))
            self.labelList[i].pack(side = LEFT)
        self.refresh()
        
        frame3 = Frame(window) # Hold four labels for displaying cards
        frame3.pack()
        Label(frame3, text = "Enter an expression: ").pack(side = LEFT)
        self.answer = StringVar()
        Entry(frame3, textvariable = self.answer).pack(side = LEFT)
        Button(frame3, text = "Verify", command = self.verify).pack(side = LEFT)
        
        window.mainloop() # Create an event loop

    # Choose four random cards
    def refresh(self):
        random.shuffle(self.index)
        for i in range(4):
            self.labelList[i]["image"] = self.imageList[self.index[i]]
     
    # Verify answer
    def verify(self):
        fourCards = []
        for i in range(4):
            fourCards.append(self.index[i] % 13)
        
        fourCards.sort()
        fourCards = [x + 1 for x in fourCards]
        
        expression = self.answer.get()
        expression = expression.replace('+', ' ')
        expression = expression.replace('-', ' ')
        expression = expression.replace('*', ' ')
        expression = expression.replace('/', ' ')
        expression = expression.replace('(', ' ')
        expression = expression.replace(')', ' ')
        numbers = expression.split()
        numbers = [eval(x) for x in numbers]
        numbers.sort()
        
        if fourCards == numbers:
            if eval(self.answer.get()) == 24:
                tkinter.messagebox.showinfo("Correct", "You got it")
            else:
                tkinter.messagebox.showerror("Incorrect", self.answer.get() + " is not 24")
        else:
            tkinter.messagebox.showerror("Incorrect", "You have to use the four cards shown")

MainGUI()
