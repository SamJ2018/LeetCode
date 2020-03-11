def main():
    s = input("Enter characters separated by spaces from one line: ").strip()
    items = s.split() # Extracts items from the string
    print("The number of uppercase letters in " + str(items) + " is " + str(count(items)))
    
def count(chars):
    return countHelper(chars, len(chars) - 1)

def countHelper(chars, high):
    if high >= 0:
        return countHelper(chars, high - 1) + (1 if chars[high].isupper() else 0)
    else:
        return 0
    
main()
