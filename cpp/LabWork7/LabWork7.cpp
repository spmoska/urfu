#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>

// Базовый класс Point
class Point {
protected:
    int x, y;       // Координаты
    sf::Color color; // Цвет

public:
    Point(int x = 0, int y = 0, sf::Color color = sf::Color::White)
        : x(x), y(y), color(color) {
    }

    void setPos(int newX, int newY) {
        x = newX;
        y = newY;
    }

    virtual void draw(sf::RenderWindow& window) = 0; // Виртуальный метод для отрисовки
};

// Класс Circle (наследник Point)
class Circle : public Point {
protected:
    float radius;

public:
    Circle(int x, int y, float radius, sf::Color color)
        : Point(x, y, color), radius(radius) {
    }

    void draw(sf::RenderWindow& window) override {
        sf::CircleShape circle(radius);
        circle.setFillColor(color);
        circle.setPosition(x, y);
        window.draw(circle);
    }

    void moveRandom(int cost, int screenWidth, int screenHeight) {
        // Случайное изменение координат
        x += rand() % (cost * 2) - cost;
        y += rand() % (cost * 2) - cost;

        // Случайное изменение размера
        radius = 20 + rand() % 81;

        // Случайное изменение цвета
        color = sf::Color(rand() % 256, rand() % 256, rand() % 256);

        // Ограничение по границам окна
        int diameter = radius * 2;

        if (x < 0) x = 0;
        if (y < 0) y = 0;
        if (x > screenWidth - diameter) x = screenWidth - diameter;
        if (y > screenHeight - diameter) y = screenHeight - diameter;
    }
};

// Класс Ring (наследник Circle)
class Ring : public Circle {
private:
    float width;

public:
    Ring(int x, int y, float radius, float width, sf::Color color)
        : Circle(x, y, radius, color), width(width) {
    }

    void draw(sf::RenderWindow& window) override {
        // Отображаем внешний круг
        sf::CircleShape outer(radius);
        outer.setFillColor(color);
        outer.setPosition(x, y);
        window.draw(outer);

        // Отображаем внутренний круг (для создания эффекта кольца)
        sf::CircleShape inner(radius - width);
        inner.setFillColor(sf::Color::Black);
        inner.setPosition(x + width, y + width);
        window.draw(inner);
    }
};

int main() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    // Инициализация окна
    sf::RenderWindow window(sf::VideoMode(800, 600), "Лабораторная работа 7", sf::Style::Default, settings);
    window.setFramerateLimit(60);

    // Получение размеров окна
    int screenWidth = window.getSize().x;
    int screenHeight = window.getSize().y;

    // Инициализация случайных чисел
    std::srand(std::time(0));

    // Создание объектов
    Circle testCircle(150, 40, 50, sf::Color::Red); // Позиция (150, 40), радиус 50
    Ring testRing(450, 80, 90, 10, sf::Color::Blue); // Позиция (450, 80), радиус 90, ширина 10

    // Главный цикл
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                // При нажатии клавиши объекты начинают двигаться
                testCircle.moveRandom(100, screenWidth, screenHeight);
                testRing.moveRandom(60, screenWidth, screenHeight);
            }
        }

        // Очистка экрана
        window.clear(sf::Color::Black);

        // Отображение объектов
        testCircle.draw(window);
        testRing.draw(window);

        // Обновление окна
        window.display();
    }

    return 0;
}
