namespace AlgorithmsAndDataStructuresProblemSolutions;

public class AnagramGrouping
{
    public static List<List<string>> GroupAnagrams(string[] s)
    {
        Dictionary <string, List<string>> groups_of_anagrams = new Dictionary<string, List<string>>();
        for (int i = 0; i < s.Length; i++)
        {
            char[] chars = s[i].ToCharArray();
            Array.Sort(chars);
            string key = new string(chars);
            if (!groups_of_anagrams.TryGetValue(key, out List<string>? group))
            {
                group = new List<string>();
                groups_of_anagrams[key] = group;
            }
            group.Add(s[i]);
        }
        return new List<List<string>> (groups_of_anagrams.Values);
    }
}
