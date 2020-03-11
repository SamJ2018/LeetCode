def main():
    s = input("Enter the numbers: ") 
    items = s.split() # Extracts items from the string
    list1 = [ eval(x) for x in items ] # Convert items to numbers

    list2 = []

    for number in list1:
        if not (number in list2):
            list2.append(number)

    print("The distinct numbers are", list2)

main()
