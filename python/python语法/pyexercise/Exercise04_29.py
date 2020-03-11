x1, y1, r1 = eval(input("Enter circle1's center x-, y-coordinates, and radius: "))

x2, y2, r2 = eval(input("Enter circle2's center x-, y-coordinates, and radius: "))
    
distance = ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) ** 0.5
if distance + r2 <= r1:
    print("circle2 is inside circle1")
elif distance <= r1 + r2:
    print("circle2 overlaps circle1")
else:
    print("circle2 does not overlap circle1")
