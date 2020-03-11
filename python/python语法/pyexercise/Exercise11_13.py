def main():
    numberOfRows, numberOfColumns = \
        eval(input("Enter the number of rows and columns of the list: "))
    
    a = []
    for i in range(numberOfRows):
        s = input("Enter a row : ") 
        items = s.split() # Extracts items from the string
        list = [ eval(x) for x in items ] # Convert items to numbers   
        a.append(list)
    
    location = locateLargest(a)
    print("The location of the largest element is at ("
        + str(location[0]) + ", " + str(location[1]) + ")")
  
def locateLargest(a):
    location = 2 * [0]
    
    largest = a[0][0]
    for i in range(len(a)):
        for j in range(len(a[i])):
            if largest < a[i][j]:
               largest = a[i][j]
               location[0] = i
               location[1] = j

    return location

main()
