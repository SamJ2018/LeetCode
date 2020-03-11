def main():
    investmentAmount = eval(input("Enter investment amount, for example 100: "))
    annualInterestRate = eval(input("Enter yearly interest rate, for example 5.25: "))

    print(format("Years", "10s"), format("Future Value", "20s"))

    for i in range(1, 30 + 1):
        futureValue = \
            futureInvestmentValue(investmentAmount, annualInterestRate / 1200, i)
        print(format(i, "<10d"), format(futureValue, "<20.2f"))

def futureInvestmentValue(investmentAmount, monthlyInterestRate, years):
    return investmentAmount * (1 + monthlyInterestRate) ** (years * 12)

main()
