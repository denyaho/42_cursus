#! /usr/bin/env python3

import sys


if __name__ == "__main__":
    args = sys.argv

    print("=== Player Score Analytics ===")
    if len(args) == 1:
        print(
            f"No scores provided."
            f" Usage: python3 {args[0][2:]} <score1> <score2> ..."
        )
    else:
        scores = []
        try:
            for i in range(1, len(args)):
                scores.append(int(args[i]))
        except ValueError as e:
            print(e)
        else:
            print(f"Scores processed: {scores}")
            print(f"Total players: {len(scores)}")
            print(f"Total score: {sum(scores)}")
            print(f"Average score: {sum(scores) / len(scores)}")
            print(f"High score: {max(scores)}")
            print(f"Low score: {min(scores)}")
            print(f"Score range: {max(scores) - min(scores)}")
