import math

def main():
    edge1, edge2, edge3 = eval(input("Enter three sides in double: "))

    if isValid(edge1, edge2, edge3):
        print("The area of the triangle is", area(edge1, edge2, edge3))
    else:
        print("Input is invalid")

# Returns true if the sum of any two sides is 
#  greater than the third side. 
def isValid(side1, side2, side3):
    return (side1 + side2 > side3) and \
      (side1 + side3 > side2) and (side2 + side3 > side1)

# Returns the area of the triangle. 
def area(side1, side2, side3):
    s = (side1 + side2 + side3) / 2
    return math.sqrt(s * (s - side1) * (s - side2) * (s - side3))

main()
