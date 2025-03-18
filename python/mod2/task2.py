square_side_len = float(input("Введите длину стороны квадрата - "))
print(f"Периметр - {round(4*square_side_len, 2)}\n"
      f"Площадь - {round(square_side_len**2, 2)}\n"
      f"Диагональ - {round(((square_side_len**2)*2)**0.5, 2)}")