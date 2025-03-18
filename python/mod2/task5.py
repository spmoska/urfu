domain = str(input("Введите домен - "))[::-1]

domain_level = ""
for char_id in range(len(domain)):
    if domain[char_id] == '.':
        print(domain_level[::-1])
        domain_level = ""
    elif char_id == len(domain) - 1:
        domain_level += domain[char_id]
        print(domain_level[::-1])
    else:
        domain_level += domain[char_id]