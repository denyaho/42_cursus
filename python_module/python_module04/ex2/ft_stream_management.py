#! /usr/bin/env python3

import sys


def stream_management() -> None:
    """
    Implements the Cyber Archives communication protocol
    using standard I/O streams.
    This function collect user input for archivist
    ID and stauts repot using stdin.
    Then, output messages via stdout/stderr
    """
    print("=== CYBER ARCHIVES - COMMUNICATION SYSTEM ===")
    print()
    print("Input Stream active. Enter archivist ID:", end=" ", flush=True)
    archivist_ID = sys.stdin.readline().strip()
    print("Input Stream active. Enter status report:", end=" ", flush=True)
    archivist_status = sys.stdin.readline().strip()
    print()
    sys.stdout.write(
        "[STANDARD] Archive staus from "
        f"{archivist_ID}: {archivist_status}\n"
    )
    sys.stderr.write("[ALERT] System diagnostic: "
                     "Communication channels verified\n")
    sys.stdout.write("[STANDARD] Data transmission complete\n")
    print()
    print("Three-channel communication test successful.")


if __name__ == "__main__":
    stream_management()
