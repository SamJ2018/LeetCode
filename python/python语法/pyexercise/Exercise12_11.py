from tkinter import * # Import tkinter
import tkinter.messagebox

class DisplaySet(Frame):
    def __init__(self, parent, numbers):
        Frame.__init__(self, parent, borderwidth = 2, relief = SUNKEN)
        for i in range(len(numbers)):
            for j in range(len(numbers[i])):
                Label(self, text = str(numbers[i][j])).grid(row = i, column = j)
        self.v1 = IntVar()
        Checkbutton(self, variable = self.v1).grid(row = i + 1, column = 0) 

    def isChecked(self):
        if self.v1.get() == 1:
            return True
        else:
            return False

def solve():
    day = 0
    for i in range(5):
        if boxes[i].isChecked():
            day += 2 ** i
    tkinter.messagebox.showinfo("Found it", "Your birthday is " + str(day))
    
window = Tk() # Create a window
window.title("Guess Birthday") # Set title

frame1 = Frame(window)
frame1.pack()
Label(frame1, text = "Check the boxes if your birthday is in these sets").pack()

frame2 = Frame(window)
frame2.pack()
boxes = []

boxes.append(DisplaySet(frame2, [[1, 3, 5, 7], [9, 11, 13, 15], [17, 19, 21, 23], [25, 27, 29, 31]]))
boxes[0].pack(side = LEFT)
boxes.append(DisplaySet(frame2, [[2, 3, 6, 7], [10, 11, 14, 15], [18, 19, 22, 23], [26, 27, 29, 31]]))
boxes[1].pack(side = LEFT)
boxes.append(DisplaySet(frame2, [[4, 5, 6, 7], [12, 13, 14, 15], [20, 21, 22, 23], [28, 29, 30, 31]]))
boxes[2].pack(side = LEFT)
boxes.append(DisplaySet(frame2, [[8, 9, 10, 11], [12, 13, 14, 15], [24, 25, 26, 27], [28, 29, 30, 31]]))
boxes[3].pack(side = LEFT)
boxes.append(DisplaySet(frame2, [[16, 17, 18, 19], [20, 21, 22, 23], [24, 25, 26, 27], [28, 29, 30, 31]]))
boxes[4].pack(side = LEFT)

frame3 = Frame(window)
frame3.pack()
Button(frame3, text = "Guess Birthday", command = solve).pack()

window.mainloop() # Create an event loop
