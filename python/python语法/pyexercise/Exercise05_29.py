count = 1
for year in range(2001, 2100 + 1):
    if year % 400 == 0 or (year % 4 == 0 and year % 100 != 0):
        if count % 10 == 0:
            print(year) 
        else:
            print(year, end = " ")
        
        count += 1
