from tkinter import * # Import tkinter
import math

class Rectangle2D:
    def __init__(self, x = 0, y = 0, width = 0, height = 0):
        self.x = x
        self.y = y
        self.width = width
        self.height = height

    def getX(self):
        return self.x

    def getY(self):
        return self.y

    def setX(self, x):
        self.x = x

    def setY(self, y):
        self.y = y

    def getWidth(self):
        return self.width
    
    def getHeight(self):
        return self.height

    def setHeight(self, x):
        self.x = x

    def setHeight(self, y):
        self.y = y

    def setWidth(self, width):
        self.width = width

    def setHeight(self, height):
        self.height = height

    def getPerimeter(self):
        return 2 * (self.width + self.height)
  
    def getArea(self):
        return self.width * self.height
  
    def containsPoint(self, x, y):
        return abs(x - self.x) <= self.width / 2 and abs(y - self.y) <= self.height / 2
  
    def contains(self, r):    
        return self.containsPoint(r.x - r.width / 2, r.y + r.height / 2) and \
            self.containsPoint(r.x - r.width / 2, r.y - r.height / 2) and \
            self.containsPoint(r.x + r.width / 2, r.y + r.height / 2) and \
            self.containsPoint(r.x + r.width / 2, r.y - r.height / 2)
  
    def overlaps(self, r):  
        return abs(self.x - r.x) <= (self.width + r.width) / 2 and \
            abs(self.y - r.y) <= (self.height + r.height) / 2 

def displayRectangle(r, text):
    canvas.delete(text)
    canvas.create_rectangle(r.x - r.width / 2, r.y - r.height/ 2, r.x + r.width / 2,
        r.y + r.height/ 2, tags = text)
    canvas.create_text(r.x, r.y, text = text, tags = text)
            
def mouseMoved(event):
    if r1.containsPoint(event.x, event.y):
        r1.setX(event.x)
        r1.setY(event.y)
        displayRectangle(r1, "r1")
        if r1.overlaps(r2):
            label["text"] = "Two rectangles intersect"
        else:
            label["text"] = "Two rectangles don't intersect"
    elif r2.containsPoint(event.x, event.y):
        r2.setX(event.x)
        r2.setY(event.y)
        displayRectangle(r2, "r2")
        if r1.overlaps(r2):
            label["text"] = "Two rectangles intersect"
        else:
            label["text"] = "Two rectangles don't intersect"
            
window = Tk() # Create a window
window.title("Two Rectangles") # Set title

width = 300
height = 100
label = Label(window, text = "Two rectangles intersect" )
label.pack()
canvas = Canvas(window, width = width, height = height)
canvas.pack()

canvas.bind("<B1-Motion>", mouseMoved)
r1 = Rectangle2D(10, 10, 30, 50)
r2 = Rectangle2D(50, 70, 30, 30)
displayRectangle(r1, "r1")
displayRectangle(r2, "r2")

window.mainloop() # Create an event loop
