import turtle
import random

width = 120
height = 100

turtle.penup() # Pull the pen up
turtle.goto(width / 2, height / 2)
turtle.pendown() # Pull the pen down
turtle.right(90)
turtle.forward(height)
turtle.right(90)
turtle.forward(width)
turtle.right(90)
turtle.forward(height)
turtle.right(90)
turtle.forward(width)

for i in range(10):
    turtle.penup() # Pull the pen up
    x = random.randint(-50, 50) 
    y = random.randint(-50, 50) 
    turtle.goto(x, y)
    turtle.pendown() # Pull the pen down

    turtle.begin_fill() # Begin to fill color in a shape
    turtle.color("red")
    turtle.circle(3) 
    turtle.end_fill() # Fill the shape

turtle.hideturtle()

turtle.done()
