# Return true if point (x2, y2) is on the same  
#  line from (x0, y0) to (x1, y1)  
def onTheSameLine(x0, y0, x1, y1, x2, y2):
    return abs((x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0)) < 0.000000001
  
def sameLine(points):
    for i in range(2, len(points)):
        if not onTheSameLine(points[0][0], points[0][1], 
            points[1][0], points[1][1], points[i][0], points[i][1]):
            return False

    return True

list1 = input("Enter five points: ").split()
points = [[eval(list1[i]), eval(list1[i + 1])] for i in range(0, 9, 2)]
print(points)
      
if sameLine(points):
   print("The five points are on the same line")
else:
   print("The five points are not on the same line")
