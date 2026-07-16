namespace AlgorithmsAndDataStructuresProblemSolutions;

public class EncodeAndDecode
{
    public static string Encode(string[] s)
    {
        string res = Convert.ToString(s.Length);
        for (int i = 0; i < s.Length; i++)
        {
            if (string.IsNullOrEmpty(s[i]))
            {
                res += " 0";
            }
            else
            {
                res += s[i][0] + Convert.ToString(s[i].Length);
            }
        }
        for (int i = 0; i < s.Length; i++)
        {
            res += s[i];
        }
        return res;
    }

    public static string[] Decode(string s)
    {
        int i = 0;
        for (; i < s.Length && char.IsDigit(s[i]); i++);
        int count_of_words;
        bool f = int.TryParse(s.Substring(0, i), out count_of_words);
        if (!f)
        {
            return Array.Empty<string>();
        }
        string[] res = new string[count_of_words];
        int[] lengths_of_words = new int[count_of_words];
        for (int j = 0; j < count_of_words && i + 1 < s.Length; j++)
        {
            i++;
            int start = i;
            for (; i < s.Length && char.IsDigit(s[i]); i++);
            lengths_of_words[j] = Convert.ToInt32(s.Substring(start, i - start));
        }
        for (int j = 0; j < count_of_words; j++)
        {
            res[j] = s.Substring(i, lengths_of_words[j]);
            i += lengths_of_words[j];
        }
        return res;
    }
}
