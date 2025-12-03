# Program to find frequency of each character in a string

str = input("String: ").strip()

freq = {ch: str.count(ch) for ch in str}

for ch in freq:
    print(f"{ch}: {freq[ch]}")