import os
from datetime import datetime


def display_menu(prompt, options):
    if os.name == "nt":
        os.system("cls")
    else:
        os.system("clear")
    print(prompt)
    for idx, option in enumerate(options):
        print(f"{idx + 1}. {option}")
    choice = int(input("Enter choice number: ")) - 1
    return choice


def get_file_extension(language):
    extensions = {
        "python": "py",
        "go": "go",
        "rust": "rs",
        "c": "c",
        "c++": "cpp",
        "javascript": "js",
        "typescript": "ts",
    }
    return extensions.get(language, "txt")


def save_metadata(file, title, url, language):
    comment_styles = {
        "python": "#",
        "go": "//",
        "rust": "//",
        "c": "//",
        "c++": "//",
        "javascript": "//",
        "typescript": "//",
    }

    # Default to "#" for unknown languages
    comment_symbol = comment_styles.get(language, "#")

    # Create the metadata with the correct comment symbol
    metadata = f"""{comment_symbol} Author: Abhinav Singh
{comment_symbol} Question: {title}
{comment_symbol} Source: {url}
{comment_symbol} Date: {datetime.now().strftime("%d/%m/%Y")}
"""
    file.write(metadata + "\n\n")
