#!/usr/bin/env python3


class Plant:
    """
    Represents a plant and tracks its growth simulation.
    """

    def __init__(self, name: str, height: int, ages: int):
        """
        Attributes:
        name (str): The name of the plant.
        height (int): The current height of the plant in centimeters.
        ages (int): The current age of the plant in days.
        start_height (int): The height recorded at
                            the start of a simulation period.
        """
        self.name = name
        self.height = height
        self.ages = ages
        self.start_height = height

    def print_plant(self) -> None:
        """
        Prints the current details of the plant to standard output
        """
        print(f"{self.name}: {self.height}cm, {self.ages} days old")

    def grow(self) -> None:
        """
        Increases the plant's height by 1 cm.
        """
        self.height += 1

    def age(self) -> None:
        """
        Increments the plant's age by 1 day.
        """
        self.ages += 1

    def get_info(self, days: int) -> None:
        """
        Updates the plant status and prints info based on the simulation day.

        - Day 1: Prints initial status without growth.
        - Day 7: Grows, ages, prints status, and shows weekly growth summary.
        - Other days: Grows, ages, and prints status.
        """
        if days == 1:
            print("=== Day 1 ===")
            self.print_plant()
        elif days == 7:
            print("=== Day 7 ===")
            self.grow()
            self.age()
            self.print_plant()
            print(f"Growth this week: +{self.height - self.start_height}cm")
        else:
            print(f"=== Day {days} ===")
            self.grow()
            self.age()
            self.print_plant()

    def simulate_growth(self) -> None:
        """
        Simulates a week (7 days) of plant growth.

        Resets the start_height to the current height before starting
        the weekly simulation loop.
        """
        self.start_height = self.height
        for i in range(1, 8):
            self.get_info(i)


if __name__ == "__main__":
    plant = Plant("Rose", 25, 30)
    plant.simulate_growth()
