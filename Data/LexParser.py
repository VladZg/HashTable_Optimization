import re

with open("./input_text.txt", "r") as input_file:
    text = input_file.read()

# print(text)

parsed_text = ' '.join(re.findall(r'[A-Za-z]+', text))

with open("./input_text_parsed.txt", "w") as output_file:
    output_file.write(str(len(parsed_text)))
    output_file.write(' ')
    text = output_file.write(parsed_text)

# print(parsed_text)
