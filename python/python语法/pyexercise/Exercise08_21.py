class Complex:
    def __init__(self, a = 0, b = 0):
        self.__a = a
        self.__b = b

    def getA(self):
        return self.__a

    def getB(self):
        return self.__b

    def __add__(self, secondComplex):
        newA = self.__a + secondComplex.getA()
        newB = self.__b + secondComplex.getB()
        return Complex(newA, newB)

    def __sub__(self, secondComplex):
        newA = self.__a - secondComplex.getA()
        newB = self.__b - secondComplex.getB()
        return Complex(newA, newB)

    def __mul__(self, secondComplex):
        newA = self.__a * secondComplex.getA() - self.__b * secondComplex.getB()
        newB = self.__b * secondComplex.getA() + self.__a * secondComplex.getB()
        return Complex(newA, newB)

    def __truediv__(self, secondComplex):
       newA = ((self.__a * secondComplex.getA() + self.__b * secondComplex.getB()) / 
               (secondComplex.getA() ** 2.0 + secondComplex.getB() ** 2.0))
       newB = ((self.__b * secondComplex.getA() - self.__a * secondComplex.getB()) / 
               (secondComplex.getA() ** 2.0 + secondComplex.getB() ** 2.0))
       return Complex(newA, newB)
   
    def __abs__(self):
       return (self.__a * 2 + self.__b * 2) ** 0.5

    def __str__(self):
        return "(" + str(self.__a) + " + " + str(self.__b) + "i)"

    def getRealPart(self):
        return self.__a

    def getImaginaryPart(self):
        return self.__b

def main():
    a, b = eval(input("Enter the first complex number: "))
    c1 = Complex(a, b)

    c, d = eval(input("Enter the second complex number: "))
    c2 = Complex(c, d)

    print(c1, "+", c2, "=", c1 + c2)
    print(c1, "-", c2, "=", c1 - c2)
    print(c1, "*", c2, "=", c1 * c2)
    print(c1, "/", c2, "=", c1 / c2)
    print("|" + str(c1) + "| = " + str(abs(c1)))

main()
