import os

import aiohttp

from scripts.utils import display_menu, get_file_extension, save_metadata


async def fetch_leetcode_data(question_name):
    url = f"https://alfa-leetcode-api.onrender.com/select?titleSlug={question_name}"
    async with aiohttp.ClientSession() as session:
        async with session.get(url) as response:
            return await response.json()


async def handle_leetcode_problem(base_path):
    if os.name == "nt":
        os.system("cls")
    else:
        os.system("clear")
    question_url = input("Enter Question URL: ").strip()
    question_name = question_url.split("problems/")[-1].split("/")[0]

    print("Fetching question data...")
    data = await fetch_leetcode_data(question_name)

    if not data:
        print("Question not found.")
        return

    language_options = ["Python", "Go", "Rust", "C", "C++", "JavaScript", "TypeScript"]
    lang_choice = display_menu("Choose your language:", language_options)
    language = language_options[lang_choice].lower()
    file_extension = get_file_extension(language)

    question_dir = os.path.join(base_path, question_name.replace("-", "_"))
    file_path = os.path.join(
        question_dir, f"{question_name.replace('-', '_')}.{file_extension}"
    )

    if not os.path.exists(question_dir):
        print(f"Creating {question_dir} directory...")
        os.makedirs(question_dir)

    if os.path.exists(file_path):
        print("File already exists.")
    else:
        with open(file_path, "w") as f:
            save_metadata(f, data["questionTitle"], question_url, language)

    readme_path = os.path.join(question_dir, "README.md")
    if not os.path.exists(readme_path):
        with open(readme_path, "w") as f:
            f.write(f"# {data['questionTitle']}\n\n{data['question']}\n")

    print(f"Problem saved at: {file_path}")
