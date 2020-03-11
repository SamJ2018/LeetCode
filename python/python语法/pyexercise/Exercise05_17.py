count = 1

for i in range(ord('!'), ord('~') + 1):
    if count % 10 != 0:
        print(chr(i), end = " ")
    else:
        print(chr(i))
    count += 1
