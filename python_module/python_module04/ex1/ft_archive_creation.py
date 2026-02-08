#! /usr/bin/env python3


def create_archive(file_name: str) -> None:
    """
    This function tries to create 'new_discovery.txt'
    and write sentences to it using open/write/close
    """
    print("=== CYBER ARCHIVES - PRESERVATION SYSTEM ===")
    print()
    file = None
    try:
        file = open(file_name, "w", encoding="utf-8")
        print(f"Initializing new storage unit: {file.name}")
        print("Storage unit created successfully...")
        print()
        file.write("[ENTRY 001] New quantum algorithm discovered\n")
        file.write("[ENTRY 002] Efficiency increased by 347%\n")
        file.write("[ENTRY 003] Archived by Data Archivist trainee\n")
        print("Inscribing preservation data...")
        print("[ENTRY 001] New quantum algorithm discovered")
        print("[ENTRY 002] Efficiency increased by 347%")
        print("[ENTRY 003] Archived by Data Archivist trainee")
        print()
        print("Data inscription complete. Storage unit sealed.")
        print(f"Archive '{file_name}' ready for long-term preservation.")
    except Exception as e:
        print(e)
    finally:
        if file is not None:
            file.close()


if __name__ == "__main__":
    file_name = "new_discovery.txt"
    create_archive(file_name)
