def main():
    SIZE = 3
    print("Enter a 3 by 3 matrix row by row: ")
    m = []
    
    for i in range(SIZE):
        line = input().split()
        m.append([eval(x) for x in line])

    print("The column-sorted list is ")
    printMatrix(sortColumns(m))

def reverse(m):
    for i in range(len(m)):
        for j in range(i, len(m[i])):
            m[i][j], m[j][i] = m[j][i], m[i][j]

def printMatrix(m):
    for i in range(len(m)):
        for j in range(len(m[i])):
            print(m[i][j], end = " ")
        print()
        
def sortColumns(m):
    result = []
    for row in m:
        result.append(row)
    
    reverse(result)
    for row in result:
        row.sort()
    reverse(result)
    
    return result

main()
