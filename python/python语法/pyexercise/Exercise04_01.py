a, b, c = eval(input("Enter a, b, c: "))

discriminant = b * b - 4 * a * c
    
if discriminant < 0:
    print("The equation has no real roots")
elif discriminant == 0:
    r1 = -b / (2 * a)
    print("The root is " + str(r1))
else:
    # (discriminant > 0)
    r1 = (-b + discriminant ** 0.5) / (2 * a)
    r2 = (-b - discriminant ** 0.5) / (2 * a)
    print("The roots are", r1, "and", r2)
