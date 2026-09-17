#include <iostream>

int island_1[][5] =
{
	{1, 1, 1, 1, 0},
	{1, 1, 0, 1, 0},
	{1, 1, 0, 0, 0},
	{0, 0, 0, 0, 0}
};

int island_2[][5] =
{
	{1, 1, 0, 0, 0} ,
	{1, 1, 0, 0, 0},
	{0, 0, 1, 0, 0},
	{0, 0, 0, 1, 1}
};


int dir[4][2] =
{
	+0, +1,
	+0, -1,
	+1, +0,
	-1, +0,
};

void DFS(int dy, int dx, const int island[][5], bool visited[4][5])
{
	visited[dy][dx] = true;

	for (int k = 0; k < 4; ++k)
	{
		int newY = dir[k][0] + dy;
		int newX = dir[k][1] + dx;

		if (newY > 3 || newY < 0 || newX < 0 || newX > 4)
			continue;

		if (island[newY][newX] == 1 && visited[newY][newX] == false)
			DFS(newY, newX, island, visited);
	}
}

size_t Counting_Islands(const int island[][5])
{
	size_t count = 0;
	bool visited[4][5] = {};

	for (int y = 0; y < 4; ++y)
	{
		for (int x = 0; x < 5; ++x)
		{
			if (island[y][x] == 1 && visited[y][x] == 0)
			{
				count++;
				DFS(y, x, island, visited);
			}

		}
	}

	return count;
}

int main()
{
	size_t res_1 = Counting_Islands(island_1);
	size_t res_2 = Counting_Islands(island_2);

	std::cout << res_1 << std::endl; 
	std::cout << res_2 << std::endl; 

	return 0;
}