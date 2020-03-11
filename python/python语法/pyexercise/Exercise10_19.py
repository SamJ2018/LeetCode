import random

def main():
    numberOfBalls = eval(input("Enter the number of balls to drop: "))
    numberOfSlots = eval(input("Enter the number of slots: "))
    
    slots = numberOfSlots * [0]
    
    for i in range(numberOfBalls):
        slots[onePath(numberOfSlots)] += 1

    printHistogram(slots)
  
# Return the slot position of the ball for a path and also print the path 
def onePath(numberOfSlots):
    position = 0;
    
    for i in range(numberOfSlots):
      if random.random() < 0.5:
          print("L", end = "")
      else:
          print("R", end = "")
          position += 1       
    
    print()
    
    return position
  
# Print the histogram for the slots 
def printHistogram(slots):
    maxSlotHeight = max(slots)
    
    for h in range(maxSlotHeight, 0, -1):
      for i in range(len(slots)):
        if slots[i] < h:
          print(" ", end = "") # Print nothing
        else:
          print("O", end = "") # Print a ball       

      print()
    
# Get the max element in slots 
def max(slots):
    result = slots[0]
    
    for i in range(1, len(slots)):
      if result < slots[i]:
        result = slots[i]
    
    return result

main()
