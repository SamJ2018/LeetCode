# Prompt the user to enter an integer for today
today = eval(input("Enter today's day: "))
elapsedDays = eval(input("Enter the number of days elapsed since today: "))
    
if today == 0:
  nameForToday = "Sunday"
elif today == 1:
  nameForToday = "Monday"
elif today == 2:
  nameForToday = "Tuesday"
elif today == 3:
  nameForToday = "Wednesday"
elif today == 4:
  nameForToday = "Thursday"
elif today == 5:
  nameForToday = "Friday"
else: # if today == 6:
  nameForToday = "Saturday"

futureDay = (today + elapsedDays) % 7
if futureDay == 0:
  nameForFutureDay = "Sunday"
elif futureDay == 1:
  nameForFutureDay = "Monday"
elif futureDay == 2:
  nameForFutureDay = "Tuesday"
elif futureDay == 3:
  nameForFutureDay = "Wednesday"
elif futureDay == 4:
  nameForFutureDay = "Thursday"
elif futureDay == 5:
  nameForFutureDay = "Friday"
else: # if futureDay == 6:
  nameForFutureDay = "Saturday"

print("Today is " + nameForToday 
    + " and the future day is " + nameForFutureDay)
