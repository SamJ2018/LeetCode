import math

class RegularPolygon:
    def __init__(self, n = 3, side = 1, x = 0, y = 0):
        self.__n = n
        self.__side = side
        self.__x = x
        self.__y = y

    def getN(self):
        return self.__n

    def getSide(self):
        return self.__side

    def getX(self):
        return self.__x

    def getY(self):
        return self.__y

    def setN(self, n):
        self.__n = n

    def setSide(self, side):
        self.__side = side

    def setX(self, x):
        self.__x = x

    def setY(self, y):
        self.__y = y

    def getPerimeter(self):
        return self.__n * self.__side

    def getArea(self):
        return self.__n * self.__side * self.__side / math.tan(math.pi / self.__n) / 4

def main():
    polygon1 = RegularPolygon()
    polygon2 = RegularPolygon(6, 4)
    polygon3 = RegularPolygon(10, 4, 5.6, 7.8)
    
    print("Polygon 1 perimeter:", polygon1.getPerimeter())
    print("Polygon 1 area:", polygon1.getArea())
    print("Polygon 2 perimeter:", polygon2.getPerimeter())
    print("Polygon 2 area:", polygon2.getArea())
    print("Polygon 3 perimeter:", polygon3.getPerimeter())
    print("Polygon 3 area:", polygon3.getArea())
          
main()
