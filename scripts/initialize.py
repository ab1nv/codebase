import asyncio
import os
import sys

from scripts.codeforces import handle_codeforces_problem
from scripts.leetcode import handle_leetcode_problem

sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), "..")))


def create_directory(path):
    if not os.path.exists(path):
        print(f"Creating {path} directory...")
        os.makedirs(path)


def display_menu():
    if os.name == "nt":
        os.system("cls")
    else:
        os.system("clear")

    print("Select an option:")
    print("1. Leetcode")
    print("2. Codeforces")

    choice = input("Enter 1 or 2: ").strip()

    if choice == "1":
        return "Leetcode"
    elif choice == "2":
        return "Codeforces"
    else:
        print("Invalid choice, please enter 1 or 2.")
        return display_menu()


async def main():
    choice = display_menu()

    base_path = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))

    if choice == "Leetcode":
        lc_dir = os.path.join(base_path, "leetcode")
        create_directory(lc_dir)
        await handle_leetcode_problem(lc_dir)
    elif choice == "Codeforces":
        cf_dir = os.path.join(base_path, "codeforces")
        create_directory(cf_dir)
        await handle_codeforces_problem(cf_dir)


if __name__ == "__main__":
    asyncio.run(main())
