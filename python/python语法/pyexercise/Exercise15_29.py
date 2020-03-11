from tkinter import * # Import tkinter

def display():
    canvas.delete("line")
    p = [width / 2, height / 2]
    length = width / 2
    displayHTree(int(order.get()), p, length)
    
# Draw H-Tree centered at point p
def displayHTree(order, p, length):
    # Locate four endpoints
    p1 = [p[0] - length / 2, p[1] - length / 2]
    p2 = [p[0] + length / 2, p[1] - length / 2]
    p3 = [p[0] - length / 2, p[1] + length / 2]
    p4 = [p[0] + length / 2, p[1] + length / 2]
      
    # Draw three lines in an H-shape
    drawLine(p1, p3)
    drawLine(p2, p4)
    drawLine([p[0] - length / 2, p[1]], [p[0] + length / 2, p[1]])

    if order > 0:
        # Recursively display H-tree
        displayHTree(order - 1, p1, length / 2)
        displayHTree(order - 1, p2, length / 2)
        displayHTree(order - 1, p3, length / 2)
        displayHTree(order - 1, p4, length / 2)

def drawLine(p1, p2):
    canvas.create_line(p1[0], p1[1], p2[0], p2[1], tags = "line")

window = Tk() # Create a window
window.title("H-Tree Fractal") # Set a title

width = 200
height = 200
canvas = Canvas(window, width = width, height = height)
canvas.pack()

# Add a label, an entry, and a button to frame1
frame1 = Frame(window) # Create and add a frame to window
frame1.pack()

Label(frame1, text = "Enter an order").pack(side = LEFT)
order = StringVar()
entry = Entry(frame1, textvariable = order, 
              justify = RIGHT).pack(side = LEFT)
Button(frame1, text = "Display", 
    command = display).pack(side = LEFT)

window.mainloop() # Create an event loop
