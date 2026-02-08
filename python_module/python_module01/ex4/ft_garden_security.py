#!/usr/bin/env python3


class SecurePlant:
    """
    Represents a plant with encapsulated attributes to enforce data validity.
    """

    def __init__(self, name: str, height: int, age: int) -> None:
        """
        Initialize a new SecurePlant instance.

        Args:
            name (str): The name of the plant.
            height (int): The initial height (cm). Must be non-negative.
            age (int): The initial age (days). Must be non-negative.
        """
        self.name = name
        self.__height = height
        self.__age = age
        print(f"Plant created: {self.name}")

    def get_height(self) -> int:
        """
        Return the current height of the plant.
        """
        return self.__height

    def get_age(self) -> int:
        """
        Return the current age of the plant.
        """
        return self.__age

    def set_height(self, height: int) -> None:
        """
        Update the plant's height after validating the input.

        The update is rejected if the provided height is negative.
        """
        if height >= 0:
            self.__height = height
            print(f"Height updated: {self.__height}cm [OK]")
        else:
            print(f"Invalid operation attempted: height {height}cm [REJECTED]")
            print("Security: Negative height rejected")

    def set_age(self, age: int) -> None:
        """
        Update the plant's age after validating the input.

        The update is rejected if the provided age is negative.
        """
        if age >= 0:
            self.__age = age
            print(f"Age updated: {self.__age} days [OK]")
        else:
            print(f"Invalid operation attempted: age {age} days [REJECTED]")
            print("Security: Negative age rejected")

    def display_info(self) -> None:
        """
        Print the current status (name, height, and age) of the plant.
        """
        print(
            f"Current plant: {self.name} ({self.get_height()}cm,"
            f" {self.get_age()} days)"
        )


if __name__ == "__main__":
    print("=== Garden Security System ===")
    plant = SecurePlant("Rose", 25, 30)
    plant.set_height(25)
    plant.set_age(30)
    print()
    plant.set_height(-5)
    print()
    plant.display_info()
