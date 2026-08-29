class Plant:
    def __init__(self, name, height, age):
        self.name = name
        self.height = height
        self.age = age

    def show(self):
        print(f"{self.name}: {round(self.height, 1)}cm, {self.age} days old")

    def grow(self):
        self.height += 0.8
    def age(self):
        self.age += 1


if __name__ == "__main__":
    print("=== Garden Plant Growth ===")
    rose = Plant("Rose", 25, 30)
    start_height = rose.height
    for day in range(1, 8):
        rose.grow()
        rose.age()
        print(f"=== Day {day} ===")
        rose.show()
    growth = rose.height - start_height
    print(f"Growth this week: {round(growth, 1)}")