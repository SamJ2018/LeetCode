import turtle
import RandomCharacter

# Write text at the specified location
def writeLine(text, x, y):
    turtle.penup() # Pull the pen up
    turtle.goto(x, y)
    turtle.pendown() # Pull the pen down
    turtle.write(line, font = ("Times", 18, "bold"))

x = -130
y = 50
line = ""

for i in range(1, 101):
    line += RandomCharacter.getRandomLowerCaseLetter() + " "
    if i % 15 == 0:
        writeLine(line, x, y)
        line = ""
        y -= 25

turtle.done()
