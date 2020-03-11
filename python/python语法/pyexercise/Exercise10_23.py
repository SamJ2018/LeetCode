def main():
    eqn = 3 * [0]
    eqn[0], eqn[1], eqn[2] = eval(input("Enter a, b, c: "))

    roots = 2 * [0]

    numberOfRoots = solveQuadratic(eqn, roots)
    
    if numberOfRoots == 0:
      print("No real roots")
    elif numberOfRoots == 1:
      print("The equation has one root:", roots[0])
    else:
      print("The equation has two roots:", roots[0], "and", roots[1])                                               
  
def solveQuadratic(eqn, roots):
    a = eqn[0]
    b = eqn[1]
    c = eqn[2]
    
    discriminant = b * b - 4 * a * c
    
    if discriminant < 0:
      return 0
    elif discriminant == 0:
      roots[0] = -b + (discriminant ** 0.5) / (2 * a)
      return 1
    else: # (discriminant > 0)
      roots[0] = -b + discriminant ** 0.5 / (2 * a)
      roots[1] = -b - discriminant ** 0.5 / (2 * a)
      return 2

main()
