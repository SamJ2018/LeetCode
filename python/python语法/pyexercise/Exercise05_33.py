deposit = eval(input("Enter the initial deposit amount: "))
annualInterestRate = eval(input("Enter annual percentage yield: "))
monthlyInterestRate = annualInterestRate / 1200

numberOfMonths = eval(input("Enter maturity period (number of months): "))

print(format("Month", "15s"), format("CS Value", "20s"))
currentValue = deposit
for i in range(1, numberOfMonths + 1):
    currentValue = currentValue * (1 + monthlyInterestRate)
    print(format(i, "15d"), format(currentValue, "20.2f"))
