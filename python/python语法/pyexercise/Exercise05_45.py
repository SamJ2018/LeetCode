decimal = eval(input("Enter an integer: "))
    
hexString = ""
value = decimal
while value != 0:
    single = value % 16
      
    if single == 15: 
        hexString = "F" + hexString
    elif single == 14:
        hexString = "E" + hexString
    elif single == 13:
        hexString = "D" + hexString
    elif single == 12:
        hexString = "C" + hexString
    elif single == 11:
        hexString = "B" + hexString
    elif single == 10:
        hexString = "A" + hexString
    else:
        hexString = str(single) + hexString

    value = value // 16
        
print(str(decimal) + "'s hex representation is " + hexString)
