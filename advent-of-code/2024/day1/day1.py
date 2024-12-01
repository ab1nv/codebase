from collections import Counter


def calculate_difference(left_val, right_val) -> int:
    return abs(left_val - right_val)


def calculate(input):
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
            calculate_difference(left, right)
            for left, right in zip(left_list, right_list)
        )

        print(f"Total distance: {total_distance}")
        frequency_sum(left_list, right_list)


# Part 2 code


def calculate_score(val, frequency) -> int:
    return val * frequency


def frequency_sum(left_list, right_list):
    right_freq = Counter(right_list)

    sum = 0
    for i in left_list:
        freq = right_freq[i]
        sum += calculate_score(i, freq)

    print(f"Total similarity score: {sum}")


if __name__ == "__main__":
    calculate("advent-of-code/2024/day1/input.txt")
