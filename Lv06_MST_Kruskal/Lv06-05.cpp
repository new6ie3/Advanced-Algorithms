#include <iostream>

int count = 0;
int map[4][6] =
{
	0,0,1,2,1,2,
	1,0,0,1,0,1,
	0,0,1,2,0,0,
	2,0,0,0,0,0,
};

void Fill(int y, int x)
{
	if (y > 3 || y < 0 || x > 5 || x < 0)
		return;

	if (map[y][x] == 0 || map[y][x] == 2)
	{
		if (map[y][x] == 2)
			count++;

		map[y][x] = 3;

		Fill(y + 1, x);
		Fill(y - 1, x);
		Fill(y, x + 1);
		Fill(y, x - 1);
	}
}

int main()
{
	Fill(0, 0);
	std::cout << count;

	return 0;
}