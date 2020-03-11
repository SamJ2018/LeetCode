def main():
    i = eval(input("Enter an integer: "))
    print("THe sum of digits in " + str(i) + " is " + str(sumDigits(i)))

def sumDigits(n):
    result = 0

    if n != 0:
        result = sumDigits(n // 10) + n % 10

    return result

main()
