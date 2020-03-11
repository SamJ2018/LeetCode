import random

def main():
    # Read numbers as a string from the console
    s = input("Enter numbers: ") 
    items = s.split() # Extracts items from the string
    numbers = [ eval(x) for x in items ] # Convert items to numbers
    shuffle(numbers)
    print(numbers)

def shuffle(list):
    for i in range(len(list)):
        index = random.randint(0, len(list) - 1)
        list[i], list[index] = list[index], list[i]

    return list
        
main()
