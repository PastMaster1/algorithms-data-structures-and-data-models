using Xunit;
using AlgorithmsAndDataStructuresProblemSolutions;

namespace Tests;
public class AlgorithmsAndDataStructuresProblemSolutionsTests
{
    static long Factorial(int n)
    {
        long res = 1;
        for (int i = 2; i <= n; i++)
        {
            res *= i;
        }
        return res;
    }

    static long ExpectedCountOfCombinations(int n)
    {
        return (Factorial(2 * n) / (Factorial(n + 1) * Factorial(n)));
    }

    static bool IsAllCombinationsCorrect(List<string> list_of_combinations, int n)
    {
        long count_of_combinations = list_of_combinations.Count;
        if (count_of_combinations != ExpectedCountOfCombinations(n))
        {
            return false;
        }
        foreach (string combination in list_of_combinations)
        {
            if (!IsCombinationCorrect(combination))
            {
                return false;
            }
        }
        return true;
    }

    static bool IsCombinationCorrect(string combination)
    {
        int c = 0;
        foreach (char e in combination)
        {
            if (e == '(')
            {
                c++;
            }
            else
            {
                c--;
                if (c < 0)
                {
                    return false;
                }
            }
        }
        return (c == 0);
    }
    
    [Fact]
    [Trait("Category", "GenerateParentheses.cs")]
    public void GenerateCombinationsWithSinglePairOfParentheses()
    {
        int n = 1;
        List<string> generated_combinations = new List<string>();
        char[] current_string = new char[2];
        int count_left = 0, count_right = 0;
        GenerateParentheses.GenerateFullListOfParentheses(n, generated_combinations, current_string, count_left, count_right);
        bool res = IsAllCombinationsCorrect(generated_combinations, n);
        Assert.True(res);
    }

    [Fact]
    [Trait("Category", "GenerateParentheses.cs")]
    public void GenerateCombinationsWithTwoPairsOfParentheses()
    {
        int n = 2;
        List<string> generated_combinations = new List<string>();
        char[] current_string = new char[4];
        int count_left = 0, count_right = 0;
        GenerateParentheses.GenerateFullListOfParentheses(n, generated_combinations, current_string, count_left, count_right);
        bool res = IsAllCombinationsCorrect(generated_combinations, n);
        Assert.True(res);
    }

    [Fact]
    [Trait("Category", "GenerateParentheses.cs")]
    public void GenerateCombinationsWithTenPairsOfParentheses()
    {
        int n = 10;
        List<string> generated_combinations = new List<string>();
        char[] current_string = new char[20];
        int count_left = 0, count_right = 0;
        GenerateParentheses.GenerateFullListOfParentheses(n, generated_combinations, current_string, count_left, count_right);
        bool res = IsAllCombinationsCorrect(generated_combinations, n);
        Assert.True(res);
    }

    [Fact]
    [Trait("Category", "EncodeAndDecode.cs")]
    public void EncodeAndDecodeBasic()
    {
        string[] s = ["a", "b"];
        string encoded_string = EncodeAndDecode.Encode(s);
        string[] decoded_list_of_strings = EncodeAndDecode.Decode(encoded_string);
        bool f = true;
        if (encoded_string == "2a1b1ab" && decoded_list_of_strings.Length == s.Length)
        {
            for (int i = 0; i < s.Length && f; i++)
            {
                if (decoded_list_of_strings[i] != s[i])
                {
                    f = false;
                }
            }
        }
        else
        {
            f = false;
        }
        Assert.True(f);
    }

    [Fact]
    [Trait("Category", "EncodeAndDecode.cs")]
    public void EncodeAndDecodeEmptyArray()
    {
        string[] s = [];
        string encoded_string = EncodeAndDecode.Encode(s);
        string[] decoded_list_of_strings = EncodeAndDecode.Decode(encoded_string);
        bool f = true;
        if (!(encoded_string == "0" && decoded_list_of_strings.Length == 0))
        {
            f = false;
        }
        Assert.True(f);
    }

