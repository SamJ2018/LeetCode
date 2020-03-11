def main():
    s = input("Enter integers separated by spaces from one line: ") 
    items = s.split() # Extracts items from the string
    numbers = [ eval(x) for x in items ] # Convert items to numbers

    if isConsecutiveFour(numbers):
        print("The series has consecutive fours")
    else:
        print("The series has no consecutive fours")

def isConsecutiveFour(values):   
    for i in range(len(values) - 3):
        isEqual = True    
        for j in range(i, i + 3):
            if values[j] != values[j + 1]:
                isEqual = False
                break
     
        if isEqual: 
            return True
    
    return False
        
main()
