def main():
    # Prompt the user to enter filenames
    f1 = input("Enter a filename: ").strip()

    # Open files for input 
    infile = open(f1, "r")
    
    s = infile.read() # Read all from the file

    scores = [ eval(x) for x in s.split() ]
    print(scores)
        
    print("There are " + str(len(s)) + " scores") 
    print("The total is " + str(sum(scores)))
    print("The average is " + str(sum(scores) / len(scores))) 
    
    infile.close() # Close the output file

main()
