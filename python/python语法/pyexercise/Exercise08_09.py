def main():
    s = input("Enter a binary number: ").strip()
    print("The hex value is", convertBinaryToHex(s))

def convertBinaryToHex(binaryValue):
    decimalValue = binaryToDecimal(binaryValue)
    return decimalToHex(decimalValue)

def binaryToDecimal(binaryString):
    value = ord(binaryString[0]) - ord('0')
    for i in range(1, len(binaryString)):
        value = value * 2 + ord(binaryString[i]) - ord('0')

    return value

# Convert a decimal to a hex as a string 
def decimalToHex(decimal):
    hex = ""
    
    while decimal != 0:
        hexValue = decimal % 16; 
        hex = toHexChar(hexValue) + hex
        decimal = decimal // 16
    
    return hex
  
# Convert an integer to a single hex digit in a character 
def toHexChar(hexValue):
    if hexValue <= 9 and hexValue >= 0:
        return chr(hexValue + ord('0'))
    else: # hexValue <= 15 && hexValue >= 10
        return chr(hexValue - 10 + ord('A'))

main()
