import math

def main():
    # Read numbers as a string from the console
    s = input("Enter numbers: ") 
    items = s.split() # Extracts items from the string
    numbers = [ eval(x) for x in items ] # Convert items to numbers

    # Display mean and deviation
    print("The mean is", mean(numbers))
    print("The standard deviation is", deviation(numbers))

# Compute the deviation of values
def deviation(x):
    average = mean(x)
    squareSum = 0

    for value in x:
      squareSum += (value - average) ** 2

    return math.sqrt(squareSum / (len(x) - 1))

# Compute the mean of a list of values
def mean(x):
    sum = 0

    for value in x:
      sum += value

    return sum / len(x)

main()
