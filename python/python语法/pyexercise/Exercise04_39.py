import turtle

x1, y1, r1 = eval(input("Enter circle1's center x-, y-coordinates, and radius: "))
x2, y2, r2 = eval(input("Enter circle2's center x-, y-coordinates, and radius: "))

# Draw circle 1
turtle.penup()
turtle.goto(x1, y1 - r1)
turtle.pendown()
turtle.circle(r1)

# Draw circle 2
turtle.penup()
turtle.goto(x2, y2 - r2)
turtle.pendown()
turtle.circle(r2)

turtle.penup()
turtle.goto(x1 - r1, y1 - r1 - 30)
turtle.pendown()

distance = ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) ** 0.5
if distance + r2 <= r1:
    turtle.write("circle2 is inside circle1")
elif distance <= r1 + r2:
    turtle.write("circle2 overlaps circle1")
else:
    turtle.write("circle2 does not overlap circle1")
        
turtle.hideturtle()

turtle.done()
