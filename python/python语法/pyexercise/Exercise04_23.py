# Enter a point with two double values
x, y = eval(input("Enter a point with two coordinates: "))

# Compute the horizontal distance to the center of the rectangle
hDistance = (x * x) ** 0.5
    
# Compute the vertical distance to the center of the rectangle
vDistance = (y * y) ** 0.5

if hDistance <= 5 and vDistance <= 2.5:
    print("Point (" + str(x) + ", " + str(y) + ") is in the rectangle")
else:
    print("Point (" + str(x) + ", " + str(y) + ") is not in the rectangle")
