class Product:
    def __init__(self, name="", price=0, weight=0):
        self.__name = name
        self.__price = price
        self.__weight = weight

    def set_name(self, name): self.__name = name
    def set_price(self, price): self.__price = price
    def set_weight(self, weight): self.__weight = weight

    def get_name(self): return self.__name
    def get_price(self): return self.__price
    def get_weight(self): return self.__weight


class Buy(Product):
    def __init__(self, name="", price=0, weight=0, quantity=0):
        super().__init__(name, price, weight)
        self.__quantity = quantity
        self.__total_price = 0
        self.__total_weight = 0
        self.calculate_totals()

    def set_quantity(self, quantity):
        self.__quantity = quantity
        self.calculate_totals()

    def get_quantity(self): return self.__quantity
    def get_total_price(self): return self.__total_price
    def get_total_weight(self): return self.__total_weight

    def calculate_totals(self):
        self.__total_price = self.get_price() * self.__quantity
        self.__total_weight = self.get_weight() * self.__quantity


class Check(Buy):
    def __init__(self, name="", price=0, weight=0, quantity=0):
        super().__init__(name, price, weight, quantity)

    def print_check(self):
        print(f"Товар: {self.get_name()}")
        print(f"Цена за шт: {self.get_price()} руб.")
        print(f"Вес 1 шт: {self.get_weight()} кг")
        print(f"Кол-во: {self.get_quantity()} шт.")
        print(f"ИТОГО ВЕС: {self.get_total_weight()} кг")
        print(f"ИТОГО СУММА: {self.get_total_price()} руб.")

my_check = Check()


my_check.set_name("Яблоки")
my_check.set_price(150)
my_check.set_weight(0.2)
my_check.set_quantity(5)

my_check.print_check()