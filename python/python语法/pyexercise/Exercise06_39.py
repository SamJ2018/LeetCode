import turtle
import math
from UsefulTurtleFunctions import drawLine

radius = 100
x1 = radius * math.cos(math.pi / 10)
y1 = radius * math.sin(math.pi / 10)

x2 = radius * math.cos(2 * math.pi / 5 + math.pi / 10)
y2 = radius * math.sin(2 * math.pi / 5 + math.pi / 10)

x3 = radius * math.cos(4 * math.pi / 5 + math.pi / 10)
y3 = radius * math.sin(4 * math.pi / 5 + math.pi / 10)

x4 = radius * math.cos(6 * math.pi / 5 + math.pi / 10)
y4 = radius * math.sin(6 * math.pi / 5 + math.pi / 10)

x5 = radius * math.cos(8 * math.pi / 5 + math.pi / 10)
y5 = radius * math.sin(8 * math.pi / 5 + math.pi / 10)

drawLine(x1, y1, x3, y3)
drawLine(x1, y1, x4, y4)
drawLine(x2, y2, x4, y4)
drawLine(x2, y2, x5, y5)
drawLine(x3, y3, x5, y5)

turtle.hideturtle()

turtle.done()