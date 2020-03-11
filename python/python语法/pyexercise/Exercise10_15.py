import random

def main():
    # Read numbers as a string from the console
    s = input("Enter numbers: ") 
    items = s.split() # Extracts items from the string
    numbers = [ eval(x) for x in items ] # Convert items to numbers
    
    if isSorted(numbers):
        print("The list is already sorted")
    else:
        print("The list is not sorted")

def isSorted(list):
    for i in range(len(list) - 1):
        if list[i] > list[i + 1]: 
            return False
        
    return True

main()
