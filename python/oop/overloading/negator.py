class Negator():
    @staticmethod
    def neg(inpt):
        if isinstance(inpt, bool):
            return not inpt
        if isinstance(inpt, (int, float)):
            return -inpt
        raise TypeError("Аргумент переданного типа не поддерживается")