# Algorithms, Data Structures and Data Models
## Data Models On C++

Данная папка содержит академическую библиотеку кастомных моделей данных, их реализации покрыты тестами.

---

## Спецификация реализованных моделей данных

Здесь представлены реализации следующих объектных моделей:
1.  **Display.hpp / .cpp:** Абстрактный класс `Display`.
2.  **Laptop.hpp / .cpp и TV.hpp / .cpp:** Классы-наследники класса `Display`.

---

## Описание моделей данных

### Display.hpp / .cpp:

Абстрактный класс с полями `ResolutionTypes resolution` и `int diagonal`, у которых модификатор доступа `protected`.
Методы:
* `float CountDisplayScore() const`: Вычисляет рейтинг экрана.
* `const char* GetResolution() const`: Возвращает разрешение экрана.
* `int GetDiagonal() const`: Возвращает длину диагонали экрана.
* `bool SetResolution(ResolutionTypes new_resolution)`: Изменяет значение разрешения экрана.
* `bool SetDiagonal(int new_diagonal)`: Изменяет значение длины диагонали экрана.
* `virtual void PrintInfo() const = 0`: Виртуальная функция для вывода характеристик.

### Laptop.hpp / .cpp

Класс-наследник класса `Display`.
Поля:
* `int battery_capacity`
* `int battery_life`
Методы:
* `float GetScore() const`: Вычисляет рейтинг ноутбука.
* `int GetBatteryCapacity() const`: Возвращает значение емкости аккумулятора.
* `int GetBatteryLife() const`: Возвращает время работы без подзарядки.
* `bool SetBatteryCapacity(int new_battery_capacity)`: Изменяет значение емкости аккумулятора.
* `bool SetBatteryLife(int new_battery_life)`: Изменяет время работы без подзарядки.
* `void PrintInfo() const override`: Выводит характеристики ноутбука.
* `bool operator==(const Laptop& another_laptop) const`: Перегрузка оператора сравнения.
* `bool operator>(const Laptop& another_laptop) const`: Перегрузка оператора сравнения.
* `bool operator<(const Laptop& another_laptop) const`: Перегрузка оператора сравнения.
* `bool operator>=(const Laptop& another_laptop) const`: Перегрузка оператора сравнения.
* `bool operator<=(const Laptop& another_laptop) const`: Перегрузка оператора сравнения.

### TV.hpp / .cpp

Класс-наследник класса `Display`.
Поля:
* `bool smart_tv`
* `bool HDR`
Методы:
* `float GetScore() const`
* `bool IsThereSmartTV() const`: Возвращает `true`, если есть поддержка Smart TV, иначе - `false`.
* `bool IsThereHDR() const`: Возвращает `true`, если есть HDR, иначе - `false`.
* `void SetSmartTV(bool new_value_of_smart_tv)`: Изменяет информацию о поддержке Smart TV.
* `void SetHDR(bool new_value_of_HDR)`: Изменяет информацию о поддержке HDR.
* `void PrintInfo() const override`: Выводит характеристики телевизора.
* `bool operator==(const TV& another_tv) const`: Перегрузка оператора сравнения.
* `bool operator>(const TV& another_tv) const`: Перегрузка оператора сравнения.
* `bool operator<(const TV& another_tv) const`: Перегрузка оператора сравнения.
* `bool operator>=(const TV& another_tv) const`: Перегрузка оператора сравнения.
* `bool operator<=(const TV& another_tv) const`: Перегрузка оператора сравнения.

---

## Системные требования

Перед запуском убедитесь, что у вас установлены:
1.  Компилятор `g++`.
2.  Утилита `make`.
3.  Библиотека `gtest`.

---

## Инструкция по работе

* Сборка статической и динамической библиотек: `make`
* Запуск тестов: `make test`

---

## Автор

*   **Автор:** PastMaster1