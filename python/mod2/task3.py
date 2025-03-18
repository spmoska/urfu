numbers_string = str(input("Введите три числа через пробел - ")).replace(" ", "")

numbers_array = []
number = ""
for char_id in range(len(numbers_string)):
    if char_id != 0 and numbers_string[char_id - 1] == " ":
        continue

n = len(array)
for i in range(n):
    swapped = False  # Оптимизация: проверка, произошёл ли обмен
    for j in range(0, n - i - 1):
        if array[j] > array[j + 1]:
            array[j], array[j + 1] = array[j + 1], array[j]  # Обмен элементов
            swapped = True