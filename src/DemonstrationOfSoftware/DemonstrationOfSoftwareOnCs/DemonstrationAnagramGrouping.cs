using AlgorithmsAndDataStructuresProblemSolutions;

namespace DemonstrationOfSoftware;

internal class DemonstrationAnagramGrouping
{
    public static void AnagramGroupingDemo()
    {
        Console.WriteLine("Демонстрация работы AnagramGrouping.cs:");
        Console.Write("Введите количество элементов массива: ");
        int n = Convert.ToInt32(Console.ReadLine());
        string[] s = new string[n];
        for (int i = 0; i < n; i++)
        {
            Console.Write("Введите элемент массива: ");
            s[i] = Console.ReadLine() ?? "";
        }
        List<List<string>> groups_of_anagrams = AnagramGrouping.GroupAnagrams(s);
        Console.Write("[ ");
        for (int i = 0; i < groups_of_anagrams.Count; i++)
        {
            Console.Write("[");
            int j = 0;
            for (; j < groups_of_anagrams[i].Count - 1; j++)
            {
                Console.Write($"{groups_of_anagrams[i][j]}, ");
            }
            Console.Write($"{groups_of_anagrams[i][j]}] ");
        }
        Console.WriteLine("]");
    }
}
