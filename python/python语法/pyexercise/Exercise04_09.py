weight1, price1 = eval(input("Enter weight and price for package 1: "))
weight2, price2 = eval(input("Enter weight and price for package 2: "))

if price1 * 1.0 / weight1 >= price2 * 1.0 / weight2:
    print("Package 1 has the best price.")
else:
    print("Package 2 has the best price.")
