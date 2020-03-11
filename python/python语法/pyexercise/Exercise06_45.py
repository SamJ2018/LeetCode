import turtle
import math

def drawPolygon(x = 0, y = 0, radius = 50, numberOfSides = 3):
    angle = 2 * math.pi / numberOfSides

    turtle.penup()
    turtle.goto(x + radius * math.cos(0 * angle),
                y - radius * math.sin(0 * angle))  
    turtle.pendown()
            
    # Connect points for the polygon
    for i in range(numberOfSides + 1):  
        turtle.goto(x + radius * math.cos(i * angle),
            y - radius * math.sin(i * angle))     

turtle.speed(0) # Fastest   

for i in range(3, 9):
    drawPolygon(i * 2 * 50 - 550, 0, 40, i)

turtle.hideturtle()

turtle.done()
