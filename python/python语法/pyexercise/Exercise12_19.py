from tkinter import * # Import tkinter
import math 

class PieChart(Canvas):
    def __init__(self, parent, data, width = 400, height = 300):
        super().__init__(parent, width = width, height = height)
        self.setData(data)
    
    def setData(self, data):
        self.__data = data
        self.drawPieChart()
        
    def drawPieChart(self):
        values = []
        for x, y, z in self.__data:
            values.append(x)
            
        total = sum(values)
        start = 0
        for i in range(len(self.__data)):
            extent = 360 * self.__data[i][0] / total
            self.drawAPie(start, extent, self.__data[i][1], self.__data[i][2])
            start += extent
            
    def drawAPie(self, start, extent, title, color):
        width = int(self["width"])
        height = int(self["height"])
        radius = min(width, height) * 0.45
        self.create_arc(width / 2 - radius, height / 2 - radius, 
            width / 2 + radius, height / 2 + radius, 
            start = start, extent = extent, fill = color, tags = "bar")
        x = width / 2 + radius * math.cos(math.radians(extent / 2 + start))
        y = height / 2 - radius * math.sin(math.radians(extent / 2 + start))
        self.create_text(x, y, text = title, tags = "bar")
  
class MainGUI:
    def __init__(self):  
        window = Tk() # Create a window
        window.title("Pie Chart") # Set a title
        
        width = 240
        height = 200
        canvas1 = PieChart(window, [[40, "CS", "red"], [30, "IS", "blue"], [50, "IT", "yellow"]], width = width, height = height)
        canvas1.grid(row = 1, column = 1)
        canvas2 = PieChart(window, 
                            [[140, "Freshman", "red"], [130, "Sophomore", "blue"], [150, "Junior", "yellow"], [80, "Senior", "green"]], 
                            width = width, height = height)
        canvas2.grid(row = 1, column = 2)
        
        window.mainloop() # Create an event loop
        
MainGUI()
