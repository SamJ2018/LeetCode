def main():
    decimal = eval(input("Enter a decimal integer: "))
    print(str(decimal) + " is binary " + decimalToBinary(decimal))

def decimalToBinary(value):
    if value == 0:
        return ""
    else:
        return decimalToBinary(value // 2) + str(value % 2) 

main()
