# Author: Abhinav Singh <https://github.com/ab1nv>
# AoC Day: 1
# Problem link: https://adventofcode.com/2024/day/1
# Timestamp: 11:32 AM IST, 1/12/2024

import os
from collections import Counter


def main() -> None:
    solution = Solution()
    file_name = os.path.basename(__file__)
    base_name = os.path.splitext(file_name)[0]
    day = base_name[base_name.find("D") + 1 :]
    input_path = f"advent-of-code/2024/day{day}/{base_name}.txt"
    solution.part_1(input_path)


##################################################################


class Solution:
    def __init__(self): ...

    def part_1(self, input: str) -> None:
        with open(input) as file:
            left_list = []
            right_list = []

            lines = file.readlines()
            for line in lines:
                left_val, right_val = map(int, line.split())
                left_list.append(left_val)
                right_list.append(right_val)

            left_list.sort()
            right_list.sort()

            total_distance = sum(
                self.calculate_difference(left, right)
                for left, right in zip(left_list, right_list)
            )

            print(f"Total distance: {total_distance}")
            self.part_2(left_list, right_list)

    def calculate_difference(self, left_val, right_val) -> int:
        return abs(left_val - right_val)

    def calculate_score(self, val, frequency) -> int:
        return val * frequency

    def part_2(self, left_list, right_list):
        right_freq = Counter(right_list)

        sum = 0
        for i in left_list:
            freq = right_freq[i]
            sum += self.calculate_score(i, freq)

        print(f"Total similarity score: {sum}")


if __name__ == "__main__":
    main()
