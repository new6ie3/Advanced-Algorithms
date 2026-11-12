#include <iostream>

int map[5][5] =
{
	0, 25, 100, 10, 30,
	0, 0, 10, 0, 0,
	0, 0, 0, 0, 0,
	0, 0, 0, 0, 5,
	0, 5, 0, 0, 0,
};

int result[5] = { 0, 25, 100, 10, 30 };
int visited[5] = { 1, 0, 0, 0, 0 };

int findMin()
{
	int min = 987654321;
	int minIndex = -1;
	for (int i = 0; i < 5; i++)
	{
		if (visited[i] == 0 && result[i] < min)
		{
			min = result[i];
			minIndex = i;
		}
	}
	return minIndex;
}

void dijkstra()
{
	for (int i = 0; i < 4; i++)
	{
		int minIndex = findMin();
		visited[minIndex] = 1;

		for (int j = 0; j < 5; j++)
		{
			if (map[minIndex][j] == 0 || visited[j] == 1)
				continue;

			int a = result[minIndex] + map[minIndex][j];
			int b = result[j];
			if (a < b)
			{
				result[j] = a;
			}
		}

	}
}


int main()
{
	dijkstra();
	int max = INT_MIN, min = INT_MAX;
	int maxIdx = 0, minIdx = 0;
	for (int i = 1; i < 5; ++i)
	{
		if (max < result[i])
		{
			max = result[i];
			maxIdx = i;
		}

		if (min > result[i])
		{
			min = result[i];
			minIdx = i;
		}
	}

	std::cout << char('A' + minIdx) << '(' << min << ')' << std::endl;
	std::cout << char('A' + maxIdx) << '(' << max << ')' << std::endl;

	return 0;
}
