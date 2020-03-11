from tkinter import * # Import tkinter
import math

def display():
    canvas.delete("line")
    paintBranch(int(depth.get()), width / 2, height - 10,
                    height / 3, math.pi / 2)

angleFactor = math.pi / 5
sizeFactor = 0.58

def paintBranch(depth, x1, y1, length, angle):
    if depth >= 0:
        x2 = x1 + math.cos(angle) * length
        y2 = y1 - math.sin(angle) * length

        # Draw the line
        drawLine([x1, y1], [x2, y2])

        # Draw the left branch
        paintBranch(depth - 1, x2, y2, length * sizeFactor, angle + angleFactor)
        # Draw the right branch
        paintBranch(depth - 1, x2, y2, length * sizeFactor, angle - angleFactor)

def drawLine(p1, p2):
    canvas.create_line(p1[0], p1[1], p2[0], p2[1], tags = "line")

window = Tk() # Create a window
window.title("Recursive Tree") # Set a title

width = 200
height = 200
canvas = Canvas(window, width = width, height = height)
canvas.pack()

# Add a label, an entry, and a button to frame1
frame1 = Frame(window) # Create and add a frame to window
frame1.pack()

Label(frame1, text = "Enter the depth").pack(side = LEFT)
depth = StringVar()
entry = Entry(frame1, textvariable = depth, 
              justify = RIGHT).pack(side = LEFT)
Button(frame1, text = "Display", 
    command = display).pack(side = LEFT)

window.mainloop() # Create an event loop
