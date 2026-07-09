namespace AlgorithmsAndDataStructuresProblemSolutions;

public class GenerateParentheses
{
    public static void GenerateFullListOfParentheses(int n, List<string> list_of_parentheses, char[] current_string, int count_left, int count_right)
    {
        if (count_left < count_right)
        {
            return;
        }
        if (count_left + count_right == 2 * n)
        {
            list_of_parentheses.Add(new string(current_string));
            return;
        }
        if (count_left < n)
        {
            current_string[count_left + count_right] = '(';
            GenerateFullListOfParentheses(n, list_of_parentheses, current_string, count_left + 1, count_right);
        }
        if (count_right < n)
        {
            current_string[count_left + count_right] = ')';
            GenerateFullListOfParentheses(n, list_of_parentheses, current_string, count_left, count_right + 1);
        }
    }
}
