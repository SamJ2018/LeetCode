import turtle

width = 100
height = 50
x, y = eval(input("Enter a point with two coordinates x, y: "))

turtle.penup() # Pull the pen up
turtle.goto(50, 25)
turtle.pendown() # Pull the pen down
turtle.right(90)
turtle.forward(height)
turtle.right(90)
turtle.forward(width)
turtle.right(90)
turtle.forward(height)
turtle.right(90)
turtle.forward(width)

turtle.penup() # Pull the pen up
turtle.goto(x, y)
turtle.pendown() # Pull the pen down
turtle.begin_fill() # Begin to fill color in a shape
turtle.color("red")
turtle.circle(3) 
turtle.end_fill() # Fill the shape

turtle.penup() # Pull the pen up
turtle.goto(-90, -55)
turtle.pendown() 

d = (x * x + y * y) ** 0.5

if abs(x) <= width / 2 and abs(y) <= height / 2:
    turtle.write("The point is inside the rectangle") 
else:
    turtle.write("The point is not inside the rectangle") 

turtle.hideturtle()

turtle.done()
