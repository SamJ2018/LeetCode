class Account:
    # Construct an Account object 
    def __init__(self, id, balance = 100, annualInterestRate = 0):
        self.__id = id
        self.__balance = balance
        self.__annualInterestRate = annualInterestRate

    def getId(self):
        return self.__id

    def getBalance(self):
        return self.__balance

    def getAnnualInterestRate(self):
        return self.__annualInterestRate

    def getMonthlyInterestRate(self):
        return self.__annualInterestRate / 12

    def setPreviousPrice(self, previousPrice):
        self.previousPrice = previousPrice

    def setCurrentPrice(self, currentPrice):
        self.currentPrice = currentPrice

    def withdraw(self, amount):
        self.__balance -= amount

    def deposit(self, amount):
        self.__balance += amount

    def getMonthlyInterest(self):
        return self.__balance * self.getMonthlyInterestRate()

def main():
    # Create an account with width 4 and height 40 
    account = Account(1122, 20000, 4.5)
    
    account.withdraw(2500)
    account.deposit(3000)
    print("ID is", account.getId())
    print("Balance is", account.getBalance())
    print("Monthly interest rate is", account.getMonthlyInterestRate())
    print("Monthly interest is", account.getMonthlyInterest())
          
main()
