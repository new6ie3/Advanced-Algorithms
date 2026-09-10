#include <iostream>

int count = 0;
void recursive(int n, int now = 0, int sum = 0)
{
	if (now == n)
	{
		if (sum == 10)
			count++;

		return;
	}

	for (int i = 1; i < 10; ++i)
	{
		recursive(n, now + 1, sum + i);
	}
}

int main()
{
	int n = 3;
	recursive(n);

	std::cout << count;
	return 0;
}