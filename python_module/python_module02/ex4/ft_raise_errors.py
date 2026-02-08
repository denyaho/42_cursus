#!/usr/bin/env python3


def check_plant_health(plant_name: str, water_level: int,
                       sunlight_hours: int) -> None:
    """
    validates the environmental conditions for a specific plant.

    This function performs a health check based on provided
    growth parameters.It ensures that inputs are within acceptable
    biological limits before proceeding.
    """
    if plant_name is None:
        raise ValueError("Error: Plant name cannot be empty!")
    if water_level > 10:
        raise ValueError(f"Error: Water level {water_level}"
                         f" is too high (max 10)")
    if sunlight_hours < 2:
        raise ValueError(
            f"Error: Sunlight hours {sunlight_hours}"
            f" is too low (min 2)"
        )
    print(f"Plant '{plant_name}' is healthy!")


def test_plant_checks() -> None:
    """
    Executes a suite of test cases for the plant health validation logic.

    Iterates through multiple scenarios including valid inputs and
    various out-of-range parameters to verify that the system raises and
    catches the appropriate ValueError exceptions.
    """
    print("=== Garden Plant Health Checker ===")
    print()
    i = 0
    while i < 4:
        try:
            if i == 0:
                print("Testing good valuess...")
                check_plant_health("tomato", 10, 15)
            elif i == 1:
                print("Testing empty plant name...")
                check_plant_health(None, 10, 15)
            elif i == 2:
                print("Testing bad water level...")
                check_plant_health("tomato", 15, 10)
            else:
                print("Testing bad sunlight hours...")
                check_plant_health("tomato", 10, 0)
        except ValueError as e:
            print(e)
        i += 1
        print()
    print("All error raising tests completed!")


test_plant_checks()
