count = 1
for i in range(100, 201):
    if not (i % 5 == 0 and i % 6 == 0) and (i % 5 == 0 or i % 6 == 0):
        if count % 10 != 0:
            print(i, end = " ")
        else:
            print(i)    
        
        count += 1
