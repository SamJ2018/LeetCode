def main():
    # Prompt the user to enter filenames
    f1 = input("Enter a filename: ").strip()

    # Open files for input 
    infile = open(f1, "r")
    
    s = infile.read() # Read all from the file
    
    removedString = input("Enter a string to be removed: ").strip()
    
    newS = s.replace(removedString, "")
    
    infile.close()  # Close the input file
    outfile = open(f1, "w")
    
    print(newS, file = outfile, end = "") # Write to the file
    print(str(len(newS)) + " characters are copied ") 

    outfile.close() # Close the output file

main()
