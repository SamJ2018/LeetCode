year = eval(input("Enter year: (e.g., 2008): "))
month = eval(input("Enter month: 1-12: "))

if month == 1:
    month = 13
    year = year - 1 # January is counted as month 13 of the previous year.
elif month == 2:
    month = 14
    year = year - 1 # February is counted as month 14 of the previous year.
    
dayOfMonth = eval(input("Enter the day of the month: 1-31: "))
    
j = year // 100
k = year % 100
    
dayOfWeek = (dayOfMonth + 26 * (month + 1) // 10 + k + k // 4 + j // 4 + 5 * j) % 7
    
if dayOfWeek == 0:
    print("Day of the week is Saturday")
elif dayOfWeek == 1: 
    print("Day of the week is Sunday")
elif dayOfWeek == 2:
    print("Day of the week is Monday")
elif dayOfWeek == 3: 
    print("Day of the week is Tuesday")
elif dayOfWeek == 4: 
    print("Day of the week is Wednesday")
elif dayOfWeek == 5: 
    print("Day of the week is Thursday")
elif dayOfWeek == 6: 
    print("Day of the week is Friday")
