def main():
    p1 = 2;
    for p in range(2, 1000 + 1):
        if isPrime(p):
            if p - p1 == 2:
                print("(" + str(p1) + ", " + str(p) + ")")

            p1 = p

def isPrime(num):
    if num == 1 or num == 2:
        return True

    for i in range(2, num // 2 + 1):
        if num % i == 0:
            return False

    return True

main()
