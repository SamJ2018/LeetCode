import turtle
import random
import UsefulTurtleFunctions

width = 100
height = 100

UsefulTurtleFunctions.drawRectangle(-75, 0, width, height)

for i in range(10):
    x = random.randint(-75 - width / 2, -75 + width / 2) 
    y = random.randint(-height / 2, height / 2) 
    UsefulTurtleFunctions.drawPoint(x, y)

radius = 50
UsefulTurtleFunctions.drawCircle(50, 0, radius)
count = 0
while count < 10:
    x = random.randint(50 - radius, 50 + radius) 
    y = random.randint(-radius, radius) 
    if ((x - 50) * (x - 50) + y * y) ** 0.5 <= radius:
        UsefulTurtleFunctions.drawPoint(x, y)
        count += 1

turtle.hideturtle()

turtle.done()
