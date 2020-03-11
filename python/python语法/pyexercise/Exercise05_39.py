# The commission sought
COMMISSION_SOUGHT = 25000
INITIAL_SALES_AMOUNT = 0.01
commission = 0
salesAmount = INITIAL_SALES_AMOUNT

while commission < COMMISSION_SOUGHT:
    # Increase salesAmount by 1 cent
    salesAmount += 0.01

    # Compute the commission from the current salesAmount
    if salesAmount >= 10000.01:
        commission = 5000 * 0.08 + 5000 * 0.1 + (salesAmount - 10000) * 0.12
    elif salesAmount >= 5000.01:
        commission = 5000 * 0.08 + (salesAmount - 5000) * 0.10
    else:
        commission = salesAmount * 0.08

# Display the sales amount
print("The sales amount $" + str(int(salesAmount * 100) / 100.0) + \
      "\nis needed to make a commission of $" + str(COMMISSION_SOUGHT))
