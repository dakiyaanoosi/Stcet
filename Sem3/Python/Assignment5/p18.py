# Program to check if a string is panagram

str = input("String: ").lower()
alphabets = set("abcdefghijklmnopqrstuvwxyz")

if alphabets <= set(str):
    print("Pangram")
else:
    print("Not a panagram")
