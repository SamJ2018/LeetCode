decimal = eval(input("Enter a decimal value (0 to 15): "))
    
if decimal > 15 or decimal < 0:
    print("Invalid input")
elif decimal < 10:
    print("The hex value is", decimal)
else: 
    print("The hex value is", chr(ord('A') + decimal - 10))
