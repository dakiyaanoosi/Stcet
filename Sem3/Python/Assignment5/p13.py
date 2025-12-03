# Program to find the longest word in a sentence

sen = input("Sentence: ")
words = sen.split()

print(f"Longest word: {max(words, key=len)}")