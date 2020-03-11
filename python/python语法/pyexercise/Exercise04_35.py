import turtle

x1, y1, x2, y2, x3, y3 = eval(input("Enter three points for p0, p1, and p2: "))

turtle.penup()
turtle.goto(x1, y1)
turtle.pendown()
turtle.write("p1 (" + str(x1) + ", " + str(y1) + ")")
turtle.goto(x2, y2)
turtle.write("p2 (" + str(x2) + ", " + str(y2) + ")")

status = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1)

# Display the point    
turtle.penup()
turtle.goto(x3, y3)
turtle.pendown()
turtle.begin_fill()
turtle.circle(5)
turtle.end_fill()
    
turtle.penup()
turtle.goto(x3 - 80, y3 - 20)
turtle.pendown()

if status > 0:
    turtle.write("p2 is on the left side of the line")
elif status == 0: 
    turtle.write("p2 is on the same line")
else:
    turtle.write("p2 is on the right side of the line")
    
turtle.hideturtle()

turtle.done()
