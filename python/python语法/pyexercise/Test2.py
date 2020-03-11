import turtle

turtle.speed(10)
turtle.pensize(3)
turtle.color("purple")
r = 100
turtle.circle(r)

turtle.penup()
turtle.forward(100)

turtle.pendown()

turtle.pensize(3)
turtle.color("red")
turtle.circle(r)

turtle.left(90)
turtle.color("green")
turtle.penup()
turtle.goto(100,100)
turtle.pendown()

r = 50
turtle.circle(r)
turtle.left(90)
turtle.penup()
turtle.forward(51)
turtle.pendown()
turtle.write("25", font=("Arial", 20,"bold"))

turtle.done()
