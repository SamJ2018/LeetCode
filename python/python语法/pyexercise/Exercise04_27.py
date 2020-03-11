x, y = eval(input("Enter a point's x- and y-coordinates: "))

if x > 200 or x < 0 or y > 100 or y < 0:
    print("The point is not in the triangle")
else:
    slope = (200.0 - 0) / (0 - 100.0)
    x1 = x + -y * slope
    if x1 <= 200:
        print("The point is in the triangle")
    else:
        print("The point is not in the triangle")
