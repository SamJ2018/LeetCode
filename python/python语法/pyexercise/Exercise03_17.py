import turtle

x1, y1, x2, y2, x3, y3 = eval(input("Enter three points for a triangle: "))

turtle.penup()
turtle.goto(x1, y1)
turtle.pendown()
turtle.write("p1 (" + str(x1) + ", " + str(y1) + ")")
turtle.goto(x2, y2)
turtle.write("p2 (" + str(x2) + ", " + str(y2) + ")")
turtle.goto(x3, y3)
turtle.write("p3 (" + str(x3) + ", " + str(y3) + ")")
turtle.goto(x1, y1)

# Compute the length of the three sides
side1 = ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) ** 0.5
side2 = ((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3)) ** 0.5
side3 = ((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2)) ** 0.5

# Compute triangle area
s = (side1 + side2 + side3) / 2
area = (s * (s - side1) * (s - side2) * (s - side3)) ** 0.5

turtle.penup()
turtle.goto(min(x1, x2, x3), min(y1, y2, y3) - 20)
turtle.pendown()

turtle.write("The area of the triangle is " + str(area))  
  
turtle.hideturtle()

input("Press any key to exit...")
