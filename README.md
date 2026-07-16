# Algorithms And Data Structures

Репозиторий содержит академическую библиотеку задач на алгоритмы и структуры данных, их решения покрыты тестами. В репозитории есть интерактивное консольное приложение для демонстрации работы программ.

---

## Архитектура и структура решения

Проект разделен на несколько изолированных модулей (многопроектное решение .NET):

*   **(./src/MyDataStructures/)** — кастомные структуры данных.
*   **(./src/AlgorithmsAndDataStructuresProblemSolutions/)** — решения алгоритмических задач.
*   **(./src/DemonstrationOfSoftware/)** — интерактивные консольные CLI-приложения.
*   **(./Tests/)** — проекты автоматического тестирования программ.

---

## Спецификация реализованных задач

В проекте представлены решения следующих задач:

1.  **StructureMinStack.cs:** Стек с поддержкой получения минимума за O(1).
2.  **GenerateParentheses.cs:** Рекурсивный генератор правильных скобочных последовательностей.
3.  **AnagramGrouping.cs:** Группировка слов-анаграмм.
4.  **EncodeAndDecode.cs:** Кодирование и декодирование строк.
5.  **TopFrequentElements.cs:** Поиск самых частых элементов массива.

---

## Возможности

*   **Структуры данных:** Кастомные реализации структур данных.
*   **Алгоритмы:** Решения алгоритмических задач.
*   **Интерактивное CLI-приложение:** Удобное меню в консоли для запуска и визуализации работы алгоритмов «на лету».
*   **Тесты:** Покрытие с помощью xUnit.
*   **Автоматизация:** Управление проектами через `Makefile`.

---

## Структура проекта

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
|   +---DemonstrationOfSoftware
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
\---Tests
    +---MyDataStructuresOnCsTests
    |       MyDataStructuresOnCsTests.csproj
    |       StructureMinStackTests.cs
    |
    \---TestsForProblemSolutionsOnCs
            AlgorithmsAndDataStructuresProblemSolutionsOnCsTests.csproj
            AlgorithmsAndDataStructuresProblemSolutionsTests.cs
```

---

## Системные требования

Перед запуском убедитесь, что у вас установлены:
1.  .NET 8.0 SDK или выше.
2.  Утилита `make`.

---

## Автор

*   **Автор:** PastMaster1