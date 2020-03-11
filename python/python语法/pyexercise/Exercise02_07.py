# Obtain input
minutes = eval(input("Enter the number of minutes: "))

numberOfDays = minutes // (24 * 60)
numberOfYears = numberOfDays // 365

# Display results
print(minutes, "minutes is approximately",
    numberOfYears, "years and", numberOfDays % 365, "days")
