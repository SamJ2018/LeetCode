import random

def main():
    # Read numbers as a string from the console
    s = input("Enter numbers: ") 
    items = s.split() # Extracts items from the string
    numbers = [ eval(x) for x in items ] # Convert items to numbers
    
    print("The distinct numbers are:", eliminateDuplicates(numbers))

def eliminateDuplicates(list):
    result = []
    for element in list:
        if not (element in result): 
            result.append(element)

    return result

main()
