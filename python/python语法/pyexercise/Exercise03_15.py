import turtle

turtle.penup()
turtle.goto(0, -70)
turtle.pendown()
turtle.circle(70) 

turtle.penup()
turtle.goto(28, -25)
turtle.pendown()
turtle.setheading(60)
turtle.circle(30, steps = 3) 

turtle.penup()
turtle.goto(-30, 20)
turtle.setheading(0)
turtle.pendown()
turtle.begin_fill() # Begin to fill color in a shape
turtle.circle(10) # Draw the left eye
turtle.end_fill() # Fill the shape

turtle.penup()
turtle.goto(30, 20)
turtle.pendown()
turtle.begin_fill() # Begin to fill color in a shape
turtle.circle(10) # Draw the right eye
turtle.end_fill() # Fill the shape

turtle.penup()
turtle.goto(0, -50)
turtle.setheading(30)
turtle.pendown()
turtle.forward(50)

turtle.penup()
turtle.goto(0, -50)
turtle.setheading(150)
turtle.pendown()
turtle.forward(50)

turtle.hideturtle()

turtle.done()
