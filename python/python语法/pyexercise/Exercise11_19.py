import sys

def main():
    matrix = []
    
    numberOfRows = eval(input("Enter the number of rows: ").strip())
    numberOfColumns = eval(input("Enter the number of column: ").strip())

    for i in range(numberOfRows):
        s = input("Enter row " + str(i) + ": ") 
        items = s.split() # Extracts items from the string
        list = [ eval(x) for x in items ] # Convert items to numbers   
        
        if len(list) != numberOfColumns:
            print("Wrong column size")
            sys.exit(0)
            
        matrix.append(list)
        
    print(isConsecutiveFourInMatrix(matrix))

def isConsecutiveFourInMatrix(values): 
    numberOfRows = len(values)
    numberOfColumns = len(values[0])

    # Check rows
    for i in range(numberOfRows):
        if isConsecutiveFour(values[i]):
            return True

    # Check columns
    for j in range(numberOfColumns):
        column = []
        # Get a column into an array
        for i in range(numberOfRows):
            column.append(values[i][j])
      
        if isConsecutiveFour(column):
            return True

    # Check major diagonal (lower part)   
    for i in range(numberOfRows - 3):
        numberOfElementsInDiagonal = min(numberOfRows - i, numberOfColumns)     
        diagonal = []
        for k in range(numberOfElementsInDiagonal):
            diagonal.append(values[k + i][k])
      
        if isConsecutiveFour(diagonal):
            return True
    
    # Check major diagonal (upper part)
    for j in range(1, numberOfColumns - 3):
        numberOfElementsInDiagonal = min(numberOfColumns - j, numberOfRows)   
        diagonal = []
        for k in range(numberOfElementsInDiagonal):
            diagonal.append(values[k][k + j])
      
        if isConsecutiveFour(diagonal):
            return True

    # Check sub-diagonal (left part)
    for j in range(3, numberOfColumns):
        numberOfElementsInDiagonal = min(j + 1, numberOfRows)   
        diagonal = []
      
        for k in range(numberOfElementsInDiagonal):
            diagonal.append(values[k][j - k])
      
        if isConsecutiveFour(diagonal):
            return True
    
    # Check sub-diagonal (right part)
    for i in range(1, numberOfRows - 3):
        numberOfElementsInDiagonal = min(numberOfRows - i, numberOfColumns)    
        diagonal = []
    
        for k in range(numberOfElementsInDiagonal):
            diagonal.append(values[k + i][numberOfColumns - k - 1])
    
        if isConsecutiveFour(diagonal):
            return True
    
    return False
  
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
