def xfunction(n):
    if n <= 0:
        print(n % 10, end = " ")
        xfunction(n // 10)
  
xfunction(1234)