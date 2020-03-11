def main():
    print(format("taxable", "<15s"), format("Single", "<15s"), format("Married", "<15s"), format("Married", "<15s"), format("Head of", "<15s"))
    print(format("Income", "<15s"), format("", "<15s"), format("Joint", "<15s"), format("Separate", "<15s"), format("a House", "<15s"))
    for taxableIncome in range(50000, 60000 + 1, 50):
        print(format(taxableIncome, "<15d"), format(getTax(0, taxableIncome), "<15d"),
            format(getTax(1, taxableIncome), "<15d"), format(getTax(2, taxableIncome), "<15d"), format(getTax(3, taxableIncome), "<15d"))

def getTax(status, income):
    if status == 0:
        return computeTax(income, 8350, 33950, 82250, 171550, 372950)
    elif status == 1: 
        return computeTax(income, 16700, 67900, 137050, 208850, 372950)
    elif status == 2: 
        return computeTax(income, 8350, 33950, 68525, 104425, 186475)
    elif status == 3: 
        return computeTax(income, 11950, 45500, 117450, 190200, 372950)
    else:
        return 0
  
def computeTax(income, r1, r2, r3, r4, r5):
    tax = 0

    if income <= r1:
      tax = income * 0.10
    elif income <= r2:
      tax = r1 * 0.10 + (income - r1) * 0.15
    elif income <= r3:
      tax = r1 * 0.10 + (r2 - r1) * 0.15 + (income - r2) * 0.25
    elif income <= r4:
      tax = r1 * 0.10 + (r2 - r1) * 0.15 + (r3 - r2) * 0.27 + (income - r3) * 0.28
    elif income <= r5:
      tax = r1 * 0.10 + (r2 - r1) * 0.15 + (r3 - r2) * 0.25 + \
        (r4 - r3) * 0.28 + (income - r4) * 0.33
    else:
      tax = r1 * 0.10 + (r2 - r1) * 0.15 + (r3 - r2) * 0.25 + \
        (r4 - r3) * 0.28 + (r5 - r4) * 0.33 + (income - r5) * 0.35

    return round(tax)

main()
