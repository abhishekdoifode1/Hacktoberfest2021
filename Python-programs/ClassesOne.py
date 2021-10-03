class Rectangle:
    def __init__(self, length, breath):
        self.length = int(length)
        self.breath = int(breath)

    def area(self):
        area = self.length * self.breath
        print(area)

    def perimetre(self):
        peri = 2 * (self.length + self.breath)
        print(peri)


rectOne = Rectangle(10, 10)
rectTwo = Rectangle(5, 5)

rectOne.area()
rectTwo.perimetre()
