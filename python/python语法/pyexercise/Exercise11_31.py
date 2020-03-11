def main():
    x1, y1, x2, y2, x3, y3, x4, y4 = eval(input("Enter x1, y1, x2, y2, x3, y3, x4, y4: "))
    points = []
    points.append([x1, y1])
    points.append([x2, y2])
    points.append([x3, y3])
    points.append([x4, y4])
    
    result = getIntersectingPoint(points)
    
    if result == None:
        print("The two lines are parallel")
    else:
        print("The intersecting point is at (" + str(result[0]) + ", " +  str(result[1]) + ")")

def linearEquation(a, b):
    determinant = a[0][0] * a[1][1] - a[0][1] * a[1][0]
    
    if determinant == 0:
        return None
    else:
        result = []
        x = (b[0] * a[1][1] - b[1] * a[0][1]) / determinant
        y = (b[1] * a[0][0] - b[0] * a[1][0]) / determinant
        result.append(x)
        result.append(y)
        return result

def getIntersectingPoint(points):
    x1, y1, x2, y2, x3, y3, x4, y4 = points[0][0], points[0][1], \
        points[1][0], points[1][1], points[2][0], points[2][1], points[3][0], points[3][1]
    a = (y1 - y2)
    b = -(x1 - x2)
    c = (y3 - y4)
    d = -(x3 - x4)
    e = (y1 - y2) * x1 - (x1 -x2) * y1
    f = (y3 - y4) * x3 - (x3 -x4) * y3
    
    result = linearEquation([[a, b], [c, d]], [e, f])
        
    if result == None:
        return None
    else:
        return result

main()
