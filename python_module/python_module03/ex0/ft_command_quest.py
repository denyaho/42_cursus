#! /usr/bin/env python3

import sys

if __name__ == "__main__":
    args = sys.argv
    print("=== Command Quest ===")

    if len(args) == 1:
        print("No arguments provided!")
        print(f"Program name: {args[0]}")
        print(f"Total arguments: {1}")
    else:
        print(f"Program name: {args[0]}")
        print(f"Arguments received: {len(args) - 1}")
        idx = 1
        for i in range(1, len(args)):
            if args[i] == "":
                continue
            else:
                print(f"Argument {idx}: {args[i]}")
                idx += 1
        print(f"Total arguments: {idx}")
