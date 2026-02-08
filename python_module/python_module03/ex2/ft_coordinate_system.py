#! /usr/bin/env python3

import sys
import math


def main():
    """
    This program receives three arguments and
    calculates the distance from the origin (0,0,0) to given three arguments.
    Raises an error if the input contains non-numeric value(e.g., string).
    """
    args = sys.argv
    print("=== Game Coordinate System ===")
    print()
    if len(args) == 4:
        try:
            for i in range(1, len(args)):
                args[i] = int(args[i])
        except ValueError as e:
            print(f"Error parsing coordinates: {e}")
            print(f'Error details - Type: ValueError, Args: ("{e}",)')
            return
        args = args[1:]
        print(f"Position created: {tuple(args)}")
    elif len(args) == 2:
        print(f'Parsing coordinates: "{args[1]}"')
        args = args[1].strip("()").split(",")
        if len(args) != 3:
            print("Error: Coordinate must have 3 components (x,y,z)")
            return
        try:

            for i in range(len(args)):
                args[i] = int(args[i])
        except ValueError as e:
            print(f"Error parsing coordinates: {e}")
            print(f'Error details - Type: ValueError, Args: ("{e}",)')
            return
        print(f"Parsed position: {tuple(args)}")
    else:
        print("Error: Coordinate must have 3 components (x,y,z)")
        return
    distance = math.sqrt(
        (args[0] - 0) * (args[0] - 0)
        + (args[1] - 0) * (args[1] - 0)
        + (args[2] - 0) * (args[2] - 0)
    )
    print(f"Distance between (0, 0, 0) and {tuple(args)}: {distance:.2f}")
    print()
    print("Unpacking demonstration:")
    print(f"Player at x={args[0]}, y={args[1]}, z={args[2]}")
    print(f"Coordinates: X={args[0]},Y={args[1]},Z={args[2]}")


if __name__ == "__main__":
    main()
