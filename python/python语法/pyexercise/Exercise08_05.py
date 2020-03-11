def main():
    s = input("Enter a string: ").strip()

    result = count(s)
   
    for i in range(10):
        if result[i] != 0:
            print(i, "occurs", result[i], "times")

def count(s):
    result = 10 * [0]
    for c in s:
        if c.isdigit():
            result[ord(c) - ord('0')] += 1
            
    return result
  
main()
