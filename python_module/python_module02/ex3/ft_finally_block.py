#!/usr/bin/env python3


def water_plants(plant_list: list) -> None:
    """
    Simulates watering a list of plants with built-in error handling.

    This function attempts to water the first three items in a list.
    it Demonstrates the use of a 'finally' block to ensure system
    resources are always closed.
    """
    print("Opening watering system")
    try:
        for idx in range(3):
            print(f"Watering {plant_list[idx]}")

    except (TypeError, IndexError):
        print("Error: Cannot water None - invalid plant!")
    finally:
        print("Closing watering system (cleanup)")


def test_watering_system() -> None:
    """
    Tests the watering system with both valid and invalid plant lists.
    """
    print("=== Garden Watering System ===")
    print()
    print("Testing normal watering...")
    plant_list = ["tomato", "lettuce", "carrots"]
    water_plants(plant_list)
    print("Watering completed successfully")
    print()
    print("Testing with error...")
    water_plants(["tomato"])
    print()
    print("Cleanup always happens, even with errors")


if __name__ == "__main__":
    test_watering_system()
