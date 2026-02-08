#! /usr/bin/env python3


def crisis_response_system(filename: str) -> None:
    """
    This function implements error handling for accessing files.
    Show error messages if file doesn't exist or
    there's no permission to access to file.
    param:
        filename -> filename that this program tries to access.
    """
    print("=== CYBER ARCHIVES - CRISIS RESPONSE SYSTEM ===")
    print()
    try:
        with open(filename, "r") as f:
            data = f.read()
    except FileNotFoundError:
        print(f"CRISIS ALERT: Attempting access to '{filename}'")
        print("RESPONSE: Archive not found in storage matrix")
        print("STATUS: Crisis handled, system stable")
    except PermissionError:
        print(f"CRISIS ALERT: Attempting access to '{filename}'")
        print("RESPONSE: Security protocols deny access")
        print("STATUS: Crisis handled, security maintained")
    except Exception as e:
        print(e)
    else:
        print(f"ROUTINE ACCESS: Attempting access to '{filename}'")
        print(f"SUCCESS: Archive recovered - ''{data}''")
        print("STATUSS: Normal operations resumed")
    print()
    print("All crisis scenarios handled successfully. Archives secure.")


if __name__ == "__main__":
    crisis_response_system("standard_archive.txt")
