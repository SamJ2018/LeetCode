from tkinter import * # Import tkinter
import tkinter.messagebox
        
def solve():   
    for i in range(6):
        for j in range(7):
            entries[i][j]["bg"] = "white"
    
    values = [[x.get() for x in v[i]] for i in range(6)]
    result = isConsecutiveFourInMatrix(values);
    if result != None:
        entries[result[0][0]][result[0][1]]["bg"] = "yellow"
        entries[result[1][0]][result[1][1]]["bg"] = "yellow"
        entries[result[2][0]][result[2][1]]["bg"] = "yellow"
        entries[result[3][0]][result[3][1]]["bg"] = "yellow"
    else:
        tkinter.messagebox.showinfo("showinfo", 
            "No four consecutive numbers in a row, a column, or a diagonal")          

def isConsecutiveFourInMatrix(values):
    numberOfRows = len(values)
    numberOfColumns = len(values[0])

    # Check rows
    for i in range(numberOfRows):
        if isConsecutiveFour(values[i]) != None:
            result = [[0, 0], [0, 0], [0, 0], [0, 0]]
            result[0][0] = result[1][0] = result[2][0] = result[3][0] = i
            k = isConsecutiveFour(values[i])
        
            result[0][1] = k
            result[1][1] = k + 1
            result[2][1] = k + 2
            result[3][1] = k + 3
   
            return result

    # Check columns
    for j in range(numberOfColumns):
        column = []
        # Get a column into an array
        for i in range(numberOfRows):
            column.append(values[i][j])
      
        if isConsecutiveFour(column) != None:
            result = [[0, 0], [0, 0], [0, 0], [0, 0]]
            result[0][1] = result[1][1] = result[2][1] = result[3][1] = j
            k = isConsecutiveFour(column)
        
            result[0][0] = k
            result[1][0] = k + 1
            result[2][0] = k + 2
            result[3][0] = k + 3
   
            return result        
        
    # Check major diagonal (lower part)   
    for i in range(numberOfRows - 3):
        numberOfElementsInDiagonal = min(numberOfRows - i, numberOfColumns)    
        diagonal = []
        for k in range(numberOfElementsInDiagonal):
            diagonal.append(values[k + i][k])
      
        if isConsecutiveFour(diagonal) != None:
            result = [[0, 0], [0, 0], [0, 0], [0, 0]]
            k = isConsecutiveFour(diagonal)       
            result[0][0] = k + i
            result[1][0] = k + 1 + i
            result[2][0] = k + 2 + i
            result[3][0] = k + 3 + i
            result[0][1] = k
            result[1][1] = k + 1
            result[2][1] = k + 2
            result[3][1] = k + 3  
            return result      
    
    # Check major diagonal (upper part)
    for j in range(1, numberOfColumns - 3):
        numberOfElementsInDiagonal = min(numberOfColumns - j, numberOfRows)    
        diagonal = []
        diagonal.append(values[k][k + j])
      
        if isConsecutiveFour(diagonal) != None:
            result = [[0, 0], [0, 0], [0, 0], [0, 0]]
            k = isConsecutiveFour(diagonal)       
            result[0][0] = k
            result[1][0] = k + 1
            result[2][0] = k + 2
            result[3][0] = k + 3
            result[0][1] = k + j 
            result[1][1] = k + 1 + j
            result[2][1] = k + 2 + j 
            result[3][1] = k + 3 + j  
            return result        

    # Check sub-diagonal (left part)
    for j in range(3, numberOfColumns):
        numberOfElementsInDiagonal = min(j + 1, numberOfRows)    
        diagonal = []
      
        for k in range(numberOfElementsInDiagonal):
            diagonal.append(values[k][j - k])
      
        if isConsecutiveFour(diagonal) != None:
            result = [[0, 0], [0, 0], [0, 0], [0, 0]]
            k = isConsecutiveFour(diagonal)    
            result[0][0] = k
            result[1][0] = k + 1
            result[2][0] = k + 2
            result[3][0] = k + 3
            result[0][1] = j - k
            result[1][1] = j - k - 1
            result[2][1] = j - k - 2 
            result[3][1] = j - k - 3  
            return result
    
    # Check sub-diagonal (right part)
    for i in range(1, numberOfRows - 3):
        numberOfElementsInDiagonal = min(numberOfRows - i, numberOfColumns)     
        diagonal = []
    
        for k in range(numberOfElementsInDiagonal):
            diagonal.append(values[k + i][numberOfColumns - k - 1])
    
        if isConsecutiveFour(diagonal) != None:
            result = [[0, 0], [0, 0], [0, 0], [0, 0]]
            k = isConsecutiveFour(diagonal)        
            result[0][0] = k + i
            result[1][0] = k + i + 1
            result[2][0] = k + i + 2
            result[3][0] = k + i + 3
            result[0][1] = numberOfColumns - k - 1 
            result[1][1] = numberOfColumns - (k + 1) - 1
            result[2][1] = numberOfColumns - (k + 2) - 1
            result[3][1] = numberOfColumns - (k + 3) - 1  
            return result;        

    return None

def isConsecutiveFour(values):   
    for i in range(len(values) - 3):
        isEqual = True     
        for j in range(i, i + 3):
            if values[j] != values[j + 1]:
                isEqual = False
                break
     
        if isEqual:
            return i

    return None
                                               
window = Tk() # Create a window
window.title("Consecutive Four") # Set a title

frame = Frame(window)
frame.pack()

v = []
entries = []
for i in range(6):
    v.append([])
    entries.append([])
    for j in range(7):
        v[i].append(IntVar())
        entries[i].append(Entry(frame, textvariable = v[i][j], width = 2))
        entries[i][j].grid(row = i, column = j)

Button(window, text = "Solve", command = solve).pack()
        
window.mainloop() # Create an event loop
