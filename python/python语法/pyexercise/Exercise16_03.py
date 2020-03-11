def main():
    s1 = input("Enter a string s1: ").strip()
    s2 = input("Enter a string s2: ").strip()
    
    index = match(s1, s2);
    if index >= 0:
        print("matched at index " + str(index))
    else:
        print("unmatched")

'''
The worst-case complexity is O(n), where n is s.length()
'''
def match(s, pattern):
    k = 0
    for i in range(len(s)):
      if k == len(pattern):
        return i - len(pattern)
      else:
        if s[i] == pattern[k]:
          k += 1
        else:
          k = 0

    if k == len(pattern):
        return len(s) - len(pattern)
    else:
        return -1

  
'''
* This is a brute-force approach, O(|s|*|pattern|))
'''
def match1(s, pattern):
    for i in range(len(s)):
      # Check if pattern matches si, si+1, ...
      k = 0       
      while k < len(pattern): 
        if s[i + k] != pattern[k]:
          break    
        k += 1

      if k == len(pattern):
        return i
    
    return -1

main()
