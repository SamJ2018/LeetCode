def main():
    s = input("Enter the integers between 1 and 100: ") 
    items = s.split() # Extracts items from the string
    numbers = [ eval(x) for x in items ] # Convert items to numbers

    counts = 100 * [0]

    for value in numbers:
        if value <= 100 and value >= 0:
            counts[value - 1] += 1

    # Display result
    for i in range(100): 
        if counts[i] > 0:
            print(i + 1, "occurs", counts[i], "time" if counts[i] == 1 else "times")

main()
