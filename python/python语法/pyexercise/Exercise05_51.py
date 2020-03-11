import turtle

# Draw 16 by 16 lattice
x = -80
for y in range(-80, 80 + 1, 10):
    turtle.penup()
    turtle.goto(x, y)
    turtle.pendown()
    turtle.forward(160)

y = 80
turtle.right(90)
for x in range(-80, 80 + 1, 10):
    turtle.penup()
    turtle.goto(x, y)
    turtle.pendown()
    turtle.forward(160)

turtle.hideturtle()

turtle.done()
