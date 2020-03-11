pi = 1
sign = 1
    
for i in range(2, 100000 + 1):
    sign = -sign
    pi += sign / (2 * i - 1.0)
       
    if i % 10000 == 0:
        print("i:", i, " PI is ", 4 * pi)
