# TODO
from cs50 import get_string

# 0.0588 * L - 0.296 * S - 15.8
# where S is ave number of sentences per 100 words
# where L is average number of letters per 100 words

text = get_string("Text: ")

letters = 0
sentences = 0

for character in text:
    if character.isalpha():
        letters += 1

words = len(text.split())

for character in text:
    if character == '!' or character == '?' or character == '.':
        sentences += 1

S = (sentences/words) * 100
L = (letters/words) * 100

grade = 0.0588 * L - 0.296 * S - 15.8


if grade >= 16:
    print("Grade 16+")
elif grade < 1:
    print("Before Grade 1")
else:    
    print(f"Grade {round(grade)}")
