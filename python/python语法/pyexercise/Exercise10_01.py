def main():
    # Read numbers as a string from the console
    s = input("Enter scores separated by spaces from one line: ") 
    items = s.split() # Extracts items from the string
    scores = [ eval(x) for x in items ] # Convert items to numbers

    best = 0 # The best score
    for i in range(len(scores)):      
        if scores[i] > best:
            best = scores[i]

    # Initialize output string
    output = ""

    # Assign and display grades
    for i in range(len(scores)):      
        if scores[i] >= best - 10:
            grade = 'A'
        elif scores[i] >= best - 20:
            grade = 'B'
        elif scores[i] >= best - 30:
            grade = 'C'
        elif scores[i] >= best - 40:
            grade = 'D'
        else:
            grade = 'F'

        print("Student", i, "score is", scores[i], "and grade is", grade)
        
main()
