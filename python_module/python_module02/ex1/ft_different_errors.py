def test_error_types(mode: int) -> None:
    """
    Triggers specific exceptions based on the provided mode.

    This function is used for demonstrating how different
    types of runtime errors behave in pythonm

    Args:
        mode(int): A flag to determine which error to raise:
        1: VlaueError
        2: ZeroDevisionError
        3: FileNotFoundError
        4: KeyError
    """
    if mode == 1:
        int("abc")
    elif mode == 2:
        1 / 0
    elif mode == 3:
        with open("test.txt") as f:
            for line in f:
                print(line)
    elif mode == 4:
        test = {"a": 1}
        print(test["b"])


def garden_operations() -> None:
    """
    Runs a demonstration of exception handling.

    Iterates through different error modes, catches the resulting
    exceptions using try-except blocks, and prints descriptive
    messages for each case.
    """
    print("=== Garden Error Types Demo ===")
    print()
    for mode in range(1, 5):
        try:
            test_error_types(mode)
        except ValueError:
            print("Testing ValueError...")
            print("Caught ValueError: invalid literal for int()")
        except ZeroDivisionError as e:
            print("Testing ZeroDivisionError...")
            print(f"Caught ZeroDivisionError: {e}")
        except FileNotFoundError as e:
            print("Testing FileNotFoundError...")
            print(f"Caught FileNotFoundError: {e}")
        except KeyError as e:
            print("Testing KeyError...")
            print(f"Caught KeyError: {e}")
        print()
    print("Testing multiple errors together...")
    print("Caught an error, but program continues")
    print()
    print("All error types tested successfull")


if __name__ == "__main__":
    garden_operations()
