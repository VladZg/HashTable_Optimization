import re
import random

with open("./input_text.txt", "r") as input_file:
    text = input_file.read()

parsed = re.findall(r'[A-Za-z]+', text)     # find all words and skip punctuation marks
parsed = list(set(parsed))                  # remove repeated words from list
length = min(10000, len(parsed))

filling_words_parsed = random.sample(parsed, length)      # choose 10000 random words from list
with open("./filling_words.txt", "w") as filling_words_file:
    filling_words_file.write(str(length) + ' ' + ' '.join(filling_words_parsed))

searching_words_parsed = random.sample(parsed, length)
with open("./searching_words.txt", "w") as searching_words_file:
    searching_words_file.write(str(length) + ' ' + ' '.join(searching_words_parsed))

# interception = set(filling_words_parsed) & set(searching_words_parsed)
# print(len(interception))

# with open("./input_text_parsed", "wb") as output_file:
#     output_file.write((str(length) + '\n').encode())
#     for word_i in range(length):
#         output_file.write((str(parsed[word_i].zfill(32)) + '\n').encode())

# print(parsed_text)
