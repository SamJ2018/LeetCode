import random
import time

def main():
    print("{0:15s}{1:15s}{2:15s}{3:15s}{4:15s}{5:15s}{6:15s}".format("Array Size", "Selection Sort", "Insertion Sort", 
                                                                     "Bubble Sort", "Merge Sort", "Quick Sort", "Heap Sort", "Radix Sort"))
    executionTime = []
    for k in range(6):
        executionTime.append(7 * [0])
 
    BASE = 5000
    for k in range(6):
        list = (k * BASE + BASE) * [0]
        list1 = (k * BASE + BASE) * [0]
        for i in range(len(list)):
            list[i] = random.randint(0, 100000 - 1)
            list1[i] = list[i]

        startTime = time.time()
        selectionSort(list)
        endTime = time.time()
        executionTime[k][0] = endTime - startTime

        startTime = time.time()
        copyList(list1, list);
        insertionSort(list)
        endTime = time.time()
        executionTime[k][1] = endTime - startTime

        startTime = time.time()
        copyList(list1, list);
        bubbleSort(list)
        endTime = time.time()
        executionTime[k][2] = endTime - startTime

        startTime = time.time()
        copyList(list1, list);
        mergeSort(list)
        endTime = time.time()
        executionTime[k][3] = endTime - startTime

        startTime = time.time()
        copyList(list1, list);
        heapSort(list) # quickSort will run out of recursive depth 
        endTime = time.time()
        executionTime[k][4] = endTime - startTime

        startTime = time.time()
        copyList(list1, list);
        heapSort(list)
        endTime = time.time()
        executionTime[k][5] = int(endTime - startTime)
      
        startTime = time.time()
        copyList(list1, list);
        radixSort(list, 5)
        endTime = time.time()
        executionTime[k][6] = int(endTime - startTime)

    for i in range(6):
        print("{0:-15d}".format(BASE + i * BASE), end = "")
        for j in range(7):
            print("{0:-15.3f}".format(executionTime[i][j]), end = "")
        print()

# The function for sorting the numbers 
def selectionSort(list):
    for i in range(len(list) - 1):
        # Find the minimum in the list[i..len(list)-1]
        currentMin = list[i]
        currentMinIndex = i

        for j in range(i + 1, len(list)):
            if currentMin > list[j]:
                currentMin = list[j]
                currentMinIndex = j

        # Swap list[i] with list[currentMinIndex] if necessary;
        if currentMinIndex != i:
            list[currentMinIndex] = list[i]
            list[i] = currentMin

# The function for sorting the numbers 
def insertionSort(list):
    for i in range(1, len(list)):
        # insert list[i] into a sorted sublist list[0..i-1] so that
        #   list[0..i] is sorted. 
        currentElement = list[i]
        k = i - 1
        while k >= 0 and list[k] > currentElement:
            list[k + 1] = list[k]
            k -= 1

        # Insert the current element into list[k + 1]
        list[k + 1] = currentElement


def bubbleSort(list):
    needNextPass = True
    
    k = 1
    while k < len(list) and needNextPass:
        # List may be sorted and next pass not needed
        needNextPass = False
        for i in range(len(list) - k): 
            if (list[i] > list[i + 1]):
                # swap list[i] with list[i + 1]
                list[i], list[i + 1] = list[i + 1], list[i]
          
                needNextPass = True # Next pass still needed

def mergeSort(list):
    if len(list) > 1:
        # Merge sort the first half
        firstHalf = list[ : len(list) // 2]
        mergeSort(firstHalf)

        # Merge sort the second half
        secondHalf = list[int(len(list) / 2) : ]
        mergeSort(secondHalf)

        # Merge firstHalf with secondHalf into list
        merge(firstHalf, secondHalf, list)

# Merge two sorted lists 
def merge(list1, list2, temp):
    current1 = 0  # Current index in list1
    current2 = 0  # Current index in list2
    current3 = 0  # Current index in temp

    while current1 < len(list1) and current2 < len(list2):
        if list1[current1] < list2[current2]:
            temp[current3] = list1[current1]
            current1 += 1
            current3 += 1
        else:
            temp[current3] = list2[current2]
            current2 += 1
            current3 += 1

    while current1 < len(list1):
        temp[current3] = list1[current1]
        current1 += 1
        current3 += 1

    while current2 < len(list2):
        temp[current3] = list2[current2]
        current2 += 1
        current3 += 1

def quickSort(list):
    quickSortHelper(list, 0, len(list) - 1)

def quickSortHelper(list, first, last):
    if last > first:
        pivotIndex = partition(list, first, last)
        quickSortHelper(list, first, pivotIndex - 1)
        quickSortHelper(list, pivotIndex + 1, last)

# Partition list[first..last] 
def partition(list, first, last):
    pivot = list[first]  # Choose the first element as the pivot
    low = first + 1  # Index for forward search
    high = last  # Index for backward search

    while high > low:
        # Search forward from left
        while low <= high and list[low] <= pivot:
            low += 1

        # Search backward from right
        while low <= high and list[high] > pivot:
            high -= 1

        # Swap two elements in the list
        if high > low:
            list[high], list[low] = list[low], list[high]

    while high > first and list[high] >= pivot:
        high -= 1

    # Swap pivot with list[high]
    if pivot > list[high]:
        list[first] = list[high]
        list[high] = pivot
        return high
    else:
        return first

def heapSort(list):
    # Create a Heap 
    heap = []

    # Add elements to the heap
    for v in list:
        add(v, heap)

    # Remove elements from the heap
    for i in range(len(list) - 1, -1, -1):
        list[i] = remove(heap)

# Add a new item into the heap 
def add(newItem, heap):
    heap.append(newItem)  # Append to the heap
    currentIndex = len(heap) - 1  # The index of the last node

    while currentIndex > 0:
        parentIndex = (currentIndex - 1) // 2
        # Swap if the current item is greater than its parent
        if heap[currentIndex] > heap[parentIndex]: 
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
            if heap[maxIndex] < heap[rightChildIndex]:
                maxIndex = rightChildIndex
      
        # Swap if the current node is less than the maximum 
        if heap[currentIndex] < heap[maxIndex]:
            heap[maxIndex], heap[currentIndex] = \
                heap[currentIndex], heap[maxIndex]
            currentIndex = maxIndex
        else:
            break  # The tree is a heap

    return removedItem

''' Sort the int array list. numberOfDigits is the number of digits
    in the largest number in the array 
'''
def radixSort(list, numberOfDigits):
    buckets = []
    for i in range(10):
        buckets.append([0]); 

    for position in range(numberOfDigits + 1):
        # Clear buckets
        for i in range(len(buckets)):
            buckets[i] = []    
      
        # Distribute the elements from list to buckets
        for i in range(len(list)):
            key = getKey(list[i], position)
            buckets[key].append(list[i])

        # Now move the elements from the buckets back to list
        k = 0 # k is an index for list
        for i in range(len(buckets)):
            for j in range(len(buckets[i])):
                list[k] = buckets[i][j]
                k += 1

'''
   Return the digit at the specified position. 
   The last digit's position is 0. 
'''
def getKey(number, position):
    result = 1;
    for i in range(position):
        result *= 10

    return (number // result) % 10

def copyList(list1, list):
    list = [ x for x in list1 ]

main()
