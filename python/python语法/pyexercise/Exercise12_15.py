from tkinter import * # Import tkinter

# Convert a decimal to a hex as a string 
def toHex(decimalValue):
    hex = ""
 
    while decimalValue != 0:
        hexValue = decimalValue % 16 
        hex = toHexChar(hexValue) + hex
        decimalValue = decimalValue // 16
    
    if len(hex) < 2:
        hex = "0" + hex
        
    return hex
  
# Convert an integer to a single hex digit in a character 
def toHexChar(hexValue):
    if hexValue <= 9 and hexValue >= 0:
        return chr(hexValue + ord('0'))
    else:  # hexValue <= 15 && hexValue >= 10
        return chr(hexValue - 10 + ord('A'))
  
# Paint a Julia Set image in the canvas        
def paint():  
    x = -1.5
    while x < 1.5:
        y = -1.5
        while y < 1.5:
            times = count(x, y)
            if count(x, y) == 50:
                color = "black"
            else:
                c = 50 - times
                color = "#" + toHex(c * 14 % 256) + toHex(
                   c * 6 % 256) + toHex(c * 13 % 256)

            canvas.create_rectangle(x * 100 + 150, y * 100 + 150, 
                x * 100 + 150 + 5, y * 100 +150 + 5, fill = color) 
            y += 0.05
        x += 0.05

def count(x, y):
    c = complex(0.2, -0.6)
    z = complex(x, y)
    
    for i in range(50):
        z = z * z + c
        if abs(z) > 2: return i
    
    return 50

window = Tk() # Create a window
window.title("Julia Set") # Set a title

width = 300 # Width of the canvas
height = 300 # Height of the canvas
canvas = Canvas(window, width = width, height = height)
canvas.pack()

Button(window, text = "Display", command = paint).pack()
        
window.mainloop() # Create an event loop
