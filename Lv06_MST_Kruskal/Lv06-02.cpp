#include <iostream>

int map[3][3] = {};

int dir[4][2] =
{
	1, 0,
	-1, 0,
	0, 1,
	0, -1
};

void Input_virus(int dy, int dx)
{
	map[dy][dx] = 1;
}

bool Check()
{
	for (int y = 0; y < 3; ++y)
	{
		for (int x = 0; x < 3; ++x)
		{
			if (map[y][x] == 0)
				return false;
		}
	}
	return true;
}


void Update(int now = 1)
{
	bool isAllVirus = Check();
	if (!isAllVirus)
	{
		for (int y = 0; y < 3; ++y)
		{
			for (int x = 0; x < 3; ++x)
			{
				if (map[y][x] == now)
				{
					for (int i = 0; i < 4; ++i)
					{
						int newX = dir[i][1] + x;
						int newY = dir[i][0] + y;

						if (newY >= 3 || newY < 0 || newX >= 3 || newX < 0)
							continue;

						if (map[newY][newX] < now && map[newY][newX] != 0)
							continue;

						map[newY][newX] = now + 1;
					}

				}
			}
		}
		Update(now + 1);
	}
	else
	{
		for (int y = 0; y < 3; ++y)
		{
			for (int x = 0; x < 3; ++x)
			{
				std::cout << map[y][x];
			}
			std::cout << std::endl;
		}

		return;
	}
}

int main()
{
	Input_virus(0, 0);
	Input_virus(2, 2);

	Update();

	return 0;
}