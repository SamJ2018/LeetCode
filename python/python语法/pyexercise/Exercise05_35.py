for number in range(6, 10000 + 1):
    sum = 0
    divisor = number - 1
    while divisor >= 1:
        if number % divisor == 0:
            sum += divisor

        divisor -= 1
        
    if number == sum:
        print(number, end = " ")
