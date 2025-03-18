class Node:
    """
    Вспомогательный класс для узлов списка
    """

    def __init__(self, data):
        self.data = data  # храним информацию
        self.nref = None  # ссылка на следующий узел
        self.pref = None  # Ссылка на предыдущий узел


class Queue:
    """
    Основной класс очереди
    """

    def __init__(self):
        self.start = None  # ссылка на начало очереди
        self.end = None  # ссылка на конец очереди

    def pop(self):
        """
        возвращаем элемент из начала списка с удалением его из списка
        """
        if self.start is None:
            raise IndexError("pop from empty queue")

        val = self.start.data  # сохраняем данные первого элемента
        self.start = self.start.nref  # сдвигаем ссылку на первый элемент

        if self.start:  # если очередь не пуста, сдвигаем ссылку на предыдущий элемент
            self.start.pref = None

        else:  # если очередь пуста, то конец очереди тоже None
            self.end = None

        return val

    def push(self, val):
        """
        добавление элемента в конец очереди
        """
        new_node = Node(val)  # создаем новый узел

        if self.end is None:  # если очередь пуста
            self.start = new_node
            self.end = new_node
        else:  # если очередь не пуста
            self.end.nref = new_node  # старый последний элемент ссылается на новый
            new_node.pref = self.end  # новый элемент ссылается на старый
            self.end = new_node  # новый элемент становится концом очереди

    def insert(self, n, val):
        """
        вставить элемент val между элементами с номерами n-1 и n
        """
        new_node = Node(val)

        if n <= 0:  # вставка в начало очереди
            new_node.nref = self.start

            if self.start:
                self.start.pref = new_node

            self.start = new_node

            if self.end is None:  # если очередь была пуста
                self.end = new_node
        else:
            current = self.start

            for _ in range(n - 1):  # ищем n-й элемент
                if current is None:
                    raise IndexError("Index out of bounds")

                current = current.nref

            new_node.nref = current.nref  # новый узел ссылается на следующий
            new_node.pref = current  # новый узел ссылается на текущий

            if current.nref:  # если не вставляем в конец
                current.nref.pref = new_node

            current.nref = new_node  # текущий узел ссылается на новый

            if new_node.nref is None:  # если вставили в конец
                self.end = new_node

    def print(self):
        """
        вывод на печать содержимого очереди
        """
        current = self.start

        while current:
            print(current.data, end=" ")
            current = current.nref

        print()  # переход на новую строку