def palindrome(string: str) -> str:
    char_count = {}
    odd_count = 0

    for char in string:
        char_count[char] = char_count.get(char, 0) + 1
        odd_count += 1 if char_count[char] % 2 else -1

    if odd_count > 1:
        return "Невозможно составить палиндром"
    else:
        half = "".join(char * (char_count[char] // 2) for char in sorted(char_count))
        middle_char = next((char for char in char_count if char_count[char] % 2), '')

        return half + middle_char + half[::-1]

string = str(input("Введите слово - ")).strip()
print(palindrome(string))