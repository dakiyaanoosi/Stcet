# Program to check if two strings are Anagrams

str1 = input("String1: ").strip().lower()
str2 = input("String2: ").strip().lower()

if sorted(str1) == sorted(str2):
    print("Anagrams")
else:
    print("Not anagrams")