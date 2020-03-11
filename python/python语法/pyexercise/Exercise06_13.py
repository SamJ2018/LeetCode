def main():
    print(format("i", "<15s"), format("m(i)", "<20s"))
    for i in range(1, 20 + 1):
        print(format(i, "<15d"), format(m(i), "<20.4f"))

def m(n):
    sum = 0;

    for i in range(1, n + 1):
      sum += i * 1.0 / (i + 1)

    return sum

main()
