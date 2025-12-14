class Bachelor():
    def __init__(self, firstName, lastName, group, averageMark):
        self.firstName = firstName
        self.lastName = lastName
        self.group = group
        self.averageMark = averageMark

    def getScholarship(self):
        if self.averageMark == 5: return 10000
        if self.averageMark > 3: return 5000
        return 0

class Undergraduate(Bachelor):
    def __init__(self, firstName, lastName, group, averageMark, scientificWork):
        self.scientificWork = scientificWork
        super().__init__(firstName, lastName, group, averageMark)
    
    def getScholarship(self):
        if self.averageMark == 5: return 15000
        if self.averageMark > 3: return 7500
        return 0
    
if __name__ == "__main__":
    students = [
    Bachelor("Иван", "Иванов", "Б-101", 5),
    Bachelor("Петр", "Петров", "Б-101", 4), 
    Undergraduate("Анна", "Сидорова", "М-201", 5, "ИИ в медицине"), 
    Undergraduate("Ольга", "Кузнецова", "М-201", 3, "Big Data"),
    Bachelor("Сергей", "Смирнов", "Б-102", 3)
    ]
    for student in students: print(student.getScholarship())