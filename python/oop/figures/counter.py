class Counter():
    def __init__(self, start = 0):
        self.value = start

    def inc(self, value = 1):
        self.value += value
    
    def dec(self, value = 1):
        self.value -= value
        if (self.value < 0):
            self.value = 0

class NonDecCounter(Counter):
    def __init__(self, start=0):
        super().__init__(start)
    
    def dec(self, value = 1):
        pass

class  LimitedCounter(Counter):
    def __init__(self, start=0, limit = 10):
        self.limit = limit
        super().__init__(start)

    def inc(self, value = 1):
        super().inc(value)
        if (self.value > self.limit):
            self.value = self.limit

if __name__ == "__main__":
    c = Counter(start=1)
    c.inc()
    c.dec(5)
    print(c.value)

    ndc = NonDecCounter(start=5)
    ndc.inc()
    ndc.dec()
    print(ndc.value)

    lc = LimitedCounter(start=5, limit=10)
    lc.inc(100)
    print(lc.value)
    
    lc.dec(5)
    print(lc.value)