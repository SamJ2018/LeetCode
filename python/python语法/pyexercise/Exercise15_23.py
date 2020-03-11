def main():
    s = input("Enter a string: ").strip()
    displayPermuation(s)

def displayPermuation(s):
    displayPermuationHelper("", s)

def displayPermuationHelper(s1, s2):
    if len(s2) > 0:
        for i in range(len(s2)):
            displayPermuationHelper(s1 + s2[i], s2[0 : i] + s2[i + 1 : ])
    else:
        print(s1)

main()
