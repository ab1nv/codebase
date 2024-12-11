# Author: Abhinav Singh <https://github.com/ab1nv>
# AoC Day: 2
# Problem link: https://adventofcode.com/2024/day/2
# Timestamp: 9:00 PM IST, 3/12/2024

import os


def main() -> None:
    solution = Solution()
    file_name = os.path.basename(__file__)
    day = file_name[file_name.find("D") + 1 : file_name.find(".")]
    input_path = f"advent-of-code/2024/day{day}/{file_name}.txt"
    solution.part_1(input_path)
    solution.part_2(input_path)


##################################################################


class Solution:
    def __init__(self): ...

    def part_1(self, input: str) -> None:
        with open(input) as f:
            file = f.readlines()
            safe = 0
            for line in file:
                if self.safe_or_unsafe(line):
                    safe += 1
        print(f"Safe Reports: {safe}")

    def part_2(self, input: str) -> None: ...
    def safe_or_unsafe(self, line: str) -> bool: ...


if __name__ == "__main__":
    main()
