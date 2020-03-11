import RandomCharacter

N = 10000
count = 0
for i in range(N):
    ch = RandomCharacter.getRandomUpperCaseLetter()
    if ch == 'A':
        count += 1

print("The occurrence of A is", count)
