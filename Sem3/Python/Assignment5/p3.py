# Program to find the number of vowels in a string

vowels = ('a', 'e', 'i', 'o', 'u')

str = input("String: ").strip()
c = 0

for ch in str:
    if ch.lower() in vowels:
        c += 1

print("Vowels count:", c)