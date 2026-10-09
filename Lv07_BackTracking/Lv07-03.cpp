#include <iostream>

constexpr int X = 6;
constexpr int Y = 4;

int map[Y][X] =
{
	0,0,1,2,1,2,
	1,0,0,1,0,1,
	0,0,1,2,0,0,
	2,0,0,0,0,0,
};

int dir[][2] =
{
	0, 1,
	0, -1,
	1, 0,
	-1, 0
};

int Fill(int x, int y, int count = 0)
{
	for (int i = 0; i < 4; ++i)
	{
		int newX = x + dir[i][1];
		int newY = y + dir[i][0];

		if (newY >= Y || newY < 0 || newX >= X || newX < 0)
			continue;

		if (map[newY][newX] == 1 || map[newY][newX] == 3)
			continue;

		if (map[newY][newX] == 2)
			count++;

		map[newY][newX] = 3;

		count = Fill(newX, newY, count);
	}

	return count;
}

int main()
{
	map[0][0] = 3;
	int res = Fill(0, 0);

	return 0;
}