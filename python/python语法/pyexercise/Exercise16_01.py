def main():
    s = input("Enter a string: ").strip()
    print("Maximum consecutive substring is " + maxConsecutiveSortedSubstring1(s))

'''
   * The worst-case complexity is O(n^2), where n is s.length(). Can you improve
   * the algorithm?
'''
def maxConsecutiveSortedSubstring(s):
    maxConsecutiveLength = len(s) * [0]
    current = 0
    for i in range(1, len(s)):
      if s[i] <= s[i - 1]: # next character is smaller
        current = i
      else:
        # s[current], s[current+1], ..., s[i-1] is a maximal increasing sequence
        for j in range(i - 1, current - 1, -1):
          maxConsecutiveLength[j] += 1

    # maxConsecutiveLength[i] denotes the length of a max sequence starting at index i
    currentMaxLength = maxConsecutiveLength[0]
    index = 0
    for i in range(len(s)):
      if maxConsecutiveLength[i] > currentMaxLength:
        currentMaxLength = maxConsecutiveLength[i]
        index = i

    return s[index : index + currentMaxLength + 1]

# O(n) version, 10/08/2010
def maxConsecutiveSortedSubstring1(s):
    currentMaxLength = 1
    lastIndexOfMaxConsecutiveSortedSubstring = 0

    possibleMaxLength = 1
    for i in range(1, len(s)):
      if s[i] > s[i - 1]:
        if lastIndexOfMaxConsecutiveSortedSubstring == i - 1:
          # Add s[i] into the max consecutive substring
          currentMaxLength += 1
          lastIndexOfMaxConsecutiveSortedSubstring += 1
        else:
          possibleMaxLength += 1
          if possibleMaxLength > currentMaxLength:
            currentMaxLength = possibleMaxLength
            lastIndexOfMaxConsecutiveSortedSubstring = i
            possibleMaxLength = 1

    return s[lastIndexOfMaxConsecutiveSortedSubstring
        - currentMaxLength + 1: lastIndexOfMaxConsecutiveSortedSubstring + 1]

main()
