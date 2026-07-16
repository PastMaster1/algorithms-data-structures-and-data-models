using DataStructuresOnCs;
namespace DemonstrationOfSoftware;

public class DemonstrationStructureMinStack
{
    public static void StructureMinStackDemo()
    {
        Console.WriteLine($"Демонстрация работы StructureMinStack.cs:");
        MinStack stack = new MinStack();
        Console.WriteLine("Добавление в стек чисел 1, 2, 3");
        stack.Push(1);
        stack.Push(2);
        stack.Push(3);
        Console.WriteLine("Вывод стека:");
        stack.PrintStack();
        Console.WriteLine("Конец вывода.");
        int d = stack.Top();
        Console.WriteLine($"Верхний элемент стека: {d}");
        d = stack.GetMin();
        Console.WriteLine($"Минимальный элемент стека: {d}");
        d = stack.Count();
        Console.WriteLine($"Размер стека: {d}");
        Console.WriteLine("Удаление элемента из стека.");
        stack.Pop();
        Console.WriteLine("Вывод стека:");
        stack.PrintStack();
        Console.WriteLine("Конец вывода.");
        d = stack.Top();
        Console.WriteLine($"Верхний элемент стека: {d}");
        d = stack.GetMin();
        Console.WriteLine($"Минимальный элемент стека: {d}");
        d = stack.Count();
        Console.WriteLine($"Размер стека: {d}");
    }
}
