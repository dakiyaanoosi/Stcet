# Program to replace a word in a string

str = input("String: ")
replace = input("Replace: ")
while replace not in str:
    replace = input("Replace: ")

wth = input("With: ")

new_str = str.replace(replace, wth)
print("New string:", new_str)