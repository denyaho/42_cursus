#!/usr/bin/env python3


class Plant:
    """
    Represents a plant in the garden.
    """

    def __init__(self, name: str, height: int, age: int):
        """
        Attributes:
        name (str): The name of the plant.
        height (int): The height of the plant in centimeters.
        age (int): The age of the plant in days.
        """
        self.name = name
        self.height = height
        self.age = age

    def print_plant(self):
        """
        Prints the plant's details to the standard output
        """
        print(f"{self.name}: {self.height}cm, {self.age} days old")


if __name__ == "__main__":
    rose = Plant("Rose", 25, 30)
    sunflower = Plant("Sunflower", 80, 45)
    cactus = Plant("Cactus", 15, 120)
    print("=== Garden Plant Registry ===")
    rose.print_plant()
    sunflower.print_plant()
    cactus.print_plant()
