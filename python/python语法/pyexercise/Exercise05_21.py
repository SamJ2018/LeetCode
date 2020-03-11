number = 0 # Number to print

for row in range(7 + 1):
    # Pad leading blanks
    for col in range(1, 7 - row + 1):
        print("    ", end = "")

    # Print left half of the row
    for col in range(row + 1):
        number = 2 ** col
        print(format(number, "4d"), end = "")


    # Print the right half of the row
    for col in range(row - 1, 0 - 1, -1):
        number = 2 ** col
        print(format(number, "4d"), end = "")

    # Start a new line
    print();
