import random
import string
import argparse
from pathlib import Path

def random_string(length=8):
    return ''.join(random.choices(string.ascii_lowercase, k=length))

def random_multiline_string(lines=3):
    return '"""\n' + '\n'.join(random_string(10) for _ in range(lines)) + '\n"""'

def random_value():
    choice = random.choice(['int', 'str', 'str', 'str', 'str', 'multiline'])
    if choice == 'int':
        return str(random.randint(0, 1000000))
    elif choice == 'str':
        return f'"{random_string(random.randint(5, 15))}"'
    elif choice == 'multiline':
        return random_multiline_string(random.randint(2, 5))

def generate_ini_by_size(target_kb, output="random.ini"):
    target_bytes = target_kb * 1024
    content = ["# Auto-generated ini file\n"]
    current_size = sum(len(line.encode('utf-8')) for line in content)

    while current_size < target_bytes:
        section = f"[{random_string(6)}]"
        content.append(section)
        for _ in range(random.randint(3, 10)):
            key = random_string(random.randint(5, 10))
            value = random_value()
            line = f"{key} = {value}"
            content.append(line)
            current_size += len((line + "\n").encode("utf-8"))
            if current_size >= target_bytes:
                break
        content.append("")  # blank line after section
        current_size += len("\n".encode("utf-8"))

    Path(output).write_text("\n".join(content), encoding='utf-8')
    print(f"File '{output}' generated ({current_size / 1024:.2f} KB).")

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Generate random ini (TOML-like) file of specified size.")
    parser.add_argument("-z", "--size", type=int, default=100, help="Target size in kilobytes (KB)")
    parser.add_argument("-o", "--output", type=str, default="random.ini", help="Output filename")
    args = parser.parse_args()

    generate_ini_by_size(args.size, args.output)