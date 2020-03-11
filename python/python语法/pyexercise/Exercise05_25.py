N = 50000

# Backward computing
sum = 0.0
for i in range(N, 0, -1):
    sum += 1.0 / i
print("The result of the backward computation", sum)
    
# Forward computing
sum1 = 0.0
for i in range(1, N + 1):
    sum1 += 1.0 / i
print("The result of the forward computation", sum1)

difference = sum - sum1
print("difference is", difference)