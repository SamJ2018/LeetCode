from tkinter import * # Import tkinter
import tkinter.messagebox

class StepControl:
    def __init__(self):
        self.list = [ x for x in range(1, 20) ]
        self.reset()
        self.key = 0

    def reset(self):
        self.low = 0
        self.high = len(self.list) - 1
        self.mid = -1
        
        # self.i = -1 # current index 
        self.done = False
        self.drawAStep()

    def step(self):
        if self.done:
            tkinter.messagebox.showinfo("showinfo", "Key is found")
            return
        
        if self.low > self.high:
            tkinter.messagebox.showinfo("showinfo", "Key is not found")
            return

        self.mid = (self.low + self.high) // 2
        self.drawAStep()
        if self.key == self.list[self.mid]:
            tkinter.messagebox.showinfo("showinfo", "Key is found")
            self.done = True;
        elif self.key > self.list[self.mid]:
            self.low = self.mid + 1 # Continue to search the second half
        else: 
            self.high = self.mid - 1 # Continue to search the first half
        
    def drawAStep(self):
        bottomGap = 10
        canvas.delete("line")
        canvas.create_line(10, height - bottomGap, width - 10, height - bottomGap, tag = "line")
        barWidth = (width - 20) / len(self.list)
        
        maxCount = int(max(self.list))
        for i in range(len(self.list)):
            if self.mid >= 0 and self.low <= i <= self.high:
                canvas.create_rectangle(i * barWidth + 10, (height - bottomGap) * (1 - self.list[i] / (maxCount + 4)), 
                    (i + 1) * barWidth + 10, height - bottomGap, fill = "gray", tag = "line")       
            else:
                canvas.create_rectangle(i * barWidth + 10, (height - bottomGap) * (1 - self.list[i] / (maxCount + 4)), 
                    (i + 1) * barWidth + 10, height - bottomGap, tag = "line")       
                         
            canvas.create_text(i * barWidth + 10 + barWidth / 2, (height - bottomGap) * ( 1 - self.list[i] / (maxCount + 4)) - 8, 
                               text = str(self.list[i]), tag = "line")

        if self.mid >= 0:
            canvas.create_rectangle(self.mid * barWidth + 10, (height - bottomGap) * ( 1 - self.list[self.mid] / (maxCount + 4)), 
                                    (self.mid + 1) * barWidth + 10, height - bottomGap, fill = "red", tag = "line")

def step():
    control.key = float(key.get())
    control.step()
    
def reset():
    control.reset()
    
window = Tk() # Create a window
window.title("Binary Search Animation") # Set title

width = 340
height = 150
radius = 2
canvas = Canvas(window, width = width, height = height)
canvas.pack()

frame = Frame(window)
frame.pack()

Label(frame, text = "Enter a key (in float):").pack(side = LEFT)
key = StringVar()
Entry(frame, textvariable = key, justify = RIGHT, width = 3).pack(side = LEFT)
Button(frame, text = "Step", command = step).pack(side = LEFT)
Button(frame, text = "Reset", command = reset).pack(side = LEFT)

control = StepControl()
control.drawAStep()

window.mainloop() # Create an event loop
