x0, y0, x1, y1, x2, y2 = eval(input("Enter three points for p0, p1, and p2: "))

status = (x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0)
    
if status > 0:
    print("p2 is on the left side of the line")
elif status == 0:
    print("p2 is on the same line")
else:
    print("p2 is on the right side of the line")
