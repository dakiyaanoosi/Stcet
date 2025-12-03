# Program to remove duplicates from a string

str = input("String: ").strip()
result = ''

for ch in str:
    if ch not in result:
        result += ch

print(result)