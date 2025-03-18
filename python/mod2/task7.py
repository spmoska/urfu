string, find_char = str(input("Введите строку - ")), str(input("Введите символ - "))

find_char_count = 0
for char in string:
    if char == find_char:
        find_char_count += 1
    else:
        print(find_char_count)
        break