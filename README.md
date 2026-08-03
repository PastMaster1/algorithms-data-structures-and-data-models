# Algorithms, Data Structures and Data Models

Репозиторий содержит академическую библиотеку задач на алгоритмы, структуры данных и модели данных,
их решения покрыты тестами. В репозитории есть интерактивные консольные приложения для
демонстрации работы программ.

---

## Технологический стек

*  **C#:** платформа `.NET 8.0 SDK`, библиотека для тестирования `xUnit`. 
*  **C++:** компилятор `g++`, стандарт `C++17`, библиотека для тестирования `gtest`.
*  Утилита `make`.

---

## Архитектура и структура репозитория

Проект разделен на несколько изолированных модулей:

*   **(./src/MyDataStructures/)** — кастомные структуры данных.
*   **(./src/DataModels/)** — кастомные модели данных.
*   **(./src/AlgorithmsAndDataStructuresProblemSolutions/)** — решения алгоритмических задач.
*   **(./src/DemonstrationOfSoftware/)** — интерактивные консольные CLI-приложения.
*   **(./tests/)** — проекты автоматического тестирования программ.

---

## Спецификация реализованных задач

### Решения задач на алгоритмы и структуры данных:

1.  **StructureMinStack.cs:** Стек с поддержкой получения минимума за O(1).
2.  **GenerateParentheses.cs:** Рекурсивный генератор правильных скобочных последовательностей.
3.  **AnagramGrouping.cs:** Группировка слов-анаграмм.
4.  **EncodeAndDecode.cs:** Кодирование и декодирование строк.
5.  **TopFrequentElements.cs:** Поиск самых частых элементов массива.

### Объектные модели
1.  **Display.hpp / .cpp:** Абстрактный класс `Display`.
2.  **Laptop.hpp / .cpp и TV.hpp / .cpp:** Классы-наследники класса `Display`.

---

## Инструкции по запуску

*   Инструкции по запуску находятся в локальных `README.md` в соответствующих директориях.

---

## Структура репозитория

```text
.
|   .gitignore
|   AlgorithmsAndDataStructures.sln
|   README.md
|
+---.github
|   \---workflows
|           main.yml
|
+---src
|   +---AlgorithmsAndDataStructuresProblemSolutions
|   |   \---AlgorithmsAndDataStructuresProblemSolutionsOnCs
|   |           AlgorithmsAndDataStructuresProblemSolutionsOnCs.csproj
|   |           AnagramGrouping.cs
|   |           EncodeAndDecode.cs
|   |           GenerateParentheses.cs
|   |           Makefile
|   |           README.md
|   |           TopFrequentElements.cs
|   |
|   +---DataModels
|   |   \---Cpp
|   |       |   Makefile
|   |       |   README.md
|   |       |
|   |       +---include
|   |       |       Display.hpp
|   |       |       Laptop.hpp
|   |       |       ResolutionTypes.hpp
|   |       |       TV.hpp
|   |       |
|   |       \---source_code
|   |               Display.cpp
|   |               Laptop.cpp
|   |               TV.cpp
|   |
|   +---DemonstrationOfSoftware
|   |   +---Cpp
|   |   |   |   Makefile
|   |   |   |   README.md
|   |   |   |
|   |   |   +---include
|   |   |   |   \---DataModels
|   |   |   |           Laptop_Demo.hpp
|   |   |   |           TV_Demo.hpp
|   |   |   |
|   |   |   \---src
|   |   |       |   main.cpp
|   |   |       |
|   |   |       \---DataModels
|   |   |               Laptop_Demo.cpp
|   |   |               TV_Demo.cpp
|   |   |
|   |   \---DemonstrationOfSoftwareOnCs
|   |           DemonstrationAnagramGrouping.cs
|   |           DemonstrationEncodeAndDecode.cs
|   |           DemonstrationGenerateParentheses.cs
|   |           DemonstrationOfSoftwareOnCs.csproj
|   |           DemonstrationStructureMinStack.cs
|   |           DemonstrationTopFrequentElements.cs
|   |           Makefile
|   |           Program.cs
|   |           README.md
|   |
|   \---MyDataStructures
|       \---MyDataStructuresOnCs
|               Makefile
|               MyDataStructuresOnCs.csproj
|               README.md
|               StructureMinStack.cs
|
\---tests
    +---DataModels
    |   \---Cpp
    |       +---include
    |       |   |   UtilityFunctions.hpp
    |       |
    |       \---src
    |               LaptopTests.cpp
    |               main.cpp
    |               TV_Tests.cpp
    |               UtilityFunctions.cpp
    |
    +---MyDataStructuresOnCsTests
    |       MyDataStructuresOnCsTests.csproj
    |       StructureMinStackTests.cs
    |
    \---TestsForProblemSolutionsOnCs
            AlgorithmsAndDataStructuresProblemSolutionsOnCsTests.csproj
            AlgorithmsAndDataStructuresProblemSolutionsTests.cs
```

---

## Автор

*   **Автор:** PastMaster1