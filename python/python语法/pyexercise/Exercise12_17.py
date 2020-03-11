from tkinter import * # Import tkinter
import tkinter.simpledialog
import random

class MainGUI():
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
        Button(frame1, text = "Find a Solution", command = self.getASolution).pack(side = LEFT)
        self.solutionLabel = Label(frame1, text = "Solution to be displayed here", width = 24, bg = "white")
        self.solutionLabel.pack(side = LEFT)
        Button(frame1, text = "Refresh", command = self.refresh).pack(side = LEFT)
        
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
        answer = StringVar()
        Entry(frame3, textvariable = answer).pack(side = LEFT)
        Button(frame3, text = "Verify", command = self.verify).pack(side = LEFT)
        
        window.mainloop() # Create an event loop

    # Choose four random cards
    def refresh(self):
        random.shuffle(self.index)
        for i in range(4):
            self.labelList[i]["image"] = self.imageList[self.index[i]]
     
    def getCards(self):
        fourCards = []
        for i in range(4):
            fourCards.append(self.index[i] % 13)
        
        fourCards.sort()
        fourCards = [x + 1 for x in fourCards]
        
        return fourCards
    
    # Verify answer
    def verify(self):   
        if self.getCards() == self.getNumbers():
            if eval(answer.get()) == 24:
                tkinter.messagebox.showinfo("Correct", "You got it")
            else:
                tkinter.messagebox.showerror("Incorrect", answer.get() + " is not 24")
        else:
            tkinter.messagebox.showerror("Incorrect", "You have to use exactly the four cards")
    
    def getNumbers(self):
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
        return numbers
        
    # Find a solution
    def findASolution(self):
      cards = self.getCards()
      a = str(cards[0])
      b = str(cards[1])
      c = str(cards[2])
      d = str(cards[3])
      
      operators = ["+", "-", "*", "/"]
      allCombinations = [            
            [a, b, c, d], [d, a, b, c],
            [c, d, a, b], [b, c, d, a], [a, b, d, c], [c, a, b, d],
            [d, c, a, b], [b, d, c, a], [a, d, c, b], [b, a, d, c],
            [c, b, a, d], [d, c, b, a], [a, c, b, d], [d, a, c, b],
            [b, d, a, c], [c, b, d, a], [b, a, c, d], [d, b, a, c],
            [c, d, b, a], [a, c, d, b], [a, d, b, c], [c, a, d, b],
            [b, c, a, d], [d, b, c, a]]
        
      for firstOp in operators:
        for secondOp in operators:
          for thirdOp in operators:
            for cardNums in allCombinations:
              for i in range(0, 3):
                for j in range(0, 5):
                   if i == 0:
                     if j == 0:
                        # Create an expression in the form a firstOp b secondOp c thirdOp d
                        solution = cardNums[0] + firstOp \
                            + cardNums[1] + secondOp \
                            + cardNums[2] + thirdOp \
                            + cardNums[3]
                        if eval(solution) == 24:
                          return solution
                     elif j == 1:
                        # Create an expression in the form (a firstOp b) secondOp c thirdOp d
                        solution = "(" + cardNums[0] + firstOp \
                            + cardNums[1] + ")" + secondOp \
                            + cardNums[2] + thirdOp \
                            + cardNums[3]
                        if eval(solution) == 24:
                          return solution
                     elif j == 2:
                        # Create an expression in the form a firstOp (b secondOp c) thirdOp d
                        solution = cardNums[0] + firstOp + "(" \
                            + cardNums[1] + secondOp \
                            + cardNums[2] + ")" + thirdOp \
                            + cardNums[3]
                        if eval(solution) == 24:
                          return solution;
                     elif j == 3:
                        # Create an expression in the form a firstOp b secondOp (c thirdOp d)
                        solution = cardNums[0] + firstOp \
                            + cardNums[1] + secondOp + "(" \
                            + cardNums[2] + thirdOp \
                            + cardNums[3] + ")"
                        if eval(solution) == 24:
                          return solution;
                     elif j == 4:
                        # Create an expression in the form (a firstOp b) secondOp (c thirdOp d)
                        solution = "(" + cardNums[0] + firstOp \
                            + cardNums[1] + ")" + secondOp \
                            + "(" + cardNums[2] + thirdOp \
                            + cardNums[3] + ")"
                        if eval(solution) == 24:
                          return solution
                   elif i == 1:
                     if j == 0:
                        solution = "(" + cardNums[0] + firstOp \
                            + cardNums[1] + secondOp \
                            + cardNums[2] + ")" + thirdOp \
                            + cardNums[3]
                        if eval(solution) == 24:
                          return solution
                     elif j == 1:
                        solution = "((" + cardNums[0] + firstOp \
                            + cardNums[1] + ")" + secondOp \
                            + cardNums[2] + ")" + thirdOp \
                            + cardNums[3]
                        if eval(solution) == 24:
                          return solution
                     elif j == 2:
                        solution = "(" + cardNums[0] + firstOp \
                            + "(" + cardNums[1] + secondOp \
                            + cardNums[2] + "))" + thirdOp \
                            + cardNums[3]
                        if eval(solution) == 24:
                          return solution
                   elif i == 2:
                     if j == 0:
                        solution = cardNums[0] + firstOp + "(" \
                            + cardNums[1] + secondOp \
                            + cardNums[2] + thirdOp \
                            + cardNums[3] + ")";
                        if eval(solution) == 24:
                          return solution
                     elif j == 1:
                        solution = cardNums[0] + firstOp + "((" \
                            + cardNums[1] + secondOp \
                            + cardNums[2] + ")" + thirdOp \
                            + cardNums[3] + ")"
                        if eval(solution) == 24:
                          return solution
                     elif j == 2:
                        solution = cardNums[0] + firstOp + "(" \
                            + cardNums[1] + secondOp + "(" \
                            + cardNums[2] + thirdOp \
                            + cardNums[3] + "))" 
                        if eval(solution) == 24:
                          return solution
        
        return "No solution"
    
    # Get a solution
    def getASolution(self):
        self.solutionLabel["text"] = self.findASolution()

MainGUI()
