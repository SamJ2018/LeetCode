import sys

# Prompt the user to enter the first number
number = eval(input("Enter a number (0: for end of input): "))
    
if number == 0:
    print("No numbers are entered except 0")
    sys.exit()
    
max = number
count = 1

# Prompt the user to enter the remaining numbers
while number != 0:
    number = eval(input("Enter a number (0: for end of input): "))

    if number > max:
        max = number
        count = 1
    elif number == max:
        count += 1
        
print("The largest number is", max, "\n",
      "The occurrence count of the largest number is", count)
