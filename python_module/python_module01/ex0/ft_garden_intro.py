#!/usr/bin/env python3


def ft_garden_intro(name: str, height: int, age: int) -> None:
    """
    This function displays garden information based on
    input data
    """
    print("=== Welcome to My Garden ===")
    print(f"Plant: {name}")
    print(f"Height: {height}cm")
    print(f"Age: {age} days")
    print()
    print("=== End of Program ===")


if __name__ == "__main__":
    ft_garden_intro("Rose", 25, 30)
