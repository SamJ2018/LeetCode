number = eval(input("Enter an integer: "))

d1 = number % 10
number = number // 10

d2 = number % 10
number = number // 10

d3 = number % 10
number = number // 10

d4 = number % 10
number = number // 10

print(d4)
print(d3)
print(d2)
print(d1)
