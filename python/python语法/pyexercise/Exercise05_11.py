# Prompt the user to enter the number of students
numberOfStudents = eval(input("Enter the number of students: "))

student1 = input("Enter a student name: ")
score1 = eval(input("Enter a student score: "))

student2 = input("Enter a student name: ")
score2 = eval(input("Enter a student score: "))

# Make sure that student1 is for the highest 
# and student2 is for the second highest
if score1 < score2:
    # Swap
    student1, student2 = student2, student1
    score1, score2 = score2, score1

    for i in range(numberOfStudents - 2):
        student = input("Enter a student name: ")
        score = eval(input("Enter a student score: "))

        if score > score1:
             # new student becomes the highest
             student1, student2 = student, student1 # student1 now is the second highest
             score1, score2 = score, score1
        elif score > score2:
             student2 = student # new student becomes the second highest
             score2 = score

    print("Top two students:")
    print(student1 + "'s score is " + str(score1))
    print(student2 + "'s score is " + str(score2))
