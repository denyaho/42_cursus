#!/usr/bin/env python3


class Plant:
    """
    Represents a generic plant in the garden.
    """

    def __init__(self, name: str, height: int, age: int):
        """
        Initialize a new Plant instance.

        Args:
            name (str): The name of the plant.
            height (int): The height of the plant (cm).
            age (int): The age of the plant (days).
        """
        self.name = name
        self.height = height
        self.age = age


class Flower(Plant):
    """
    Represents a flowering plant (inherits from Plant).
    """

    def __init__(self, name: str, height: int, age: int, color: str):
        """
        Initialize a new Flower instance
        color (str): The color of the flower.
        """
        super().__init__(name, height, age)
        self.color = color

    def bloom(self) -> None:
        """
        Print the flower's details and a blooming message.
        """
        print(
            f"{self.name} (Flower): {self.height}cm,"
            f" {self.age} days. {self.color} color"
        )
        print(f"{self.name} is blooming beautifully!")


class Tree(Plant):
    """
    Represents a tree (inherits from Plant).
    """

    def __init__(self, name: str, height: int, age: int, trunk_diameter: int):
        """
        Initialize a new Tree instance.

        trunk_diameter (int): The trunk diameter (cm).
        """
        super().__init__(name, height, age)
        self.trunk_diameter = trunk_diameter

    def produce_shade(self):
        """
        Calculate and print the amount of shade produced by the tree.
        """
        print(
            f"{self.name} (Tree): {self.height}cm,"
            f" {self.age} days, {self.trunk_diameter}cm diameter"
        )
        shade_area = self.height * self.trunk_diameter * (31.2 / 10000)
        print(f"{self.name} provides {int(shade_area)} square meters of shade")


class Vegetable(Plant):
    """
    Represents a vegetable or edible plant (inherits from Plant).
    """

    def __init__(
        self,
        name: str,
        height: int,
        age: int,
        harvest_season: str,
        nutritional_value: str,
    ):
        """
        Initialize a new Vegetable instance.
        harvest_season (str): The best season for harvest (e.g., 'summer').
        nutritional_value (str): The primary nutrient (e.g., 'vitamin C').
        """
        super().__init__(name, height, age)
        self.harvest_season = harvest_season
        self.nutritional_value = nutritional_value

    def get_info(self):
        """
        Print the vegetable's details including harvest season and nutrition.
        """
        print(
            f"{self.name} (Vegetable): {self.height}cm,"
            f" {self.age} days, {self.harvest_season} harvest"
        )
        print(f"{self.name} is rich in {self.nutritional_value}")


if __name__ == "__main__":
    print("=== Garden Plant Types ===")
    print()
    rose = Flower("Rose", 25, 30, "red")
    rose.bloom()
    print()

    tulip = Flower("Tulip", 30, 25, "yellow")
    tulip.bloom()
    print()

    oak = Tree("Oak", 500, 1825, 50)
    oak.produce_shade()
    print()

    pine = Tree("Pine", 300, 1460, 40)
    pine.produce_shade()
    print()

    tomato = Vegetable("Tomato", 80, 90, "summer", "vitamin C")
    tomato.get_info()
    print()

    carrot = Vegetable("Carrot", 60, 75, "fall", "beta-carotene")
    carrot.get_info()
