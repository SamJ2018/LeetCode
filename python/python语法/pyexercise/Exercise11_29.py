def main():
    SIZE = 3
    m1 = input("Enter list1: ").split()
    m2 = input("Enter list2: ").split()
    
    if equals(m1, m2):
        print("Two lists are identical")
    else:
        print("Two lists are not identical")

def equals(m1, m2):
    list1 = []
    for row in m1:
        for e in row:
            list1.append(e)
    list1.sort()
      
    list2 = []
    for row in m1:
        for e in row:
            list2.append(e)
    list2.sort()
    
    return list1 == list2

main()
