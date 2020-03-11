import random

def main():
    infile = open("hangman.txt", "r")
    words = infile.read().split()
    
    while True:
        index = random.randint(0, len(words) - 1)
        hiddenWord = words[index]

        guessedWord = len(hiddenWord) * ['*']

        numberOfCorrectLettersGuessed = 0
        numberOfMisses = 0

        while numberOfCorrectLettersGuessed < len(hiddenWord):
            letter = input("(Guess) Enter a letter in word " + toString(guessedWord) + " > ").strip()

            if letter in guessedWord:
                print("\t" + letter + " is already in the word")
            elif hiddenWord.find(letter) < 0:
                print("\t" + letter + " is not in the word")
                numberOfMisses += 1
            else:
                k = hiddenWord.find(letter)
                while k >= 0:
                    guessedWord[k] = letter
                    numberOfCorrectLettersGuessed += 1
                    k = hiddenWord.find(letter, k + 1)

        print("The word is " + hiddenWord + ". You missed "
                + str(numberOfMisses) + (" time" if numberOfMisses <= 1 else " times"))

        anotherGame = input("Do you want to guess for another word? Enter y or n> ").strip()
        if anotherGame == 'n':
            print("Finished")
            break

def toString(list):
    s = ""
    for e in list:
        s += e
    return s

main()
