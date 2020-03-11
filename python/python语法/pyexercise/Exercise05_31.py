# Prompt the user to enter input
year = eval(input("Enter a year: "))
firstDay = eval(input("Enter the first day of the year: "))

startDay = firstDay
numberOfDaysInMonth = 0

# Display calendar for each month
for month in range(1, 12 + 1):
    # Display Calendar title
    print("          ", end = "")
    if month == 1:
        print("January " + str(year))
        numberOfDaysInMonth = 31
    elif month == 2:            
        print("Feburary", year)
        if year % 400 == 0 or (year % 4 == 0 and year % 100 != 0):
            numberOfDaysInMonth = 29
        else:
            numberOfDaysInMonth = 28
    elif month == 3:                           
        print("March", year)
        numberOfDaysInMonth = 31
    elif month == 4:            
        print("April", year)
        numberOfDaysInMonth = 30
    elif (month == 5):            
        print("May", year)
        numberOfDaysInMonth = 31
    elif month == 6:            
        print("June", year)
        numberOfDaysInMonth = 30
    elif month == 7:            
        print("July", year)
        numberOfDaysInMonth = 31
    elif month == 8:            
        print("August", year)
        numberOfDaysInMonth = 31
    elif month == 9:            
        print("September", year)
        numberOfDaysInMonth = 30
    elif month == 10:            
        print("October", year)
        numberOfDaysInMonth = 31
    elif month == 11:            
        print("November", year)
        numberOfDaysInMonth = 30
    elif (month == 12):            
        print("December", year)
        numberOfDaysInMonth = 31

    print("-----------------------------")
    print(" Sun Mon Tue Wed Thu Fri Sat")

    # Pad space before the first day of the month
    i = 0
    for i in range(startDay):
        print("    ", end = "")

    for i in range(1, numberOfDaysInMonth + 1):
        if (i < 10):
            print("   " + str(i), end = "")
        else:
            print("  " + str(i), end = "")

        if ((i + startDay) % 7 == 0):
            print()

    print()
    print()

    # Get the start day for the next month
    startDay = (startDay + numberOfDaysInMonth) % 7