    [Fact]
    [Trait("Category", "EncodeAndDecode.cs")]
    public void EncodeAndDecodeEmptyStrings()
    {
        string[] s = ["", "", ""];
        string encoded_string = EncodeAndDecode.Encode(s);
        string[] decoded_list_of_strings = EncodeAndDecode.Decode(encoded_string);
        bool f = true;
        if (encoded_string == "3 0 0 0" && decoded_list_of_strings.Length == s.Length)
        {
            for (int i = 0; i < s.Length && f; i++)
            {
                if (decoded_list_of_strings[i] != s[i])
                {
                    f = false;
                }
            }
        }
        else
        {
            f = false;
        }
        Assert.True(f);
    }

    [Fact]
    [Trait("Category", "EncodeAndDecode.cs")]
    public void EncodeAndDecodeTenEmptyStrings()
    {
        string[] s = ["", "", "", "", "", "", "", "", "", ""];
        string encoded_string = EncodeAndDecode.Encode(s);
        string[] decoded_list_of_strings = EncodeAndDecode.Decode(encoded_string);
        bool f = true;
        if (encoded_string == "10 0 0 0 0 0 0 0 0 0 0" && decoded_list_of_strings.Length == s.Length)
        {
            for (int i = 0; i < s.Length && f; i++)
            {
                if (decoded_list_of_strings[i] != s[i])
                {
                    f = false;
                }
            }
        }
        else
        {
            f = false;
        }
        Assert.True(f);
    }

    [Fact]
    [Trait("Category", "EncodeAndDecode.cs")]
    public void EncodeAndDecodeLengthOfElementIsTen()
    {
        string[] s = ["AAAAAAAAAA", "AAAAAAAAAA"];
        string encoded_string = EncodeAndDecode.Encode(s);
        string[] decoded_list_of_strings = EncodeAndDecode.Decode(encoded_string);
        bool f = true;
        if (encoded_string == "2A10A10AAAAAAAAAAAAAAAAAAAA" && decoded_list_of_strings.Length == s.Length)
        {
            for (int i = 0; i < s.Length && f; i++)
            {
                if (decoded_list_of_strings[i] != s[i])
                {
                    f = false;
                }
            }
        }
        else
        {
            f = false;
        }
        Assert.True(f);
    }

    [Fact]
    [Trait("Category", "EncodeAndDecode.cs")]
    public void EncodeAndDecodeOneEmptyStringAtTheStart()
    {
        string[] s = ["", "A", "A"];
        string encoded_string = EncodeAndDecode.Encode(s);
        string[] decoded_list_of_strings = EncodeAndDecode.Decode(encoded_string);
        bool f = true;
        if (encoded_string == "3 0A1A1AA" && decoded_list_of_strings.Length == s.Length)
        {
            for (int i = 0; i < s.Length && f; i++)
            {
                if (decoded_list_of_strings[i] != s[i])
                {
                    f = false;
                }
            }
        }
        else
        {
            f = false;
        }
        Assert.True(f);
    }

    [Fact]
    [Trait("Category", "EncodeAndDecode.cs")]
    public void EncodeAndDecodeOneEmptyStringInTheMiddle()
    {
        string[] s = ["A", "", "A"];
        string encoded_string = EncodeAndDecode.Encode(s);
        string[] decoded_list_of_strings = EncodeAndDecode.Decode(encoded_string);
        bool f = true;
        if (encoded_string == "3A1 0A1AA" && decoded_list_of_strings.Length == s.Length)
        {
            for (int i = 0; i < s.Length && f; i++)
            {
                if (decoded_list_of_strings[i] != s[i])
                {
                    f = false;
                }
            }
        }
        else
        {
            f = false;
        }
        Assert.True(f);
    }

    [Fact]
    [Trait("Category", "EncodeAndDecode.cs")]
    public void EncodeAndDecodeOneEmptyStringAtTheEnd()
    {
        string[] s = ["A", "A", ""];
        string encoded_string = EncodeAndDecode.Encode(s);
        string[] decoded_list_of_strings = EncodeAndDecode.Decode(encoded_string);
        bool f = true;
        if (encoded_string == "3A1A1 0AA" && decoded_list_of_strings.Length == s.Length)
        {
            for (int i = 0; i < s.Length && f; i++)
            {
                if (decoded_list_of_strings[i] != s[i])
                {
                    f = false;
                }
            }
        }
        else
        {
            f = false;
        }
        Assert.True(f);
    }

