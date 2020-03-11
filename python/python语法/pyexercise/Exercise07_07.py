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
  
def main():
    a, b, c, d, e, f = eval(input("Enter a, b, c, d, e, f: "))

    equation = LinearEquation(a, b, c, d, e, f)

    if equation.isSolvable():
        print("x is", equation.getX(), "and y is", equation.getY())
    else:
        print("The equation has no solution")
        
main()
