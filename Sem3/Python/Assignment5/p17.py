# Program to find the first non-repeated character

str = input("String: ").strip()

for ch in str:
    if str.count(ch) == 1:
        print(ch)
        break
else:
    print("No non-repeated characters found!")