try:
    num = int(input("Введите натуральное число - "))

    if num < 0:
        print("Неверный ввод")
    else:
        def to_base(num: int, base: int) -> str:
            digits = "0123456789ABCDEF"
            result = ""
            while num > 0:
                result = digits[num % base] + result
                num //= base
            return result if result else "0"

        print(to_base(num, 2))
        print(to_base(num, 8))
        print(to_base(num, 16))
except:
    print("Неверный ввод")