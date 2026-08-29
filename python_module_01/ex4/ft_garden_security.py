class Plant:
    def __init__(self, name, height, age):
        self.name = name
        self._height = height
        self._age = age

    def show(self):
        print(f"{self.name}: {round(self._height, 1)}cm, {self._age} days old")

    def grow(self):
            self._height += 0.8

    def age(self):
            self._age += 1

    def get_height(self):
        return self._height

    def get_age(self):
        return self._age

    def set_height(self, height):
        if height < 0:
            print(f"{self.name}: Error, height can't be negative")
            print("Height update rejected")
            return
        self._height = height
        print(f"Height updated: {self._height}")

    def set_age(self, age):
        if age < 0:
            print(f"{self.name}: Error, age can't be negative")
            print("Age update rejected")
            return
        self._age = age
        print(f"Age updated: {self._age}")

if __name__ == "__main__":
    print("=== Garden Security System ===")
    rose = Plant("Rose", 15.0, 10)
    rose.show()
    print()

    rose.set_height(25)
    rose.set_age(30)
    print()

    rose.set_height(-1)
    rose.set_age(-10)
    print()

    print("Current state: Rose: ", end="")
    rose.show()