    [Fact]
    [Trait("Category", "TopFrequentElements.cs")]
    public void TopFrequentElementsBasic()
    {
        int n = 6;
        int[] nums = [1, 1, 1, 2, 2, 3];
        int k = 1;
        int[] res = TopFrequentElements.FindTopFrequentElements(nums, n, k);
        Assert.True(res.Length == 1 && res[0] == 1);
    }

    [Fact]
    [Trait("Category", "TopFrequentElements.cs")]
    public void TopFrequentElementsEmptyArray()
    {
        int n = 0;
        int[] nums = [];
        int k = 1;
        int[] res = TopFrequentElements.FindTopFrequentElements(nums, n, k);
        Assert.True(res.Length == 0);
    }

    [Fact]
    [Trait("Category", "TopFrequentElements.cs")]
    public void TopFrequentElementsEmptyResult()
    {
        int n = 6;
        int[] nums = [1, 1, 1, 2, 2, 3];
        int k = 0;
        int[] res = TopFrequentElements.FindTopFrequentElements(nums, n, k);
        Assert.True(res.Length == 0);
    }

    [Fact]
    [Trait("Category", "TopFrequentElements.cs")]
    public void TopFrequentElementskGreaterThann()
    {
        int n = 6;
        int[] nums = [1, 1, 1, 2, 2, 3];
        int k = 10;
        int[] res = TopFrequentElements.FindTopFrequentElements(nums, n, k);
        bool f = true;
        if (res.Length == 3)
        {
            if (!(res[0] == 1 && res[1] == 2 && res[2] == 3))
            {
                f = false;
            }
        }
        else
        {
            f = false;
        }
        Assert.True(f);
    }

    [Fact]
    [Trait("Category", "AnagramGrouping.cs")]
    public void AnagramGroupingBasic()
    {
        string[] s = ["123", "132", "213", "45", "54", "6"];
        List<List<string>> res = AnagramGrouping.GroupAnagrams(s);
        bool f = true;
        if (res.Count == 3 && res[0].Count == 3 && res[1].Count == 2 && res[2].Count == 1)
        {
            if (!(res[0][0] == "123" && res[0][1] == "132" && res[0][2] == "213" && res[1][0] == "45" && res[1][1] == "54" && res[2][0] == "6"))
            {
                f = false;
            }
        }
        else
        {
            f = false;
        }
        Assert.True(f);
    }

    [Fact]
    [Trait("Category", "AnagramGrouping.cs")]
    public void AnagramGroupingOnlyOneString()
    {
        string[] s = ["a"];
        List<List<string>> res = AnagramGrouping.GroupAnagrams(s);
        bool f = true;
        if (!(res.Count == 1 && res[0].Count == 1 && res[0][0] == "a"))
        {
            f = false;
        }
        Assert.True(f);
    }

    [Fact]
    [Trait("Category", "AnagramGrouping.cs")]
    public void AnagramGroupingEmptyArray()
    {
        string[] s = [];
        List<List<string>> res = AnagramGrouping.GroupAnagrams(s);
        bool f = true;
        if (!(res.Count == 0))
        {
            f = false;
        }
        Assert.True(f);
    }

    [Fact]
    [Trait("Category", "AnagramGrouping.cs")]
    public void AnagramGroupingEmptyStrings()
    {
        string[] s = ["", ""];
        List<List<string>> res = AnagramGrouping.GroupAnagrams(s);
        bool f = true;
        if (!(res.Count == 1 && res[0].Count == 2 && res[0][0] == "" && res[0][1] == ""))
        {
            f = false;
        }
        Assert.True(f);
    }

    [Fact]
    [Trait("Category", "AnagramGrouping.cs")]
    public void AnagramGroupingDuplicates()
    {
        string[] s = ["A", "A"];
        List<List<string>> res = AnagramGrouping.GroupAnagrams(s);
        bool f = true;
        if (!(res.Count == 1 && res[0].Count == 2 && res[0][0] == "A" && res[0][1] == "A"))
        {
            f = false;
        }
        Assert.True(f);
    }
}
