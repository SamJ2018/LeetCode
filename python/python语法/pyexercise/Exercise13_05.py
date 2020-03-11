def main():
    # Prompt the user to enter filenames
    f1 = input("Enter a filename: ").strip()

    # Open files for input 
    infile = open(f1, "r")
    
    s = infile.read() # Read all from the file
    
    oldString = input("Enter the old string to be replaced: ").strip()
    newString = input("Enter the new string to replace the old string: ").strip()
    
    newS = s.replace(oldString, newString)
    
    infile.close()  # Close the input file
    outfile = open(f1, "w")
    
    print(newS, file = outfile, end = "") # Write to the file
    print("Done") 

    outfile.close() # Close the output file

main()
