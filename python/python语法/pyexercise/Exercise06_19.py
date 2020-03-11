def main():
    x0, y0, x1, y1, x2, y2 = eval(input("Enter three points for p0, p1, and p2: "))
    
    if leftOfTheLine(x0, y0, x1, y1, x2, y2):
        print("(" + str(x2) + ", " + str(y2) + ") is on the left side of the line from"
            + " (" + str(x0) + ", " + str(y0) + ") to " + "(" + str(x1) + ", " + str(y1) + ")")
    elif onTheLineSegment(x0, y0, x1, y1, x2, y2):
        print("(" + str(x2) + ", " + str(y2) + ") is on the line segment from"
            + " (" + str(x0) + ", " + str(y0) + ") to " + "(" + str(x1) + ", " + str(y1) + ")");      
    elif onTheSameLine(x0, y0, x1, y1, x2, y2):
        print("(" + str(x2) + ", " + str(y2) + ") is on the same line from"
            + " (" + str(x0) + ", " + str(y0) + ") to " + "(" + str(x1) + ", " + str(y1) + ")");      
    else:
        print("(" + str(x2) + ", " + str(y2) + ") is on the right side of the line from"
            + " (" + str(x0) + ", " + str(y0) + ") to " + "(" + str(x1) + ", " + str(y1) + ")")      
  
# Return true if point (x2, y2) is on the left side of the 
#  directed line from (x0, y0) to (x1, y1)  
def leftOfTheLine(x0, y0, x1, y1, x2, y2):
    return (x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0) > 0

# Return true if point (x2, y2) is on the same  
#  line from (x0, y0) to (x1, y1)  
def onTheSameLine(x0, y0, x1, y1, x2, y2):
    return abs((x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0)) < 0.000000001
  
# Return true if point (x2, y2) is on the
# line segment from (x0, y0) to (x1, y1)  
def onTheLineSegment(x0, y0, x1, y1, x2, y2):
    return onTheSameLine(x0, y0, x1, y1, x2, y2) and ((x0 <= x2 and x2 <= x1) or (x0 >= x2 and x2 >= x1))

main()
