#include <iostream>

int main()
{
	int n;
	std::cin >> n;
	int s = 0;
	for (int i = 5; i <= 3 * n + 2; i++)
	{
		for (int j = 1; j <= 2 * n * (n + 1); j++)
		{
			int k = 50;
			while (k > 33)
			{
				k = k - 3;
				s = s + 1;
			}
		}
	}
	std::cout << s;
	return 0;
}