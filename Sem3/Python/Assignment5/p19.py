# Program to remove all punctuations from a string
import string

str = input("String: ")
new_str = ''

for ch in str:
    if ch not in string.punctuation:
        new_str += ch

print(new_str)