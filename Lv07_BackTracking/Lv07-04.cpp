#include <iostream>

constexpr int X = 5;
constexpr int Y = 4;

int map[Y][X] =
{
	0,0,1,0,1,
	0,0,0,0,0,
	0,1,0,0,0,
	0,0,0,0,0,
};

int dir[][2] =
{
	0, 1,
	0, -1,
	1, 0,
	1, 1,
	1, -1,
	-1, -1,
	-1, 0,
	-1, 1
};

bool CheckAllFilled()
{
	for (int y = 0; y < Y; ++y)
	{
		for (int x = 0; x < X; ++x)
		{
			if (map[y][x] == 0)
				return false;
		}
	}
	return true;
}

void ApplyNextFire()
{
	for (int y = 0; y < Y; ++y)
	{
		for (int x = 0; x < X; ++x)
		{
			if (map[y][x] == 2)
				map[y][x] = 1;
		}
	}
}

int Fill(int count = 0)
{
	if (CheckAllFilled())
		return count;

	for (int y = 0; y < Y; ++y)
	{
		for (int x = 0; x < X; ++x)
		{
			if (map[y][x] == 1)
			{
				for (int i = 0; i < 8; ++i)
				{
					int newY = y + dir[i][0];
					int newX = x + dir[i][1];

					if (newY >= Y || newY < 0 || newX >= X || newX < 0)
						continue;

					if (map[newY][newX] == 0)
						map[newY][newX] = 2;
				}
			}

		}
	}

	ApplyNextFire();
	return Fill(count + 1);
}

int main()
{
	int res = Fill();
	std::cout << res;

	return 0;
}