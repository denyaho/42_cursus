#! /usr/bin/env python3


def read_data_from_file() -> None:
    """
    This function tries to access to 'ancient_fragment.txt' and
    display the contents of file.
    If the file is inaccessible, display Error sentences.
    """
    print("=== CYBER ARCHIVES - DATA RECOVERY SYSTEM ===")
    print()
    file = None
    try:
        file = open("ancient_fragment.txt", "r")
        print(f"Accessing Storage Vault: {file.name}")
        print("Connection established...")
        print()
        print("RECOVERED DATA:")
        data = file.read()
        print(data)
        print()
        print("Data recovery complete. Storage unit disconnected.")
    except FileNotFoundError:
        print("ERROR: Storage vault not found. Run data generator first.")
    except PermissionError:
        print("ERROR: Permission denied. check the permission of given files")
    except Exception as e:
        print(e)
    finally:
        if file is not None:
            file.close()


if __name__ == "__main__":
    read_data_from_file()
