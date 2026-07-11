using AlgorithmsAndDataStructuresProblemSolutions;
namespace DemonstrationOfSoftware;

internal class DemonstrationTopFrequentElements
{
    public static void TopFrequentElementsDemo()
    {
        Console.Write("Введите количество элементов массива: ");
        int n = Convert.ToInt32(Console.ReadLine());
        int[] nums = new int[n];
        for (int i = 0; i < n; i++)
        {
            Console.Write("Введите элемент массива: ");
            nums[i] = Convert.ToInt32(Console.ReadLine());
        }
        Console.Write("Какое количество элементов, которые наиболее часто встречаются, вывести: ");
        int k = Convert.ToInt32(Console.ReadLine());
        int[] res = TopFrequentElements.FindTopFrequentElements(nums, n, k);
        foreach (int e in res)
        {
            Console.WriteLine(e);
        }
    }
}
