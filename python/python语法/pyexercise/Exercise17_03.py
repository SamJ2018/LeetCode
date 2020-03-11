def heapSort(list):
    # Create a Heap 
    heap = []

    # Add elements to the heap
    for v in list:
        add(v, heap)
    
    # Remove elements from the heap
    for i in range(len(list)):
        list[i] = remove(heap)
        
# Add a new item into the heap 
def add(newItem, heap):
    heap.append(newItem)  # Append to the heap
    currentIndex = len(heap) - 1  # The index of the last node

    while currentIndex > 0:
        parentIndex = (currentIndex - 1) // 2
        # Swap if the current item is greater than its parent
        if heap[currentIndex] < heap[parentIndex]: 
            heap[currentIndex], heap[parentIndex] = \
                heap[parentIndex], heap[currentIndex]
        else:
            break  # The tree is a heap now

        currentIndex = parentIndex

# Remove the root from the heap 
def remove(heap):
    removedItem = heap[0]
    heap[0] = heap[len(heap) - 1]
    heap.pop(len(heap) - 1) # Remove the last item

    currentIndex = 0
    while currentIndex < len(heap):
        leftChildIndex = 2 * currentIndex + 1
        rightChildIndex = 2 * currentIndex + 2
      
        # Find the maximum between two children
        if leftChildIndex >= len(heap): 
            break  # The tree is a heap
        maxIndex = leftChildIndex
        if rightChildIndex < len(heap):
            if heap[maxIndex] > heap[rightChildIndex]:
                maxIndex = rightChildIndex
      
        # Swap if the current node is less than the maximum 
        if heap[currentIndex] > heap[maxIndex]:
            heap[maxIndex], heap[currentIndex] = \
                heap[currentIndex], heap[maxIndex]
            currentIndex = maxIndex
        else:
            break  # The tree is a heap

    return removedItem
  
def main():
    # Read numbers as a string from the console
    s = input("Enter numbers: ") 
    items = s.split() # Extracts items from the string
    list = [ eval(x) for x in items ] # Convert items to numbers
        
    heapSort(list)
    for v in list:
        print(str(v) + " ", end = " ")

main()
