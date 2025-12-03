# Program to check if a string is Palindrome

str = input("String: ").strip()
if str == str[::-1]:
    print("Palindrome")
else:
    print("Not Palindrome")