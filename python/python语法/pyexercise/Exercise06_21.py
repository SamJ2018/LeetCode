def main():
    number = eval(input("Enter a positive number: "))
    print("The square root for", number, "is", sqrt(number))

def sqrt(num):
    nextGuess = 1.0
    lastGuess = 0
    
    while abs(nextGuess - lastGuess) >= 0.00001:
        lastGuess = nextGuess
        nextGuess = (lastGuess + (num / lastGuess)) * 0.5

    return nextGuess;

main()
