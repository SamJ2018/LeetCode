class Account:
    # Construct an Account object 
    def __init__(self, id, balance = 100, annualInterestRate = 0):
        self.id = id
        self.balance = balance
        self.annualInterestRate = annualInterestRate

    def getId(self):
        return self.id

    def getBalance(self):
        return self.balance

    def getAnnualInterestRate(self):
        return self.annualInterestRate

    def getMonthlyInterestRate(self):
        return self.annualInterestRate / 12

    def setPreviousPrice(self, previousPrice):
        self.previousPrice = previousPrice

    def setCurrentPrice(self, currentPrice):
        self.currentPrice = currentPrice

    def withdraw(self, amount):
        self.balance -= amount

    def deposit(self, amount):
        self.balance += amount

    def getMonthlyInterest(self):
        return self.balance * self.getMonthlyInterestRate()
    
def withdraw():
    amount = eval(input("Enter an amount to withdraw: "))
    if amount <= accounts[id].getBalance():
        accounts[id].withdraw(amount)
    else:
        print("The amount is too large, ignored")

def deposit():
    amount = eval(input("Enter an amount to deposit: "))
    if amount >= 0:
        accounts[id].deposit(amount)
    else:
        print("The amount is negative, ignored")

def getAChoice():
    while True:
        print("\nMain menu");
        print("1: check balance");
        print("2: withdraw");
        print("3: deposit");
        print("4: exit");
        print("Enter a choice: ", end = "");
        choice = eval(input())
        if choice < 1 or choice > 4:
            print("Wrong choice, try again: ", end = "")
        else:
            break

    return choice

# Create 10 accounts
accounts = []
for i in range(10): 
    accounts.append(Account(i, 100))

while True:
   id = eval(input("Enter an account id: "))
   if id < 1 or id > 10:
      print("Please enter a correct id")
      continue;

   while True:
        choice = getAChoice()

        if choice == 1:
            print("The balance is", format(accounts[id].getBalance(), ".2f"))
        elif choice == 2:
            withdraw()
        elif choice == 3:
            deposit()
        elif choice == 4:
            break 
