import turtle

x = -120
y = 100

# Draw header
turtle.penup() # Pull the pen up
turtle.goto(x, y)
turtle.pendown() # Pull the pen down
turtle.write("Multiplication Table", font = ("Courier", 14, "bold"))

x = -180
y -= 30
line = "     "
# Draw first line
turtle.penup() # Pull the pen up
turtle.goto(x, y)
turtle.pendown() # Pull the pen down
for i in range(1, 10):
    line += str(i) + "  "
turtle.write(line, font = ("Courier", 14, "bold"))

y -= 20

# Draw separators
turtle.penup() # Pull the pen up
turtle.goto(x, y)
turtle.pendown() # Pull the pen down
turtle.write(32 * "-", font = ("Courier", 14, "bold"))

y -= 20
line = "1 |"
for i in range(1, 10):
    for j in range(1, 10): 
        line += (" " if i * j > 9 else "  ") + str(i * j)

    # Draw a line
    turtle.penup() # Pull the pen up
    turtle.goto(x, y)
    turtle.pendown() # Pull the pen down
    turtle.write(line, font = ("Courier", 14, "bold"))

    line = str(i + 1 ) + " |"
    y -= 20

turtle.hideturtle()

turtle.done()
