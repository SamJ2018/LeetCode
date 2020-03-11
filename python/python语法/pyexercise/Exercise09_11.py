from tkinter import * # Import tkinter
import math 
from datetime import datetime

class MainGUI:
    def __init__(self):
        window = Tk() # Create a window
        window.title("Current Time") # Set a title
        
        width = 200
        height = 200
        radius = width / 2.4
        secondHandLength = radius * 0.8
        minuteHandLength = radius * 0.65
        hourHandLength = radius * 0.5
        
        canvas = Canvas(window, bg = "white", width = width, height = height)
        canvas.pack()
        canvas.create_oval(width / 2 - radius, height / 2 - radius, 
                width / 2 + radius, height / 2 + radius)
        canvas.create_text(width / 2 - radius + 5, height / 2, text = "9")
        canvas.create_text(width / 2 + radius - 5, height / 2, text = "3")
        canvas.create_text(width / 2, height / 2 - radius + 5, text = "12")
        canvas.create_text(width / 2, height / 2 + radius - 5, text = "6")
        
        d = datetime.now()
        
        xCenter = width / 2
        yCenter = height / 2
        second = d.second
        xSecond = xCenter + secondHandLength * math.sin(second * (2 * math.pi / 60))
        ySecond = yCenter - secondHandLength * math.cos(second * (2 * math.pi / 60))
        canvas.create_line(xCenter, yCenter, xSecond, ySecond, fill = "red")
        
        minute = d.minute
        xMinute = xCenter + minuteHandLength * math.sin(minute * (2 * math.pi / 60))
        yMinute = yCenter - minuteHandLength * math.cos(minute * (2 * math.pi / 60))
        canvas.create_line(xCenter, yCenter, xMinute, yMinute, fill = "blue")
        
        hour = d.hour % 12
        xHour = xCenter + hourHandLength * math.sin((hour + minute / 60) * (2 * math.pi / 12))
        yHour = yCenter - hourHandLength * math.cos((hour + minute / 60) * (2 * math.pi / 12))
        canvas.create_line(xCenter, yCenter, xHour, yHour, fill = "green")
        
        timestr = str(hour) + ":" + str(minute) + ":" + str(second)
        canvas.create_text(width / 2, height / 2 + radius + 10, text = timestr)
        
        window.mainloop() # Create an event loop

MainGUI()
