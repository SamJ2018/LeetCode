from tkinter import * # Import tkinter
import math

class RegularPolygonCanvas(Canvas):
    def __init__(self, parent, numberOfSides = 4, width = 150, height = 150):
        super().__init__(parent, width = width, height = height)
        self.setNumberOfSides(numberOfSides)
        
    def getNumberOfSides(self):
        return self.__numberOfSides 

    def setNumberOfSides(self, numberOfSides):
        self.__numberOfSides = numberOfSides
        self.drawPolygon()
        
    def drawPolygon(self):
        self.delete("polygon")
        
        width = int(self["width"])
        height = int(self["height"])
        xCenter = width / 2
        yCenter = height / 2;
        radius = min(width, height) * 0.4

        angle = 2 * math.pi / self.__numberOfSides
    
        # Create a Polygon object
        polygon = []

        # Add points to the polygon
        for i in range(self.__numberOfSides):
            polygon.append([xCenter + radius * math.cos(i * angle),
                           yCenter - radius * math.sin(i * angle)])     
 
        # Draw the polygon
        self.create_polygon(polygon, fill = "red", tags = "polygon")

class MainClass:
    def __init__(self):  
        window = Tk() # Create a window
        window.title("n-sided Polygons") # Set title
        
        self.canvas = RegularPolygonCanvas(window, 3, width = 250, height = 250)
        self.canvas.pack()
        
        frame = Frame(window)
        frame.pack()
        Button(frame, text = "+1", command = self.increase).pack(side = LEFT)
        Button(frame, text = "-1", command = self.decrease).pack(side = LEFT)
        
        window.mainloop() # Create an event loop

    def increase(self):
        self.canvas.setNumberOfSides(self.canvas.getNumberOfSides() + 1)
    
    def decrease(self):
        if self.canvas.getNumberOfSides() > 3:
            self.canvas.setNumberOfSides(self.canvas.getNumberOfSides() - 1)

MainClass()
