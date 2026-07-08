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
}
