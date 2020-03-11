import turtle

turtle.color("green")
turtle.goto(-50, 0)

turtle.penup()
turtle.goto(0, 0)
turtle.pendown()
turtle.color("blue")
turtle.goto(60, 0)

turtle.penup()
turtle.goto(0, 0)
turtle.pendown()
turtle.color("red")
turtle.goto(0, 70)

turtle.color("black")
turtle.penup()
turtle.goto(0, -100)
turtle.pendown()
turtle.circle(100)

turtle.penup()
turtle.goto(-5, 85)
turtle.pendown()
turtle.write(12)
      
turtle.penup()
turtle.goto(90, 0)
turtle.pendown()
turtle.write(3)

turtle.penup()
turtle.goto(-95, 0)
turtle.pendown()
turtle.write(9)

turtle.penup()
turtle.goto(0, -100)
turtle.pendown()
turtle.write(6)

turtle.penup()
turtle.goto(-15, -115)
turtle.pendown()
turtle.write("9:15:00")

turtle.hideturtle()

turtle.done()
