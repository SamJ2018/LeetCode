import math

n = eval(input("Enter the number of sides: "))
side = eval(input("Enter the side: "))
area = n * side * side / math.tan(math.pi / n) / 4

print("The area of the polygon is", area)
