def find_nod(a: int, b: int) -> int:
    if a > b:
        return find_nod(a - b, b)
    elif b > a:
        return find_nod(a, b - a)
    else:
        return a

a, b = map(int, input("Введите два числа через пробел - ").split(" "))
print(find_nod(a, b))