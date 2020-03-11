def main():
    s = input("Enter numbers separated by spaces from one line: ") 
    items = s.split() # Extracts items from the string
    numbers = [ eval(x) for x in items ] # Convert items to numbers
    
    longestSequenceCount = 0
    longestSequenceValue = 0
    longestSequenceIndex = 0
    
    currentLongestSequenceCount = 1
    currentLongestSequenceValue = 0

    previous = numbers[0]    
    for index in range(len(numbers)):
        if numbers[index] == previous:
            currentLongestSequenceCount += 1
        elif currentLongestSequenceCount > longestSequenceCount:
            longestSequenceCount = currentLongestSequenceCount
            longestSequenceValue = currentLongestSequenceValue
            longestSequenceIndex = index - currentLongestSequenceCount
            
            currentLongestSequenceCount = 1
            currentLongestSequenceValue = numbers[index]       
          
        previous = numbers[index]
    
    print("The longest same number sequence starts at index " 
        + str(longestSequenceIndex) + " with " + str(longestSequenceCount) 
        + " values of " + str(longestSequenceValue))
    
main()
