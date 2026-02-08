#!/usr/bin/env python3


class Plant:
    """
    Represents a plant created in the factory.
    """

    def __init__(self, name: str, height: int, age: int) -> None:
        """
        Attributes:
        name (str): The name of the plant.
        height (int): The height of the plant in centimeters.
        age (int): The age of the plant in days.
        """
        self.name = name
        self.height = height
        self.age = age

    def plant_factory(self) -> None:
        """
        Prints the details of the created plant to standard output.
        """
        print(f"Created: {self.name} ({self.height}cm, {self.age} days)")


if __name__ == "__main__":
    print("=== Plant Factory Output ===")
    plants = [
        ("Rose", 25, 30),
        ("Oak", 200, 365),
        ("Cactus", 5, 90),
        ("Sunflower", 80, 45),
        ("Fern", 15, 120),
    ]
    count = 0
    for name, height, age in plants:
        new_plant = Plant(name, height, age)
        new_plant.plant_factory()
        count += 1
    print()
    print(f"Total plants created: {count}")
