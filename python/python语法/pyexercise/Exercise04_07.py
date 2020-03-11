# Receive the amount 
amount = eval(input("Enter an amount in float, e.g., 11.56: "))

# Convert the amount to cents
remainingAmount = int(amount * 100)

# Find the number of one dollars
numberOfOneDollars = remainingAmount // 100
remainingAmount = remainingAmount % 100

# Find the number of quarters in the remaining amount
numberOfQuarters = remainingAmount // 25
remainingAmount = remainingAmount % 25

# Find the number of dimes in the remaining amount
numberOfDimes = remainingAmount // 10
remainingAmount = remainingAmount % 10

# Find the number of nickels in the remaining amount
numberOfNickels = remainingAmount // 5
remainingAmount = remainingAmount % 5

# Find the number of pennies in the remaining amount
numberOfPennies = remainingAmount

# Display results
print("Your amount", amount, "consists of")

if numberOfOneDollars > 1:
    print(numberOfOneDollars, "\t dollars")
elif numberOfOneDollars == 1:
    print(numberOfOneDollars, "\t dollar")

if numberOfQuarters > 1:
    print(numberOfQuarters, "\t quarters")
elif numberOfQuarters == 1:
    print(numberOfQuarters, "\t quarter")

if numberOfDimes > 1:
    print(numberOfDimes, "\t dimes")
elif numberOfDimes == 1:
    print(numberOfDimes, "\t dime")

if numberOfNickels > 1:
    print(numberOfNickels, "\t nickels")
elif numberOfNickels == 1:
    print(numberOfNickels, "\t nickel")

if numberOfPennies > 1:
    print(numberOfPennies, "\t pennies")
elif numberOfPennies == 1:
    print(numberOfPennies, "\t penny")
