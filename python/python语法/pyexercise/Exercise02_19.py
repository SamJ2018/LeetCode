# Enter the investment amount
investmentAmount = eval(input("Enter the investment amount, for example 120000.95: "))

# Enter yearly interest rate
annualInterestRate = eval(input("Enter annual interest rate, for example 8.25: "))
# Obtain monthly interest rate
monthlyInterestRate = annualInterestRate / 1200

# Enter number of years
numOfYears = eval(input("Enter number of years as an integer, for example 5: "))

futureValue = investmentAmount * (1 + monthlyInterestRate) ** (numOfYears * 12)

print("Future value is", int(futureValue * 100) / 100.0)