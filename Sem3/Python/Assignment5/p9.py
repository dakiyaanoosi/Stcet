# Program to check if a substring exists in a string

str = input("String: ")
substring = input("Substring: ")

if substring in str:
    print("Substring exists")
else:
    print("Substring doesn't exists")