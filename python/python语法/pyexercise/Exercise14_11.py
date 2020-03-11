def main():
    filename = input("Enter a filename: ").strip()
    # Open file for input
    infile = open(filename, "r")
    
    s = infile.read().upper()
    countVowels = 0
    countConsonants = 0

    vowels = {'A', 'E', 'I', 'O', 'U'}
    for ch in s:
        if ch in vowels:
            countVowels += 1
        elif ch.isalpha():
            countConsonants += 1

    print("The number of vowels is", countVowels, "and consonants is",
        countConsonants)    

main() # Call the main function
