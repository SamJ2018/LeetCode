def sum(i1, i2):
    sum = 0
    for i in range(i1, i2):
        sum += i

    return sum

def main():
    print("Sum from 1 to 10 is", sum(1, 10)) 
    print("Sum from 20to 37is", sum(20, 37))
    print("Sum from 35 to 49 is", sum(35, 49))

main() # Call the main function
