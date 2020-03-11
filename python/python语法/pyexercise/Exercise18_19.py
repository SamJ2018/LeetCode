class FibonacciIterator:
    def __init__(self):
        self.fn1 = 0 # Current two consecutive fibonacci numbers
        self.fn2 = 1 
    
    def __next__(self): 
        current = self.fn1
        self.fn1, self.fn2 = self.fn2, self.fn1 + self.fn2
        
        return current

    def __iter__(self):
        return self
    
def main():
    iterator = FibonacciIterator()
    for i in iterator:
        print(i)
        if i > 1000: break

main()

iterator = iter(FibonacciIterator())
print(iterator.__next__())
print(next(iterator))
