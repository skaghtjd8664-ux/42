class Plant:
    class Stats:
        def __init__(self):
            self._grow_count = 0
            self._age_count = 0
            self._show_count = 0

        def record_grow(self):
            self._grow_count += 1

        def record_age(self):
            self._age_count += 1

        def record_show(self):
            self._show_count += 1

        def show(self):
            print(f"Stats: {self._grow_count} grow, {self._age_count} age, {self._show_count} show")

    @staticmethod
    def is_year(day):
        return day > 365

    def __init__(self, name, height, age):
        self.name = name
        self._height = height
        self._age = age
        self.stats = Plant.Stats()

    @classmethod
    def create_anonymous(cls):
        return cls("Unknown plant", 0.0, 0)

    def show(self):
        print(f"{self.name}: {round(self._height, 1)}cm, {self._age} days old")
        self.stats.record_show()

    def grow(self):
            self._height += 2.1
            self.stats.record_grow()

    def age(self):
            self._age += 1
            self.stats.record_age()

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

class Flower(Plant):
    def __init__(self, name, height, age, color):
        super().__init__(name, height, age)
        self.color = color
        self.bloomed = False

    def bloom(self):
        self.bloomed = True
    def show(self):
        super().show()
        print(f"Color: {self.color}")
        if self.bloomed:
            print(f"{self.name} is blooming beautifully!")
        else:
            print(f"{self.name} has not bloomed yet")

class Tree(Plant):
    class Treestats(Plant.Stats):
        def __init__(self):
            super().__init__()
            self._shade_count = 0

        def record_shade(self):
            self._shade_count += 1

        def show(self):
            super().show()
            print(f"{self._shade_count} shade")

    def __init__(self, name, height, age, trunk_diameter):
        super().__init__(name, height, age)
        self.trunk_diameter = trunk_diameter
        self.stats = self.Treestats()

    def produce_shade(self):
        print(f"Tree {self.name} now produces a shade of {self._height}cm long and {self.trunk_diameter}cm wide.")
        self.stats.record_shade()

    def show(self):
        super().show()
        print(f" Trunk diameter: {self.trunk_diameter}cm")

class Vegetable(Plant):
    def __init__(self, name, height, age, harvest_season):
        super().__init__(name, height, age)
        self.harvest_season = harvest_season
        self.nutritional_value = 0

    def grow(self):
        super().grow()
        self.nutritional_value += 0.5

    def age(self):
        super().age()
        self.nutritional_value += 0.5

    def show(self):
        super().show()
        print(f"Harvest season: {self.harvest_season}")
        print(f"Nutritional value: {round(self.nutritional_value)}")

class Seed(Flower):
    def __init__(self, name, height, age, color):
        super().__init__(name, height, age, color)
        self.seed = 0

    def bloom(self):
        super().bloom()
        self.seed = 42

    def show(self):
        super().show()
        print(f"Seeds: {self.seed}")

if __name__ == "__main__":
    print("=== Garden statistics ===")

    print("=== Check year-old")
    print(f"Is 30 days more than a year? -> {Plant.is_year(30)}")
    print(f"Is 400 days more than a year? -> {Plant.is_year(400)}")
    print("")

    print("=== Flower")
    rose = Flower("Rose", 15.0, 10, "red")
    rose.show()
    print(f"[statistics for {rose.name}]")
    rose.stats.show()
    rose.grow()
    print("[asking the rose to bloom]")
    rose.bloom()
    rose.show()
    print(f"[statistics for {rose.name}]")
    rose.stats.show()
    print("")

    print("=== Tree")
    oak = Tree("Oak", 200.0, 365, 5.0)
    oak.show()
    print(f"[statistics for {oak.name}]")
    oak.stats.show()
    print("[asking the oak to produce shade]")
    oak.produce_shade()
    print(f"[statistics for {oak.name}]")
    oak.stats.show()
    print("")

    print("=== Seed")
    sunflower = Seed("Sunflower", 80.0, 45, "yellow")
    sunflower.show()
    print("[make sunflower grow, age and bloom]")
    sunflower.grow()
    sunflower.age()
    sunflower.bloom()
    sunflower.show()
    print(f"[statistics for {rose.name}]")
    sunflower.stats.show()
    print("")

    print("=== Anonymous")
    unknown = Plant.create_anonymous()
    unknown.show() 
    print(f"[statistics for {unknown.name}]")
    unknown.stats.show()
