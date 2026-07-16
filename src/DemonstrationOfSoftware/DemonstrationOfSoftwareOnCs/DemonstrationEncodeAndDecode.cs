using AlgorithmsAndDataStructuresProblemSolutions;
namespace DemonstrationOfSoftware;

public class DemonstrationEncodeAndDecode
{
    public static void EncodeAndDecodeDemo()
    {
        Console.WriteLine($"Демонстрация работы EncodeAndDecode.cs:");
        Console.Write("Введите количество элементов: ");
        int n = Convert.ToInt32(Console.ReadLine());
        string[] s = new string[n];
        Console.WriteLine("Введите набор строк");
        for (int i = 0; i < n; i++)
        {
            s[i] = Console.ReadLine()!;
        }
        string encoded_string = EncodeAndDecode.Encode(s);
        string[] decoded_string = EncodeAndDecode.Decode(encoded_string);
        Console.WriteLine($"Encoded string: {encoded_string}");
        Console.Write($"Decoded string:");
        foreach (string e in decoded_string)
        {
            Console.Write($" {e}");
        }
    }
}
