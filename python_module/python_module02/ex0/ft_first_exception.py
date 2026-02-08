#!/usr/bin/env python3


def check_temperature(temp_str: str) -> None:
    """
    This function uses try-except syntax for handling temperature.
    If temperature is below 40 degrees, it's perfect for plants
    Otherwise, too cold / hot for plants
    If string is input, catch valueerror and display the result.
    """
    print(f"Testing temperature: {temp_str}")
    try:
        temp_num = int(temp_str)
    except ValueError:
        print(f"Error: '{temp_str}' is not a valid number")
        return
    if 0 <= temp_num and temp_num <= 40:
        print(f"Temperature {temp_num}°C is perfect for plants!")
        return temp_num
    elif 40 < temp_num:
        print(f"Error: {temp_num}°C is too hot for plants (max 40°C)")
    else:
        print(f"Error: {temp_num}°C is too cold for plants (min 0°C)")


if __name__ == "__main__":
    print("=== Garden Temperature Checker ===")
    check_temperature("25")
    print()
    check_temperature("abc")
    print()
    check_temperature("100")
    print()
    check_temperature("-50")
    print()
    print("All tests completed - program didn't crash!")
