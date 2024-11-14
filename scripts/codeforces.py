import os
import re

import aiohttp
from bs4 import BeautifulSoup as bf

from scripts.utils import display_menu, get_file_extension, save_metadata

headers = {
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.36",
}


def extract_problem_code(url):
    match = re.search(r"/problemset/problem/(\d+/\w+)", url)
    return match.group(1).replace("/", "") if match else "000"


def format_problem_title(raw_title):
    problem_code, problem_name = raw_title.split(".", 1)
    problem_code = problem_code.strip()
    problem_name = problem_name.strip()
    filename_title = problem_code.lower()
    return problem_name, filename_title, problem_code


async def fetch_codeforces_data(question_url):
    async with aiohttp.ClientSession() as session:
        async with session.get(question_url, headers=headers) as response:
            text = await response.text()
            return parse_codeforces_data(text)


def parse_codeforces_data(html_text):
    soup = bf(html_text, "html.parser")
    title_div = soup.find("div", class_="title")
    raw_title = title_div.text.strip() if title_div else "UnknownCode. Unknown Problem"
    question_name, filename_title, problem_code = format_problem_title(raw_title)
    problem_statement_div = soup.find("div", class_="ttypography")
    problem_statement = (
        problem_statement_div.text.strip()
        if problem_statement_div
        else "No problem statement available."
    )
    input_spec_div = soup.find("div", class_="input-specification")
    input_spec = (
        input_spec_div.text.strip() if input_spec_div else "No input specification."
    )
    output_spec_div = soup.find("div", class_="output-specification")
    output_spec = (
        output_spec_div.text.strip() if output_spec_div else "No output specification."
    )
    sample_tests_div = soup.find("div", class_="sample-tests")
    sample_tests = ""
    if sample_tests_div:
        input_example = sample_tests_div.find("div", class_="input")
        output_example = sample_tests_div.find("div", class_="output")
        sample_tests = (
            f"Input:\n{input_example.text.strip()}\n\nOutput:\n{output_example.text.strip()}"
            if input_example and output_example
            else "No sample tests."
        )
    note_div = soup.find("div", class_="note")
    note = note_div.text.strip() if note_div else "No additional notes."
    tags_div = soup.find_all("span", class_="tag-box")
    tags = [tag.text.strip() for tag in tags_div]
    difficulty = ""
    if tags and tags[-1].startswith("*"):
        difficulty = tags[-1].strip("*")
        tags.pop()
    return {
        "title": question_name,
        "filename_title": filename_title,
        "problem_code": problem_code,
        "problem_statement": problem_statement,
        "input_specification": input_spec,
        "output_specification": output_spec,
        "sample_tests": sample_tests,
        "note": note,
        "tags": ", ".join(tags),
        "difficulty": difficulty,
    }


async def handle_codeforces_problem(base_path):
    if os.name == "nt":
        os.system("cls")
    else:
        os.system("clear")
    question_url = input("Enter Question URL: ").strip()
    data = await fetch_codeforces_data(question_url)
    if not data:
        print("Question not found.")
        return
    problem_code = extract_problem_code(question_url)
    data["problem_code"] = problem_code
    language_options = ["Python", "C++", "Rust", "C", "Go", "JavaScript", "TypeScript"]
    lang_choice = display_menu("Choose your language:", language_options)
    language = language_options[lang_choice].lower()
    file_extension = get_file_extension(language)
    problemset_path = os.path.join(base_path, "problemset", problem_code)
    file_path = os.path.join(problemset_path, f"{problem_code}.{file_extension}")
    if not os.path.exists(problemset_path):
        os.makedirs(problemset_path)
    if not os.path.exists(file_path):
        with open(file_path, "w") as f:
            save_metadata(f, data["title"], question_url, language)
            template_path = os.path.join(
                base_path, "template", f"basic.{file_extension}"
            )
            if os.path.exists(template_path):
                with open(template_path, "r") as template_file:
                    f.write(template_file.read())
    readme_path = os.path.join(problemset_path, "README.md")
    if not os.path.exists(readme_path):
        with open(readme_path, "w") as f:
            f.write(f"# {data['title']}\n\n")
            f.write(f"**Difficulty**: {data['difficulty']}\n\n")
            f.write(f"## Problem Statement\n{data['problem_statement']}\n\n")
            f.write(f"## Input Specification\n{data['input_specification']}\n\n")
            f.write(f"## Output Specification\n{data['output_specification']}\n\n")
            f.write(f"## Sample Tests\n{data['sample_tests']}\n\n")
            if data["note"]:
                f.write(f"## Note\n{data['note']}\n")
            solution_link = f"[{language.capitalize()}](./{problem_code}/{problem_code}.{file_extension})"
            f.write(f"\n## Solution\n{solution_link}\n")
    problem_map_path = os.path.join(base_path, "README.md")
    solution_link = f"[{language.capitalize()}](./problemset/{problem_code}/{problem_code}.{file_extension})"
    problem_entry = f"[{data['title']}]({question_url})"
    with open(problem_map_path, "r+") as problem_map:
        content = problem_map.readlines()
        table_start = next(
            (i for i, line in enumerate(content) if line.strip().startswith("| No. |")),
            None,
        )
        if table_start is None:
            content.append(
                "\n\n### Problem Set\n\n| No. | Problem | Solution | Tags | Difficulty |\n|----------|----------|----------|----------|----------|\n"
            )
            table_start = len(content)
        entry_exists = False
        for i in range(table_start, len(content)):
            line = content[i]
            if f"| {problem_code} |" in line:
                entry_exists = True
                line_parts = line.strip().split("|")
                if len(line_parts) > 2 and solution_link not in line_parts[2]:
                    line_parts[3] = line_parts[3].strip() + f", {solution_link}"
                    content[i] = "|".join(line_parts) + "\n"
                break
        if not entry_exists:
            new_row = f"| {problem_code} | {problem_entry} | {solution_link} | {data['tags']} | {data['difficulty']} |\n"
            content.append(new_row)
        problem_map.seek(0)
        problem_map.truncate(0)
        problem_map.writelines(content)
    print(f"Problem saved at: {file_path}")
