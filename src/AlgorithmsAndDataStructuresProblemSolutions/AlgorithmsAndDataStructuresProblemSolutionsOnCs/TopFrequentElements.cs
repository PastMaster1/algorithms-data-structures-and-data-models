namespace AlgorithmsAndDataStructuresProblemSolutions;

public class TopFrequentElements
{
    public static int[] FindTopFrequentElements(int[] nums, int n, int k)
    {
        if (k <= 0 || n <= 0)
        {
            return Array.Empty<int>();
        }
        Dictionary<int, int> frequency_of_elements = new Dictionary<int, int>();
        int count_of_unique_elements = 0;
        int max_frequency = 0;
        for (int i = 0; i < n; i++)
        {
            if (!frequency_of_elements.TryGetValue(nums[i], out int frequency))
            {
                count_of_unique_elements++;
            }
            frequency_of_elements[nums[i]] = frequency + 1;
        }
        Dictionary<int, List<int>> elements_grouped_by_frequency = new Dictionary<int, List<int>>();
        foreach (var element in frequency_of_elements)
        {
            if (!elements_grouped_by_frequency.TryGetValue(element.Value, out List<int>? list_of_elements))
            {
                list_of_elements = new List<int>();
                elements_grouped_by_frequency[element.Value] = list_of_elements;
                if (element.Value > max_frequency)
                {
                    max_frequency = element.Value;
                }
            }
            list_of_elements.Add(element.Key);
        }
        if (k > count_of_unique_elements)
        {
            k = count_of_unique_elements;
        }
        int[] res = new int[k];
        int j = 0;
        for (int i = max_frequency; i > 0 && j < k; i--)
        {
            if (elements_grouped_by_frequency.TryGetValue(i, out List<int>? list_of_elements))
            {
                for (int m = 0; m < list_of_elements.Count && j < k; m++)
                {
                    res[j] = list_of_elements[m];
                    j++;
                }
            }
        }
        return res;
    }
}
