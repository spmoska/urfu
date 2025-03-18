phone_number = str(input("Введите номер телефона - "))

new_phone_number = ""
for char in phone_number:
    if char not in ['-', '(', ')', ' ']:
        new_phone_number += char

print(new_phone_number)
