using AlgorithmsAndDataStructuresProblemSolutions;
namespace DemonstrationOfSoftware;

internal class DemonstrationGenerateParentheses
{
    public static void GenerateParenthesesDemo()
    {
        Console.WriteLine($"Демонстрация работы GenerateParentheses.cs:");
        Console.Write("Введите количество пар скобок: ");
        int n = Convert.ToInt32(Console.ReadLine());
        if (n < 0)
        {
            Console.WriteLine("n/a");
        }
        else
        {
            List<string> res = new List<string>();
            char[] combination_of_parentheses = new char[2 * n];
            GenerateParentheses.GenerateFullListOfParentheses(n, res, combination_of_parentheses, 0, 0);
            foreach (string a in res)
            {
                Console.WriteLine(a);
            }
        }
    }
}
