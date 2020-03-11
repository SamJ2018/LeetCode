def main():
    x1, y1, x2, y2 = eval(input("Enter the endpoints of the first line segment: "))
    x3, y3, x4, y4 = eval(input("Enter the endpoints of the second line segment: "))

    # Build a 2 by 2 linear equation
    a = (y1 - y2)
    b = (-x1 + x2)
    c = (y3 - y4)
    d = (-x3 + x4)
    e = -y1 * (x1 - x2) + (y1 - y2) * x1
    f = -y3 * (x3 - x4) + (y3 - y4) * x3

    equation = LinearEquation(a, b, c, d, e, f)

    if equation.isSolvable():
        print("The intersecting point is: (" +
              str(equation.getX()) + ", " + str(equation.getY()) + ")")
    else:
        print("The two lines do not cross ")
        
class LinearEquation:
    def __init__(self, a, b, c, d, e, f):
        self.__a = a
        self.__b = b
        self.__c = c
        self.__d = d
        self.__e = e
        self.__f = f

    def getA(self):
        return self.__a

    def getB(self):
        return self.__b
    
    def getC(self):
        return self.__c
    
    def getD(self):
        return self.__d

    def getE(self):
        return self.__e
    
    def getF(self):
        return self.__f
    
    def getElapsedTime(self):
        return int(1000 * (self.__endTime - self.startTime))


    def isSolvable(self):
        return self.__a * self.__d - self.__b * self.__c != 0

    def getX(self):
        return (self.__e * self.__d - self.__b * self.__f) / (self.__a * self.__d - self.__b * self.__c)

    def getY(self):
        return (self.__a * self.__f - self.__e * self.__c) / (self.__a * self.__d - self.__b * self.__c)

main()
