import math

def distance(x1, y1, x2, y2):
    return math.sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2))

def drawHangman():
    canvas.delete("hangman")
    if hangman.isFinishedWithWrongGuess:
        # Display the guessed word
        canvas.create_text(200, 190, text = "The word is: " + toString(hangman.hiddenWord), 
                           font = "Times 14 ", tags = "hangman")
        canvas.create_text(200, 210, text = "To continue the game, press ENTER", 
                           font = "Times 14 ", tags = "hangman")
    elif hangman.isFinishedWithCorrectGuess:
        # Display the guessed word
        canvas.create_text(200, 190, text = "You got " + toString(hangman.guessedWord), 
                           font = "Times 14 ", tags = "hangman")
        canvas.create_text(200, 210, text = "To continue the game, press ENTER", 
                           font = "Times 14 ", tags = "hangman")       
    else:
        # Display the guessed word
        canvas.create_text(200, 190, text = "Guess a word: " + toString(hangman.guessedWord),
            font = "Times 14 ", tags = "hangman")

        if hangman.numberOfMisses > 0:
            canvas.create_text(200, 210, text = "Missed letters: " + toString(hangman.missedLetters),
                font = "Times 14 ", tags = "hangman")

    canvas.create_arc(20, 200, 20 + 80, 200 + 40, start = 0, extent = 180) # Draw the base
    canvas.create_line(20 + 40, 200, 20 + 40, 20)  # Draw the pole
    canvas.create_line(20 + 40, 20, 20 + 40 + 100, 20) # Draw the hanger
    
    if hangman.numberOfMisses < 1:
        return

    angle = 90 # Start from the middle
    x1 = 20 + 40 + 100
    y1 = 20
    radius = 20
    x = x1 + radius * math.cos(math.radians(angle))
    y = y1 + radius * math.sin(math.radians(angle))
    canvas.create_line(20 + 40 + 100, 20, x, y) # Draw the hanger

    if hangman.numberOfMisses < 2:
        return
    
    # Draw the circle
    length = 20 + 20
    x = x1 + length * math.cos(math.radians(angle))
    y = y1 + length * math.sin(math.radians(angle))
    canvas.create_oval(x - radius, y - radius, x + radius, y + radius) # Draw the hanger

    if hangman.numberOfMisses < 3:
        return
    # Draw the left arm
    length = distance(x1, y1, 20 + 40 + 100 - radius * 
        math.cos(math.radians(45)), 40 + radius + radius * math.sin(math.radians(45)))
    angle1 = math.degrees(math.asin(radius * math.cos(math.radians(45)) / length))
    x2 = x1 + length * math.cos(math.radians(angle + angle1))
    y2 = y1 + length * math.sin(math.radians(angle + angle1))

    length = distance(x1, y1, 20 + 40 + 100 - 60, 40 + radius + 60)
    angle1 = math.degrees(math.asin(60 / length));
    x3 = x1 + length * math.cos(math.radians(angle + angle1))
    y3 = y1 + length * math.sin(math.radians(angle + angle1))

    canvas.create_line(x2, y2, x3, y3)

    if hangman.numberOfMisses < 4:
        return
    # Draw the right arm
    length = distance(x1, y1, 20 + 40 + 100 + radius * math.cos(math.radians(45)), 
        40 + radius + radius * math.sin(math.radians(45)))
    angle1 = -math.degrees(math.asin(radius * math.cos(math.radians(45))
          / length))
    x2 = x1 + length * math.cos(math.radians(angle + angle1))
    y2 = y1 + length * math.sin(math.radians(angle + angle1))

    length = distance(x1, y1, 20 + 40 + 100 + 60, 40 + radius + 60)
    angle1 = -math.degrees(math.asin(60 / length));
    x3 = x1 + length * math.cos(math.radians(angle + angle1))
    y3 = y1 + length * math.sin(math.radians(angle + angle1))

    canvas.create_line(x2, y2, x3, y3)

    if hangman.numberOfMisses < 5:
        return
        
    # Draw the body
    length = 40 + 20
    x2 = x1 + length * math.cos(math.radians(angle))
    y2 = y1 + length * math.sin(math.radians(angle))

    length = 40 + 20 + 60
    x3 = x1 + length * math.cos(math.radians(angle))
    y3 = y1 + length * math.sin(math.radians(angle))

    canvas.create_line(x2, y2, x3, y3)

    if hangman.numberOfMisses < 6:
        return
    
    # Draw the left leg
    length = distance(x1, y1, 20 + 40 + 100 - 40, 40 + radius + 80 + 40)
    angle1 = math.degrees(math.asin(40.0 / length))
    x4 = x1 + length * math.cos(math.radians(angle + angle1))
    y4 = y1 + length * math.sin(math.radians(angle + angle1))
    canvas.create_line(x3, y3, x4, y4)

    if hangman.numberOfMisses < 7:
        return
      
    # Draw the right leg
    angle1 = -math.degrees(math.asin(40.0 / length))
    x4 = x1 + length * math.cos(math.radians(angle + angle1))
    y4 = y1 + length * math.sin(math.radians(angle + angle1))
    canvas.create_line(x3, y3, x4, y4)
    
import random

class Hangman:
    def __init__(self):
        self.setWord()
        
    def setWord(self):
        index = random.randint(0, len(words) - 1)
        self.hiddenWord = words[index]

        self.guessedWord = len(self.hiddenWord) * ['*']

        self.numberOfCorrectLettersGuessed = 0
        self.numberOfMisses = 0
        self.missedLetters = []
        self.isFinishedWithWrongGuess = False
        self.isFinishedWithCorrectGuess = False
        
    def guess(self, letter):
        if letter in self.guessedWord:
            print("\t" + letter + " is already in the word")
        elif self.hiddenWord.find(letter) < 0:
            print("\t" + letter + " is not in the word")
            if not (letter in self.missedLetters):
                self.missedLetters.append(letter)
                self.numberOfMisses += 1
                if self.numberOfMisses == 7:
                    hangman.isFinishedWithWrongGuess = True
        else:
            k = self.hiddenWord.find(letter)
            while k >= 0:
                self.guessedWord[k] = letter
                self.numberOfCorrectLettersGuessed += 1
                k = self.hiddenWord.find(letter, k + 1)
            if self.numberOfCorrectLettersGuessed == len(self.hiddenWord):
                self.isFinishedWithCorrectGuess = True
            
        # Update display
        drawHangman()
        
def toString(list):
    s = ""
    for e in list:
        s += e
    return s

from tkinter import * # Import tkinter

# Initialize words, get the words from a file
infile = open("hangman.txt", "r")
words = infile.read().split()
    
window = Tk() # Create a window
window.title("Hangman") # Set a title

def processKeyEvent(event):  
    if event.char >= 'a' and event.char <= 'z':
        print("char? ", event.char)
        hangman.guess(event.char)
    elif event.keycode == 13:
        if hangman.isFinishedWithCorrectGuess or hangman.isFinishedWithWrongGuess:
            hangman.setWord()
            drawHangman()
    
width = 400
height = 280    
canvas = Canvas(window, bg = "white", width = width, height = height)
canvas.pack()

hangman = Hangman()
drawHangman()

# Bind with <Key> event
canvas.bind("<Key>", processKeyEvent)
canvas.focus_set()

window.mainloop() # Create an event loop
