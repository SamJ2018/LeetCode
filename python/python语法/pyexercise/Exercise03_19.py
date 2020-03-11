import turtle

x1, y1 = eval(input("Enter the first point x, y: "))
x2, y2 = eval(input("Enter the second point x, y: "))

turtle.penup()
turtle.goto(x1, y1)
turtle.pendown()
turtle.write("(" + str(x1) + ", " + str(y1) + ")")
turtle.goto(x2, y2)
turtle.write("(" + str(x2) + ", " + str(y2) + ")")
turtle.hideturtle()

turtle.done()
