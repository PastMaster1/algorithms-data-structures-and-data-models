namespace DemonstrationOfSoftware;

internal class Program
{
    static int Main(string[] args)
    {
        Dictionary<int, string> list_of_software = new Dictionary<int, string>();
        list_of_software[0] = "Выход";
        list_of_software[1] = "Повтор списка команд";
        list_of_software[2] = "StructureMinStack.cs";
        list_of_software[3] = "GenerateParentheses.cs";
        list_of_software[4] = "EncodeAndDecode.cs";
        list_of_software[5] = "TopFrequentElements.cs";
        
        Console.WriteLine("Демонстрация работы ПО");
        PrintHelp(list_of_software);
        Console.Write("Выберите какую программу запустить: ");
        int user_choice = Convert.ToInt32(Console.ReadLine());
        while (user_choice != 0)
        {
            if (user_choice == 1)
            {
                PrintHelp(list_of_software);
            }
            else if (user_choice == 2)
            {
                DemonstrationStructureMinStack.StructureMinStackDemo();
            }
            else if (user_choice == 3)
            {
                DemonstrationGenerateParentheses.GenerateParenthesesDemo();
            }
            else if (user_choice == 4)
            {
                DemonstrationEncodeAndDecode.EncodeAndDecodeDemo();
            }
            else if (user_choice == 5)
            {
                DemonstrationTopFrequentElements.TopFrequentElementsDemo();
            }
            else
            {
                Console.WriteLine("Некорректный ввод");
            }
            Console.WriteLine();
            Console.Write("Выберите какую программу запустить: ");
            user_choice = Convert.ToInt32(Console.ReadLine());
        }
        return 0;
    }

    static void PrintHelp(Dictionary<int, string> d)
    {
        foreach (var e in d)
        {
            Console.WriteLine($"{e.Key} - {e.Value}");
        }
    }
}
