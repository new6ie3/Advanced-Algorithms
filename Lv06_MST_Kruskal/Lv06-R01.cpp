#include <iostream>

int max = 0;
int visited[9] = {};
int map[3][3] =
{
	-4, 1, 3,
	3, -1, 4,
	-3, 2, 0,
};

int count = 0;
void DFS(int now = 0, int mul = 1)
{
	if (now >= 3)
	{
		if (max < mul)
		{
			max = mul;
			count = 1;
		}
		else if (max == mul)
		{
			count++;
		}

		return;
	}

	for (int i = 0; i < 9; ++i)
	{
		if (visited[i] == 1)
			continue;

		visited[i] = 1;
		DFS(now + 1, mul * map[i / 3][i % 3]);
		visited[i] = 0;
	}
}

int main()
{
	DFS();
	std::cout << count;

	return 0;
}