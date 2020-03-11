# Prompt the user to enter input
month = eval(input("Enter a month in the year (e.g., 1 for Jan): "))

year = eval(input("Enter a year: "))

numberOfDaysInMonth = 0;

if month == 1:
    print("January", year, end = "")
    numberOfDaysInMonth = 31;
elif month == 2:
    print("February", year, end = "")
    if year % 400 == 0 or (year % 4 == 0 and year % 100 != 0):
        numberOfDaysInMonth = 29;
    else:
        numberOfDaysInMonth = 28;
elif month == 3:
    print("March", year, end = "")
    numberOfDaysInMonth = 31;
elif month == 4:
    print("April", year, end = "")
    numberOfDaysInMonth = 30;
elif month == 5:
    print("May", year, end = "")
    numberOfDaysInMonth = 31;
elif month == 6:
    print("June", year, end = "")
    numberOfDaysInMonth = 30;
elif month == 7:
    print("July", year, end = "")
    numberOfDaysInMonth = 31;
elif month == 8:
    print("August", year, end = "")
    numberOfDaysInMonth = 31;
elif month == 9:
    print("September", year, end = "")
    numberOfDaysInMonth = 30;
elif month == 10:
    print("October", year, end = "")
    numberOfDaysInMonth = 31;
elif month == 11:
    print("November", year, end = "")
    numberOfDaysInMonth = 30;
else:
    print("December", year, end = "")
    numberOfDaysInMonth = 31;

print(" has", numberOfDaysInMonth, "days")
