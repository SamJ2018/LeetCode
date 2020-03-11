def main():
    s = input("Enter a string: ").strip().upper()

    for ch in s:
        if ch.isalpha():
            print(getNumber(ch), end = "")
        else:
            print(ch, end = "")
            
def getNumber(uppercaseLetter):
    number = 0
    
    if uppercaseLetter == 'A' or uppercaseLetter == 'B' or uppercaseLetter == 'C':
        number = 2
    elif uppercaseLetter == 'D' or uppercaseLetter == 'E' or uppercaseLetter == 'F':
        number = 3
    elif uppercaseLetter == 'G' or uppercaseLetter == 'H' or uppercaseLetter == 'I':
        number = 4
    elif uppercaseLetter == 'J' or uppercaseLetter == 'K' or uppercaseLetter == 'L':
        number = 5
    elif uppercaseLetter == 'M' or uppercaseLetter == 'N' or uppercaseLetter == 'O':
        number = 6
    elif uppercaseLetter == 'P' or uppercaseLetter == 'Q' or uppercaseLetter == 'R' or uppercaseLetter == 'S':
        number = 7
    elif uppercaseLetter == 'T' or uppercaseLetter == 'U' or uppercaseLetter == 'V':
        number = 8
    elif uppercaseLetter == 'W' or uppercaseLetter == 'X' or uppercaseLetter == 'Y' or uppercaseLetter == 'Z':
        number = 9

    return number

main()
