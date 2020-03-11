def main():
    line = input("Enter x1, y1, x2, y2, x3, y3, x4, y4: ").split()
    p = [[eval(line[i]), eval(line[i + 1])] for i in range(0, 8, 2)]

    points = []
    for i in range(4):
        points.append(2 * [0]) 
    points[0][0] = p[0][0]; points[0][1] = p[0][1];
    points[1][0] = p[2][0]; points[1][1] = p[2][1];
    points[2][0] = p[1][0]; points[2][1] = p[1][1];
    points[3][0] = p[3][0]; points[3][1] = p[3][1];    
    x = getIntersectingPoint(points)
            
    areas = []
    trianglePoints = []
    for i in range(3):
        trianglePoints.append(2 * [0]) 
    
    trianglePoints[0][0] = p[0][0]
    trianglePoints[0][1] = p[0][1]
    trianglePoints[1][0] = p[1][0]
    trianglePoints[1][1] = p[1][1]
    trianglePoints[2][0] = x[0]
    trianglePoints[2][1] = x[1]
    areas.append(getTriangleArea(trianglePoints))
    
    trianglePoints[0][0] = p[2][0]; trianglePoints[0][1] = p[2][1]
    trianglePoints[1][0] = p[1][0]; trianglePoints[1][1] = p[1][1]
    areas.append(getTriangleArea(trianglePoints))

    trianglePoints[0][0] = p[2][0]; trianglePoints[0][1] = p[2][1]
    trianglePoints[1][0] = p[3][0]; trianglePoints[1][1] = p[3][1]
    areas.append(getTriangleArea(trianglePoints))

    trianglePoints[0][0] = p[0][0]; trianglePoints[0][1] = p[0][1]
    trianglePoints[1][0] = p[3][0]; trianglePoints[1][1] = p[3][1]
    areas.append(getTriangleArea(trianglePoints))

    print("The areas are ")
    areas.sort()
    for i in range(4):
        print(str(areas[i]) + " ")

def getTriangleArea(points):
    x1, y1, x2, y2, x3, y3 = points[0][0], points[0][1], \
        points[1][0], points[1][1], points[2][0], points[2][1]  

    # Compute the length of the three sides
    side1 = ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) ** 0.5
    side2 = ((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3)) ** 0.5
    side3 = ((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2)) ** 0.5

    s = (side1 + side2 + side3) / 2;
    temp = s * (s - side1) * (s - side2) * (s - side3)
    area = temp ** 0.5

    if temp < 0 or temp <= 0.0000000000001: return None
    else: return area

def linearEquation(a, b):
    determinant = a[0][0] * a[1][1] - a[0][1] * a[1][0]
    
    if determinant == 0:
        return None
    else:
        x = (b[0] * a[1][1] - b[1] * a[0][1]) / determinant
        y = (b[1] * a[0][0] - b[0] * a[1][0]) / determinant
        return [x, y]

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
