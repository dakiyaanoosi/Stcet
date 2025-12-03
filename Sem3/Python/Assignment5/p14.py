# Program to count the frequency of each word in a sentence

sen = input("Sentence: ").strip().lower()
words = sen.split()

counts = {word: words.count(word) for word in words}

for count in counts:
    print(f"{count}: {counts[count]}")