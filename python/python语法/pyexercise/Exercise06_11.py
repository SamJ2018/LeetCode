def main():
    print(format("salesAmount", "<15s"), format("Commission", "<15s"))

    for salesAmount in range(10000, 100000 + 1, 5000):
        print(format(salesAmount, "<15d"), format(computeCommission(salesAmount), "<15.1f"))

def computeCommission(salesAmount):
    if salesAmount >= 10000.01:
        commission = 5000 * 0.08 + 5000 * 0.1 + (salesAmount - 10000) * 0.12
    elif salesAmount >= 5000.01:
        commission = 5000 * 0.08 + (salesAmount - 5000) * 0.10
    else:
        commission = salesAmount * 0.08

    return commission

main()
