def check_year_leap(year: int) -> bool:
    """
    Проверяет високосный год или нет
    """

    return year % 4 == 0 and year % 100 != 0 or year % 400 == 0


def year_to_word(year: int) -> str:
    """
    Переводит численное представление года в словесное
    """

    year_thousand = year // 1000 if year // 1000 != 0 else None
    year_hundreds = year // 100 % 10 if year // 100 % 10 != 0 else None
    year_tens = year // 10 % 10 if year // 10 % 10 != 0 else None
    year_ones = year % 10 if year % 10 != 0 else None

    thousands_word = ("одна","две","три","четыре","пять","шесть","семь","восемь","девять")
    hundreds_in_word = ("сто","двести","триста","четыреста","пятьсот","шестьсот","семьсот","восемьсот","девятьсот")
    tens_in_word = ("десять","двадцать","тридцать","сорок","пятьдесят","шестьдесят","семьдесят","восемьдесят","девяносто")
    ones_in_word = ("первого","второго","третьего","четвертого","пятого","шестого","седьмого","восьмого","девятого")

    year_in_words = []

    if year_thousand:
        try:
            if year_thousand == 1: year_in_words.append(f"{thousands_word[year_thousand - 1]} тысяча")

            elif 2 <= year_thousand <= 4: year_in_words.append(f"{thousands_word[year_thousand - 1]} тысячи")

            elif 5 <= year_thousand <= 9: year_in_words.append(f"{thousands_word[year_thousand - 1]} тысяч")
        except:
            raise Exception("Год выходит за рамки 1000 - 9000")

    if year_hundreds:
        try:
            year_in_words.append(hundreds_in_word[year_hundreds - 1])
        except:
            raise Exception


    if year_tens:
        if year_tens == 1 and year_ones != 0:
            ones_in_word = ("один", "два", "три", "четыре", "пять", "шесть", "семь", "восемь", "девять")

            ten_in_word = ones_in_word[year_ones - 1]

            if ten_in_word[len(ten_in_word) - 1] == 'а':
                year_in_words.append(ten_in_word.replace("а", "енадцатое"))
            elif ten_in_word[len(ten_in_word) - 1] == 'и':
                year_in_words.append(f"{ten_in_word}надцатое")
            else:
                year_in_words.append(f"{ten_in_word[:-1]}надцатое")
        elif 1 <= year_tens <= 9 and year_ones == 0:
            year_in_words.append(f"{tens_in_word[year_tens - 1][:-1]}ого")
        else:
            year_in_words.append(tens_in_word[year_tens - 1])

    if year_ones:
        try:
            year_in_words.append(ones_in_word[year_ones - 1])
        except:
            raise Exception


    return f"{" ".join(year_in_words)} года"


def month_to_word(month: int) -> str :
    """
    Переводит численное представление месяца в словесное
    """

    months = ("января", "февраля","марта","апреля","мая","июня","июля","августа","сентября","октября","ноября","декабря")

    try:
        return months[month]
    except:
        raise Exception("Месяц указан неверно!")


def day_to_word(day: int, month: int, year: int) -> str:
    """
    Переводит численное представление дня в словесное
    """

    number_in_word = ("один","два","три","четыре","пять","шесть","семь","восемь","девять")
    number_in_word_date = ("первое","второе","третье","четвертое","пятое","шестое","седьмое","восьмое","девятое")

    if (day == 0 and 31 < day < 0) or (month % 2 == 0 and month not in (8, 12) and day > 30):
        raise Exception("День указан неверно!")

    if month == 2:
        if day > 29:
            raise Exception("В феврале максимум 29 дней")

        if not check_year_leap(year) and day > 28:
            raise Exception(f"{year} не високосный год")

    if day < 10:
        return number_in_word_date[day - 1]

    if day == 10:
        return "десятое"

    if 10 < day < 20:
        day_in_word = number_in_word[day % 10 - 1]

        if day_in_word[len(day_in_word) - 1] == 'а':
            return day_in_word.replace("а", "енадцатое")
        elif day_in_word[len(day_in_word) - 1] == 'и':
            return f"{day_in_word}надцатое"
        else:
            return f"{day_in_word[:-1]}надцатое"

    if day in [20, 30]:
        return f"{number_in_word[day // 10 - 1]}дцатое"

    if 20 < day <= 31:
        return f"{number_in_word[day // 10 - 1]}дцать {number_in_word_date[day % 10 - 1]}"

    return "Неизвестный день :)"


def convert_date(date: str):
    try:
        input_day, input_month, input_year = map(int, date.split("."))
        return f"{day_to_word(input_day, input_month, input_year)} {month_to_word(input_month)} {year_to_word(input_year)}"
    except:
        raise Exception("Неверный формат даты")

print(convert_date(str(input("Введите дату (формат 00.00.0000) - "))))