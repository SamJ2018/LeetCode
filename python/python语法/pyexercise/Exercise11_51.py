def main():
    s = input("Enter students' names and scores: ") 
    items = s.split() # Extracts items from the string
    # Convert items to a list
    students = [[eval(items[i + 1]), items[i]] for i in range(len(items), 2)] 
    students.sort()
    
    for e in students:
        print(e[1] + "\t" + str(e[0]))

main()
