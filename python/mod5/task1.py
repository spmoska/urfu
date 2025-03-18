class Node:
    """
    Вспомогательный класс для узлов списка
    """

    def __init__(self, data):
        self.data = data  # храним информацию
        self.pref = None  # ссылка на предыдущий узел, может быть Node или None


class Stack:
    """
    Основной класс для стека
    """

    def __init__(self):
        self.end = None  # ссылка на конец стека, может быть Node или None

    def pop(self):
        """
        возвращение последнего элемента из списка с удалением его из списка
        """
        if self.end is None:
            raise IndexError("pop from empty stack")

        val = self.end.data  # сохраняем данные последнего элемента
        self.end = self.end.pref  # сдвигаем ссылку на конец стека
        return val

    def push(self, val):
        """
        добавление элемента val в конец списка
        """
        new_node = Node(val)  # создаем новый узел
        new_node.pref = self.end  # новый узел ссылается на старый конец стека
        self.end = new_node  # новый узел становится концом стека

    def print(self):
        """
        вывод на печать содержимого стека
        """
        current = self.end  # начинаем с конца стека

        while current:
            print(current.data, end=" ")  # выводим данные текущего узла
            current = current.pref  # переходим к предыдущему узлу

        print()  # переходим на новую строку