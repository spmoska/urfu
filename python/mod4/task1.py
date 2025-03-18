def show_message(numbers: [int]) -> str:
    set_numbers = set(numbers)
    if len(set_numbers) == 1:
        return "Все числа равные"
    elif len(set_numbers) == len(numbers):
        return "Все числа разные"
    else:
        return "Есть равные и неравные числа"

numbers = input("Введите числа через пробел - ").split(" ")

print(show_message(numbers))