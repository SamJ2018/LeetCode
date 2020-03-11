import math

def main():
    x1, y1, width1, height1 = eval(input("Enter x1, y1, width1, height1: "))
    x2, y2, width2, height2 = eval(input("Enter x2, y2, width2, height2: "))
    r1 = Rectangle2D(x1, y1, width1, height1)
    r2 = Rectangle2D(x2, y2, width2, height2)
    
    print("Area for r1 is", r1.getArea())
    print("Perimeter for r1 is", r1.getPerimeter())
    
    print("Area for r2 is", r2.getArea())
    print("Perimeter for r2 is", r2.getPerimeter())
    
    print("r1 contains the center of r2?", r1.containsPoint(r2.getX(), r2.getY()))
    print("r1 contains r2?", r1.contains(r2))
    print("r2 in r1?", r2 in r1)
    print("r1 overlaps r2?", r1.overlaps(r2))
    
    print("r1 < r2?", r1 < r2)

class Rectangle2D:
    def __init__(self, x = 0, y = 0, width = 0, height = 0):
        self.x = x
        self.y = y
        self.width = width
        self.height = height

    def getX(self):
        return self.x

    def getY(self):
        return self.y

    def getWidth(self):
        return self.width
    
    def getHeight(self):
        return self.height

    def setHeight(self, x):
        self.x = x

    def setHeight(self, y):
        self.y = y

    def setWidth(self, width):
        self.width = width

    def setHeight(self, height):
        self.height = height

    def getPerimeter(self):
        return 2 * (self.width + self.height)
  
    def getArea(self):
        return self.width * self.height
  
    def containsPoint(self, x, y):
        return abs(x - self.x) <= self.width / 2 and abs(y - self.y) <= self.height / 2
  
    def contains(self, r):    
        return self.containsPoint(r.x - r.width / 2, r.y + r.height / 2) and \
            self.containsPoint(r.x - r.width / 2, r.y - r.height / 2) and \
            self.containsPoint(r.x + r.width / 2, r.y + r.height / 2) and \
            self.containsPoint(r.x + r.width / 2, r.y - r.height / 2)
  
    def overlaps(self, r):  
        return abs(self.x - r.x) <= (self.width + r.width) / 2 and \
            abs(self.y - r.y) <= (self.height + r.height) / 2 

    def __contains__(self, anotherRectangle):
        return self.contains(anotherRectangle)

    def __lt__(self, secondRectangle): 
        return self.__cmp__(secondRectangle) < 0

    def __le__(self, secondRectangle): 
        return self.__cmp__(secondRectangle) <= 0

    def __gt__(self, secondRectangle): 
        return self.__cmp__(secondRectangle) > 0

    def __ge__(self, secondRectangle): 
        return self.__cmp__(secondRectangle) >= 0
   
    # Compare two numbers
    def __cmp__(self, secondRectangle): 
        if self.getArea() > secondRectangle.getArea():
            return 1
        elif self.getArea() < secondRectangle.getArea():
            return -1
        else:
            return 0    
main()
