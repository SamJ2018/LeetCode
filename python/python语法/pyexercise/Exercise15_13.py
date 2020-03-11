def main():
    s = input("Enter a string: ").strip()
    print("The uppercase letters in " + s + " is " + str(countUppercase(s)))

def countUppercase(s):
    return countUppercaseHelper(s, len(s) - 1)

def countUppercaseHelper(s, high):
    if high < 0:
        return 0
    else:
        return countUppercaseHelper(s, high - 1) + (1 if s[high].isupper() else 0)

main()
