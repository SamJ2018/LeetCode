def main():
    matrix = []
    
    for i in range(3):
        s = input("Enter a 3-by-4 matrix row " + str(i) + ": ") 
        items = s.split() # Extracts items from the string
        list = [ eval(x) for x in items ] # Convert items to numbers   
        matrix.append(list)
        
    for j in range(4):
        print("Sum of the elements at column", j, "is", sumColumn(matrix, j))
    
def sumColumn(m, columnIndex):
    sum = 0
    for i in range(len(m)):
        sum += m[i][columnIndex]
    return sum
        
main()
