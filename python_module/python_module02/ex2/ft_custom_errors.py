#!/usr/bin/env python3


class GardenError(Exception):
    """
    Base class for exceptions in the garden module.
    """

    def __init__(self, arg=""):
        self.arg = arg


class PlantError(GardenError):
    """
    Exception raised for issues related to plant health
    """

    def __str__(self):
        return f"Caught PlantError: The {self.arg} plant is wilting!"


class WaterError(GardenError):
    """
    Exception raised when there is a water supply issue.
    """

    def __str__(self):
        return "Caught WaterError: Not enough water in the tank!"


def check_planterror(arg) -> None:
    """
    Simulates a plant health check that always fails.
    """
    raise PlantError(arg)


def check_watererror() -> None:
    """
    Simulates a water level check that always fails.
    """
    raise WaterError()


def check_allerror(arg: str) -> None:
    """
    Sequentially triggers and handles both plant and water errors.
    This function demonstrates how to catch multiple specific exceptions
    within a loop
    """
    for idx in range(2):
        try:
            if idx == 0:
                check_planterror(arg)
            elif idx == 1:
                check_watererror()
        except (PlantError, WaterError) as e:
            print(e)


def handle_errors(mode: int, arg: str) -> None:
    """
    Routes to different error simulation scenarios based on the mode.
    """
    if mode == 0:
        print("Testing PlantError...")
        check_planterror(arg)
    elif mode == 1:
        print("Testing WaterError")
        check_watererror()
    elif mode == 2:
        print("Testing catching all garden errors...")
        check_allerror(arg)


if __name__ == "__main__":
    for mode in range(3):
        try:
            arg = "tomato"
            handle_errors(mode, arg)
        except (PlantError, WaterError) as e:
            print(e)
        print()
    print("All custom error types work correctly")
