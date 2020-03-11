class Point:
    def __init__(self, x, y):
        self.__x = x
        self.__y = y
    
    def getX(self):
        return self.__x
    
    def getY(self):
        return self.__y

    # Is point (x, y) close to this point
    def isNearBy(self, p):
        return self.distance(p.getX(), p.getY()) < 5

    def distance(self, x2, y2):
        return ((self.__x - x2) * (self.__x - x2) + (self.__y - y2) * (self.__y - y2)) ** 0.5

    def __str__(self):
        return "(" + str(self.__x) + ", " + self.__y + ")" 

def main():
    x1, y1, x2, y2 = eval(input("Enter two points x1, y1, x2, y2: "))
    print("The distance between the two points is", Point(x1, y1).distance(x2, y2))

    if Point(x1, y1).isNearBy(Point(x2, y2)):
        print("The two points are near to each other")
    else:
        print("The two points are not near to each other")
        
main()
