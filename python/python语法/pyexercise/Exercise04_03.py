a, b, c, d, e, f = eval(input("Enter a, b, c, d, e, f: "))

detA = a * d - b * c
    
if detA == 0:
    print("The equation has no solution")
else:
    x = (e * d - b * f) / detA
    y = (a * f- e * c) / detA
    print("x is", x, "and y is", y)
