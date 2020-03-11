import turtle

x, y = eval(input("Enter the coordinates for the center of the rectangle: "))
width = eval(input("Enter the width of the rectangle: "))
height = eval(input("Enter the height of the rectangle: "))

turtle.penup()
turtle.goto(x - width / 2, y - height / 2)
turtle.pendown()
turtle.goto(x + width / 2, y - height / 2)
turtle.goto(x + width / 2, y + height / 2)
turtle.goto(x - width / 2, y + height / 2)
turtle.goto(x - width / 2, y - height / 2)

turtle.hideturtle()

input("Press any key to exit...")
