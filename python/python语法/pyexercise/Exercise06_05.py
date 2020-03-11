def main():
    num1, num2, num3 = eval(input("Enter three integers: "))
        
    # Invoke the displaySortedNumbers method to display the 
    # numbers in increasing order
    displaySortedNumbers(num1, num2, num3)

def displaySortedNumbers(num1, num2, num3):
    # Write the code to implement this method
    if num1 > num2:
      num1, num2 = num2, num1

    if num2 > num3:
      num2, num3 = num3, num2

    if num1 > num2:
      num1, num2 = num2, num1

    print("The sorted numbers are", num1, num2, num3)
    
main()
