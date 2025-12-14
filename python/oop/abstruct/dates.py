import abc

class Date(abc.ABC):
    def __init__(self, year, month, day):
        self.year = year
        self.month = month
        self.day = day

    def iso_format(self):
        return f"{self.year}-{self.month:02}-{self.day:02}"
    
    @abc.abstractmethod
    def format(self):
        pass

class USADate(Date):
    def format(self):
        return f"{self.month:02}-{self.day:02}-{self.year}"

class ItalianDate(Date):
    def format(self):
        return f"{self.day:02}/{self.month:02}/{self.year}"