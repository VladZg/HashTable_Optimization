import re

with open("./input_text.txt", "r") as input_file:
    text = input_file.read()

parsed = re.findall(r'[A-Za-z]+', text)     # find all words and skip punctuation marks
parsed = list(set(parsed))                  # remove repeated words from list

for i in range(len(parsed)):
    parsed_i_byte = parsed[i].encode('utf-8')
    print(parsed[i], end=": ")
    for j in range(len(parsed[i])):
        print(parsed_i_byte[j], end=" ")
    print()

parsed_text = ' '.join(parsed)              # convert from list to string

with open("./input_text_parsed.txt", "w") as output_file:
    output_file.write(str(len(parsed)))
    output_file.write(' ')
    text = output_file.write(parsed_text)

# print(parsed_text)
