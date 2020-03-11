from tkinter import * # Import tkinter

length = 0
x = 0
y = 0

def display():
    global x, y, length
    
    canvas.delete("line")
    # Get the length of a U side
    length = min(width, height)
    for i in range(int(order.get())):
        length /= 2
      
    # Reset start cursor position
    x = length / 2
    y = length / 2
      
    upperU(int(order.get())) # Start recursion    
    
# Display upper U 
def upperU(order):
    if order > 0:
        leftU(order - 1)
        lineNewPosition(0, length)
        upperU(order - 1)
        lineNewPosition(length, 0)
        upperU(order - 1)
        lineNewPosition(0, -length)
        rightU(order - 1)

# Display left U 
def leftU(order):
    if order > 0:
        upperU(order - 1)
        lineNewPosition(length, 0)
        leftU(order - 1)
        lineNewPosition(0, length)
        leftU(order - 1)
        lineNewPosition(-length, 0)
        downU(order - 1)

# Display right U 
def rightU(order):
    if order > 0:
        downU(order - 1)
        lineNewPosition(-length, 0);
        rightU(order - 1);
        lineNewPosition(0, -length)
        rightU(order - 1)
        lineNewPosition(length, 0)
        upperU(order - 1)

# Display down U 
def downU(order):
    if order > 0:
        rightU(order - 1);
        lineNewPosition(0, -length);
        downU(order - 1);
        lineNewPosition(-length, 0);
        downU(order - 1);
        lineNewPosition(0, length);
        leftU(order - 1);

# Draw a line from the current position to the new relative position 
def lineNewPosition(deltaX, deltaY):
    global x, y
    drawLine([x, y], [x + deltaX, y + deltaY])
    x += deltaX
    y += deltaY

def drawLine(p1, p2):
    canvas.create_line(p1[0], p1[1], p2[0], p2[1], tags = "line")

window = Tk() # Create a window
window.title("Hilbert curve") # Set a title

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
