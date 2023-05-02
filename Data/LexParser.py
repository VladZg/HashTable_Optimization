import re
import random

# with open("./input_text.txt", "r") as input_file:
#     text = input_file.read()

# parsed = re.findall(r'[A-Za-z]+', text)     # find all words and skip punctuation marks
# parsed = list(set(parsed))                  # remove repeated words from list
# length = min(10000, len(parsed))
# parsed = random.sample(parsed, 2*length)

# filling_words_parsed = random.sample(parsed, length)      # choose 10000 random words from list
# with open("./filling_words_bin.bin", "bw") as filling_words_file:
#     filling_words_file.write(str(length) + ' '.join(filling_words_parsed))

# searching_words_parsed = random.sample(parsed, length)
# with open("./searching_words_bin.bin", "bw") as searching_words_file:
#     searching_words_file.write(str(length) + ' '.join(searching_words_parsed))

# parsed = [str.zfill(32) for str in parsed]

# filling_words_parsed = random.sample(parsed, length)      # choose 10000 random words from list
# with open("./filling_words_bin.bin", "bw") as filling_words_file:
#     filling_words_file.write((''.join(filling_words_parsed)).encode())
#
# searching_words_parsed = random.sample(parsed, length)
# with open("./searching_words_bin.bin", "bw") as searching_words_file:
#     searching_words_file.write((''.join(searching_words_parsed)).encode())

# interception = set(filling_words_parsed) & set(searching_words_parsed)
# print(len(interception))

# with open("./input_text_parsed", "wb") as output_file:
#     output_file.write((str(length) + '\n').encode())
#     for word_i in range(length):
#         output_file.write((str(parsed[word_i].zfill(32)) + '\n').encode())

# print(parsed_text)

with open("./filling_words.txt", "r") as filling_words_input_file:
    filling_text = filling_words_input_file.read()

filling_text = filling_text.split()
filling_text_parsed = [str.ljust(32, '\0') for str in filling_text]

# for i in range(10000):
#     filling_text_parsed[i] = filling_text_parsed[i].replace('0', '\0')

# print(filling_text_parsed)

with open("./searching_words.txt", "r") as searching_words_input_file:
    searching_text = searching_words_input_file.read()

searching_text = searching_text.split()
searching_text_parsed = [str.ljust(32, '\0') for str in searching_text]

# for i in range(10000):
#     searching_text_parsed[i] = searching_text_parsed[i].replace('0', '\0')

# print(searching_text)

# filling_words_parsed = random.sample(parsed, length)      # choose 10000 random words from list
with open("./filling_words_bin.bin", "bw") as filling_words_output_file:
    filling_words_output_file.write((''.join(filling_text_parsed)).encode())
#
# # searching_words_parsed = random.sample(parsed, length)
with open("./searching_words_bin.bin", "bw") as searching_words_output_file:
    searching_words_output_file.write((''.join(searching_text_parsed)).encode())
