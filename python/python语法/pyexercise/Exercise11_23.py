def main():
    n = 6
    matrix = []
    
    # Prompt the user for input
    print("Enter a 6-by-6 matrix: ");
    for i in range(n):
        line = input().split()
        matrix.append([eval(x) for x in line])
    
    if isEvenParity(matrix):
        print("All rows and columns are even")
    else:
        location = locateACell(matrix)
        print("The first row and column where the parity is violated is at ("
        + str(location[0]) + ", " + str(location[1]) + ")")
  
def isEvenParity(matrix):
    for i in range(len(matrix)):
        sum = 0
        for j in range(len(matrix[i])):
            sum += matrix[i][j]
        if sum % 2 != 0:
            return False
    
    for j in range(len(matrix[0])):
        sum = 0
        for i in range(len(matrix)):
            sum += matrix[i][j]
        if sum % 2 != 0:
            return False
        
    return True
  
def locateACell(matrix):
    result = [0, 0]
    for i in range(len(matrix)):
        sum = 0
        for j in range(len(matrix[i])):
            sum += matrix[i][j]
        if sum % 2 != 0:
            result[0] = i
            break
    
    for j in range(len(matrix[0])):
        sum = 0
        for i in range(len(matrix)):
            sum += matrix[i][j]
        if sum % 2 != 0:
            result[1] = j
            break
 
    return result

main()
