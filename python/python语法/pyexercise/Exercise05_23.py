# Enter loan amount
loanAmount = eval(input("Enter loan amount, for example 120000.95: "))

# Enter number of years
numOfYears = eval(input("Enter number of years as an integer, for example 5: "))

# Display the header
print("{0:<20s}{1:<20s}{2:<20s}".format("Interest Rate", "Monthly Payment", "Total Payment"))

annualInterestRate = 5.0
while annualInterestRate <= 8.0:
    # Obtain monthly interest rate
    monthlyInterestRate = annualInterestRate / 1200

    # Compute mortgage
    monthlyPayment = loanAmount * monthlyInterestRate /  \
        (1 - (pow(1 / (1 + monthlyInterestRate), numOfYears * 12)))
    totalPayment = monthlyPayment * numOfYears * 12

    # Display results
    print(format(annualInterestRate, ">5.3f"), "%", format(monthlyPayment, "20.2f"), format(totalPayment, "20.2f"))
    annualInterestRate += 1.0 / 8
