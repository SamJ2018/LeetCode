from tkinter import * # Import tkinter
    
def display():
    canvas.delete("line")
    p1 = [width / 2, 10]
    p2 = [10, height - 10]
    p3 = [width - 10, height - 10]
    displayTriangles(int(order.get()), p1, p2, p3)

def displayTriangles(order, p1, p2, p3):
    if order == 0: # Base condition
        # Draw a triangle to connect three points
        canvas.create_polygon(p1, p2, p3, tags = "line")
    else:    
        # Get the midpoint on each edge in the triangle
        p12 = midpoint(p1, p2)
        p23 = midpoint(p2, p3)
        p31 = midpoint(p3, p1)

        # Recursively display three triangles
        displayTriangles(order - 1, p1, p12, p31)
        displayTriangles(order - 1, p12, p2, p23)
        displayTriangles(order - 1, p31, p23, p3)
    
# Return the midpoint between two points
def midpoint(p1, p2):
    p = 2 * [0]
    p[0] = (p1[0] + p2[0]) / 2
    p[1] = (p1[1] + p2[1]) / 2
    return p

window = Tk() # Create a window
window.title("Sierpinski Triangle") # Set a title

width = 200
height = 200
canvas = Canvas(window, width = width, height = height)
canvas.pack()

# Add a button, a check button, and a radio button to frame1
frame1 = Frame(window) # Create and add a frame to window
frame1.pack()

Label(frame1, text = "Enter an order").pack(side = LEFT)
order = StringVar()
entry = Entry(frame1, textvariable = order, 
              justify = RIGHT).pack(side = LEFT)
Button(frame1, text = "Display SierpinskiTriangle", 
    command = display).pack(side = LEFT)

window.mainloop() # Create an event loop
