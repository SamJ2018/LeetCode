from tkinter import * # Import tkinter
import tkinter.messagebox # Import tkinter.messagebox
import urllib.request

def showResult():
    analyzeFile(url.get())

def analyzeFile(url):
    try:
        infile = urllib.request.urlopen(url)
        s = str(infile.read().decode()) # Read the content as string from the URL
    
        counts = countLetters(s.lower())

        # Display results in a histogram
        histogram(counts)
    
        infile.close() # Close file
    except ValueError:
        tkinter.messagebox.showwarning("Analyze URL", 
                                    "URL " + filename + " does not exist")  
def histogram(counts): 
    numberOfBars = len(counts)
    width = int(canvas["width"])
    height = int(canvas["height"])
    heightBar = 0.75 * height
    widthBar = width - 20
    maxCounts = max(counts)
    
    for i in range(numberOfBars):
        canvas.create_rectangle(i * widthBar / numberOfBars + 10, height - 20 - counts[i] * heightBar / maxCounts, (i + 1) * widthBar / numberOfBars + 10, height - 20)
        canvas.create_text(i * widthBar / numberOfBars + 10 + 0.5 * widthBar / numberOfBars, height - 10, text = chr(i + ord('a')))

# Count each letter in the string 
def countLetters(s): 
    counts = 26 * [0] # Create and initialize counts
    for ch in s:
        if ch.isalpha():
            counts[ord(ch) - ord('a')] += 1
    return counts

            
def openFile(): 
    filenameforReading = askopenfilename()
    filename.set(filenameforReading)
        
window = Tk() # Create a window
window.title("Occurrence of Letters in a Histogram from URL") # Set title

frame1 = Frame(window) # Hold four labels for displaying cards
frame1.pack()
canvas = Canvas(frame1, width = 500, height = 200)
canvas.pack()

frame2 = Frame(window) # Hold four labels for displaying cards
frame2.pack()

Label(frame2, text = "Enter a URL: ").pack(side = LEFT)
url = StringVar()
Entry(frame2, width = 50, textvariable = url).pack(side = LEFT)
Button(frame2, text = "Show Result", command = showResult).pack(side = LEFT)

window.mainloop() # Create an event loop
