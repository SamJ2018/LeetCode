def main():
    binary = input("Enter a binary number: ").strip()
    print(binary + " is decimal " + str(binaryToDecimal(binary)))

def binaryToDecimal(binaryString):
    return binaryToDecimalHelper(binaryString, 0, len(binaryString) - 1)
  
def binaryToDecimalHelper(binaryString, low, high):
    if high < low:
        return 0
    else:
        return binaryToDecimalHelper(binaryString, low, high - 1) * 2 + ord(binaryString[high]) - ord('0')

main()
