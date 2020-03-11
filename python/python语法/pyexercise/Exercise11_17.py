# Read the number of banks and limit
line1 = input().split()
n = eval(line1[0])
limit = eval(line1[1])
    
balances = [] # Balance for each bank
loan = [] # loan[i][j] is the amount bank i loans to bank j
for i in range(n):
    loan.append(n * [0])
        
for i in range(0, n):   
    # Read each line
    line = input().split()   
    balances.append(eval(line[0])) # Bank i's balance
    numberOfBorrowers = eval(line[1]) # Number of banks borrowing from bank i
    loan.append([])
    for j in range(0, numberOfBorrowers):
        k = eval(line[2 + j * 2]) # Bank k borrows from bank i
        loan[i][k] = eval(line[2 + j * 2 + 1]) # the loan amount of Bank k borrowing from bank i
    
asset = n * [0] # asset[i] is bank i's total asset
isSafe = n * [True] # All banks are safe initially
    
print("Unsafe banks: ", end = "")
newUnsafeFound = True # Indicate whether a new unsafe bank is discovered
while newUnsafeFound:
      newUnsafeFound = False # Assume no new unsafe banks are found
      for i in range(0, n):
        asset[i] = balances[i]
        for j in range(0, n):
          asset[i] += loan[i][j]
        
        if isSafe[i] and asset[i] < limit:
          isSafe[i] = False
          newUnsafeFound = True
          # Remove bank i is unsafe 
          print(i, end = " ")
          
          for k in range(0, n):
            loan[k][i] = 0 # Bank i's borrowed loans are gone
