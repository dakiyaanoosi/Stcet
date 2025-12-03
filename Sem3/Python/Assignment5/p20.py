# Program to find all the substrings of a string

str = input("String: ").strip()
substrings = []
for i in range(len(str)):
    for j in range(i+1, len(str)+1):
        substrings.append(str[i:j])

print(substrings)