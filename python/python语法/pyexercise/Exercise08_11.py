def main():
    s = input("Enter a string: ").strip()
    
    print("The reversal is", reverse(s))

def reverse(s):
    result = ""
    
    for ch in s:
        result = ch + result
        
    return result

main()
