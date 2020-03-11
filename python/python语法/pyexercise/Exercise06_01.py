def main():
    for i in range(1, 100 + 1):
        if i % 10 == 0:
            print(format(getPentagonalNumber(i), "6d"))
        else:
            print(format(getPentagonalNumber(i), "6d"), end = "")

def getPentagonalNumber(n):
    return n * (3 * n - 1) // 2

main()
