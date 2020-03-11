from tkinter import * # Import tkinter
from random import randint

SIZE = 10

def findLargestBlock(m):
    count = []
    for i in range(len(m)):
        count.append([])
        for j in range(len(m)):
            count[i].append(0)
    
    for i in range(len(m) - 1, 0 - 1, -1):
        for j in range(len(m) - 1, 0 - 1, -1):
            if m[i][j] == 1:
                count[i][j] = 1
                for k in range(1, count[i][j] + 1):
                    if i < len(m) - 1 and j < len(m) - 1 and m[i + 1][j + 1] == 1:
                        # Check to expand the block with (i, j) at its upper right corner
                        for k in range(1, count[i + 1][j + 1] + 1):
                            if m[i][j + k] == 1 and m[i + k][j] == 1:
                                count[i][j] += 1
                            else:
                                break

    max = count[0][0]
    maxOfx = 0
    maxOfy = 0
    for i in range(len(m)):
        for j in range(len(m[i])):
            if count[i][j] > max:
                max = count[i][j]
                maxOfx = i
                maxOfy = j
                
    return maxOfx, maxOfy, max                      
        
class MainGUI:
    def __init__(self):
        window = Tk() # Create a window
        window.title("Find Largest Block") # Set title
        
        frame1 = Frame(window)
        frame1.pack()
        
        self.m = [] 
        for i in range(SIZE):
            self.m.append([])
            for j in range(SIZE):
                self.m[i].append(0)
                
        self.cells = [] # A list of variables tied to entries
        for i in range(SIZE):
            self.cells.append([])
            for j in range(SIZE):
                self.cells[i].append(StringVar())
        
        self.entries = []
        for i in range(SIZE):
            self.entries.append([])
            for j in range(SIZE):
                self.entries[i].append(Entry(frame1, width = 2, justify = RIGHT, 
                      textvariable = self.cells[i][j]))
                self.entries[i][j].grid(row = i, column = j)
                
        frame2 = Frame(window)
        frame2.pack()
        Button(frame2, text = "Refresh", command = self.refresh).pack(side = LEFT)
        Button(frame2, text = "Find Largest Block", command = self.findBlock).pack(side = LEFT)
        
        self.refresh()
        window.mainloop() # Create an event loop
        
    def refresh(self):
        for i in range(SIZE):
            for j in range(SIZE):
                self.cells[i][j].set(str(randint(0, 1)))    
                self.entries[i][j]["bg"] = "white"   
            
    def findBlock(self):
        for i in range(SIZE):
            for j in range(SIZE):
                self.m[i][j] = int(self.cells[i][j].get())
            
        x, y, length = findLargestBlock(self.m)
            
        for i in range(x, x + length):
            for j in range(y, y + length):
                self.entries[i][j]["bg"] = "red"      

MainGUI()
