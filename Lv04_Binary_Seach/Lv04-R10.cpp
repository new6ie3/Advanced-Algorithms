#include <iostream>

int code[] = {1, 5, 4, -2, 6, 7, -1};
bool visited[7] = {};
int min = 987654321;

void Recursive(int n, int now = 0, int val = 1)
{
	if (now == n)
	{
		if (min > val) min = val;
		return;
	}

	for (int i = 0; i < 7; ++i)
	{
		if (visited[i] == 1)
			continue;

		visited[i] = 1;
		Recursive(n, now + 1, val * code[i]);
		visited[i] = 0;
	}
}

int main()
{
	int n = 3;
	Recursive(n);
	std::cout << min;

	return 0;
}