import math

def main():
    side = eval(input("Enter the side: "))
    print("The area of the pentagon is", getArea(side))
  
def getArea(side):
    # Compute the area
    area = 5 * side * side / math.tan(math.pi / 5) / 4
    
    return area

main()
