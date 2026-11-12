#include <iostream>
#define NOT 999999

int map[4][4] =
{
	0, 50, NOT, 20,
	NOT, 0, 5, NOT,
	NOT, NOT, 0, NOT,
	NOT, 10, 25, 0,
};

int result[4] = { 0, 50, NOT, 20 };
int visited[4] = { 1, 0, 0, 0 };

int findMin()
{
	int min = 987654321;
	int minIndex = -1;

	for (int i = 0; i < 4; ++i)
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
	int minIndex = 0;

	for (int i = 0; i < 3; ++i)
	{
		minIndex = findMin();

		for (int j = 0; j < 4; ++j)
		{
			int a = result[minIndex] + map[minIndex][j];
			int b = result[j];

			if (a < b)
				result[j] = a;
		}

		visited[minIndex] = 1;
	}

	std::cout << "최단 거리 결과" << std::endl;
	char nodes[] = { 'A', 'B', 'C', 'D' };
	for (int i = 0; i < 4; ++i)
		std::cout << "A ->" << nodes[i] << ": " << result[i] << "만원" << std::endl;

}

int main()
{
	dijkstra();
	return 0;
}