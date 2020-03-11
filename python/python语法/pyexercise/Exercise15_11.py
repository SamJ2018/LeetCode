def main():
    s = input("Enter a string: ").strip()
    reverseDisplay(s)

def reverseDisplay(value):
    reverseDisplayHelper(value, len(value) - 1)

def reverseDisplayHelper(value, high):
    if high >= 0:
        print(value[high], end = "")
        reverseDisplayHelper(value, high - 1)

main()
