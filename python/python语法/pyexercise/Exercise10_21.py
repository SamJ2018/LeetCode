def main():
    # Declare a constant value for the number of lockers
    NUMBER_OF_LOCKER = 100

    # Create an array to store the status of each array
    # The first student closed all lockers, each lockers[i] is false
    lockers = NUMBER_OF_LOCKER * [False]
    
    # Each student changes the lockers
    for j in range(1, NUMBER_OF_LOCKER + 1):
      # Student Sj changes every jth locker
      # starting from the lockers[j - 1].
      for i in range(j - 1, NUMBER_OF_LOCKER, j):
        lockers[i] = not lockers[i]

    # Find which one is open
    for i in range(NUMBER_OF_LOCKER):
        if lockers[i]:
            print("Locker", i + 1, "is open")
        
main()
