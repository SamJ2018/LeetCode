countPositive = 0
countNegative = 0
count = 0
total = 0

num = eval(input(
    "Enter an integer, the input ends if it is 0: "))
    
while num != 0:
    if num > 0:
        countPositive += 1
    elif num < 0:
        countNegative += 1

    total += num
    count += 1
      
    # Read the next number
    num = eval(input(
        "Enter an integer, the input ends if it is 0: "))

if count == 0:
    print("No numbers are entered except 0")
else:
    print("The number of positives is", countPositive)
    print("The number of negatives is", countNegative)
    print("The total is", total)
    print("The average is", total / count)