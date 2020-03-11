def main():
    number = eval(input("Enter a number between 0 and 511: "))
    
    binaryChars = toBinaryChars(number);

    for i in range(1, len(binaryChars) + 1):
        print('H' if binaryChars[i - 1] == '0' else 'T', end = " ")
        if i % 3 == 0: print()

def toBinaryChars(number):
    result =  9 * [' ']

    i = len(result) - 1
    while number != 0:
        if number % 2 == 0:
            result[i] = '0'
            i -= 1
        else:
            result[i] = '1'
            i -= 1            
        number //= 2

    for k in range(i, -1, -1):
        result[k] = '0'

    return result

main()
