#! /usr/bin/env python3


def secure_vault_access() -> None:
    """
    This function implements secure file operation using "with".
    try to access to 'classifed_data.txt' and 'security_protocols.txt'
    Create these files using data_generator.py first.
    """
    print("=== CYBER ARCHIVES - VAULT SECURITY SYSTEM ===")
    print()
    print("Initiating secure vault access...")
    print("Vault connection established with failsafe protocols")
    print()
    try:
        print("SECURE EXTRACTION:")
        with open("classified_data.txt", "r") as f:
            data = f.read()
            print(data)
        print()
        print("SECURE PRESERVATION:")
        with open("security_protocols.txt", "a") as f:
            f.write("[CLASSIFIED] New security protocols archived\n")
            f.write("Vault automatically sealed upon completion\n")
            print("[CLASSIFIED] New security protocols archived")
            print("Vault automatically sealed upon completion")
    except FileNotFoundError as e:
        print(e)
    except PermissionError as e:
        print(e)
    except Exception as e:
        print(e)
    else:
        print()
        print("All vault operations completed with maximum security")


if __name__ == "__main__":
    secure_vault_access()
