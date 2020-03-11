import sys

# Prompt the user to enter the number of lines
numberOfLines = eval(input("Enter the number of lines: "))

if numberOfLines < 1 or numberOfLines > 15:
    print("You must enter a number from 1 to 15")
    sys.exit(0)

# Print lines
for row in range(1, numberOfLines + 1):
    # Print (NUMBER_OF_LINES - row) leading spaces
    for column in range(1, numberOfLines - row + 1):
        print("   ", end = "")

    # Print leading numbers row, row - 1, ..., 1
    for num in range(row, 0, -1):
        print(format(num, "3d"), end = "")

    # Print ending numbers 2, 3, ..., row - 1, row
    for num in range(2, row + 1):
        print(format(num, "3d"), end = "")

    # Start a new line
    print()
