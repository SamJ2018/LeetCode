from tkinter import * # Import tkinter
import math

def display():
    canvas.delete("line")
    p1 = [width / 2, 10]
    p2 = [10, height - 60]
    p3 = [width - 10, height - 60]
    displayKochSnowFlake(int(order.get()), p1, p2)
    displayKochSnowFlake(int(order.get()), p2, p3)
    displayKochSnowFlake(int(order.get()), p3, p1)
    
# Draw a snow flak with the specified order on one line
def displayKochSnowFlake(order, p1, p2):
    if order == 0:
        # Draw a line
        canvas.create_line(p1, p2, tags = "line")
    else:
        # Get points x, y, z on the edge 
        deltaX = p2[0] - p1[0]
        deltaY = p2[1] - p1[1]

        x = [p1[0] + deltaX / 3, p1[1] + deltaY / 3]
        y = [p1[0] + deltaX * 2 / 3, p1[1] + deltaY * 2 / 3]
        z = [((p1[0] + p2[0]) / 2 + math.cos(math.radians(30)) * (p1[1] - p2[1]) / 3),
          (int)((p1[1] + p2[1]) / 2 + math.cos(math.radians(30)) * (p2[0] - p1[0]) / 3)]

        # Recursively display snow flakes on lines
        displayKochSnowFlake(order - 1, p1, x)
        displayKochSnowFlake(order - 1, x, z)
        displayKochSnowFlake(order - 1, z, y)
        displayKochSnowFlake(order - 1, y, p2)
    
window = Tk() # Create a window
window.title("Koch snowflake") # Set a title

width = 200
height = 250
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
