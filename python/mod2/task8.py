words = str(input("Введите слова через пробел - "))

result_word = ""
for char_id in range(len(words)):
    if char_id == 0 or words[char_id - 1] == " ":
        continue

    if words[char_id] == " ":
        result_word += words[char_id - 1]
    elif char_id == len(words) - 1:
        result_word += words[char_id]

print(result_word)
