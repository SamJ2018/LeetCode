def main():
    totalMilliseconds = eval(input("Enter time in milliseconds: "))
    print(convertMillis(totalMilliseconds))

def convertMillis(millis):
    # Obtain the total seconds since the midnight, Jan 1, 1970
    totalSeconds = millis // 1000

    # Compute the current second in the minute in the hour
    seconds = totalSeconds % 60

    # Obtain the total minutes
    totalMinutes = totalSeconds // 60

    # Compute the current minute in the hour
    minutes = totalMinutes % 60

    # Obtain the total hours
    hours = totalMinutes // 60

    # Display results
    return str(hours) + ":" + str(minutes) + ":" + str(seconds)

main()
