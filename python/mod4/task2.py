def exponentiation(a: int, n: int) -> int:
    if n == 0:
        return 1
    elif n % 2 == 0:
        return exponentiation(a, n // 2)**2
    else:
        return a * exponentiation(a, n - 1)

a, n = map(int, input("Введите число и степень, в которую необходимо возвести (через пробел) - ").split(" "))

print(exponentiation(a, n))