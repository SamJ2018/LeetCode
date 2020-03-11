monthlyDeposit = eval(input("Enter monthly saving amount: "))

currentValue = monthlyDeposit

# First month value
currentValue = currentValue * (1 + 0.00417)

# Second month value
currentValue = (currentValue + monthlyDeposit) * (1 + 0.05 / 12)

# Third month value
currentValue = (currentValue + monthlyDeposit) * (1 + 0.05 / 12)

# Fourth month value
currentValue = (currentValue + monthlyDeposit) * (1 + 0.05 / 12)

# Fifth month value
currentValue = (currentValue + monthlyDeposit) * (1 + 0.05 / 12)

# Sixth month value
currentValue = (currentValue + monthlyDeposit) * (1 + 0.05 / 12)

print("After the sixth month, the account value is", (int)(currentValue * 100) / 100)
