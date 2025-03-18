string = str(input("Введите строку - "))

one_count = 0
zero_count = 0

for char in string:
    if char == "1": one_count += 1
    elif char == "0": zero_count += 1

if one_count == zero_count: print("yes")
else: print("no")