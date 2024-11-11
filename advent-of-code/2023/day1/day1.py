def extract_front_num(line):
    front_num = -1
    for i in line:
        if i.isdigit():
            front_num = int(i)
            return front_num


def extract_last_num(line):
    last_num = -1
    for i in reversed(line):
        if i.isdigit():
            last_num = int(i)
            return last_num


def main():
    sum = 0
    with open(
        "/home/abhinav/code/codebase/advent-of-code/2023/day1/input.txt", "r"
    ) as file:
        for line in file:
            f = extract_front_num(line.strip())
            l = extract_last_num(line.strip())

            if f != -1 and l != -1:
                sum += f * 10 + l
        print(sum)


if __name__ == "__main__":
    main()
