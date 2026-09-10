#include <iostream>

char board[5][5] =
{
	'A','E','K','X','K',
	'Z','O','Q','K','P',
	'C','F','W','L','X',
	'C','E','I','H','B',
	'N','E','M','I','O',
};

int dir_type1[5][2] =
{
	-1, 0,
	0, 0,
	0, -1,
	0, +1,
	+1, 0,
};

int dir_type2[5][2] =
{
	-1, -1,
	0, 0,
	-1, 1,
	1, 1,
	1, -1
};

void Gacha(int dy, int dx, int type)
{
	switch (type)
	{
	case 1:
		for (int i = 0; i < 5; ++i)
		{
			int newY = dy + dir_type1[i][0];
			int newX = dx + dir_type1[i][1];

			if (newY > 4 || newY < 0 || newX > 4 || newX < 0)
				continue;

			std::cout << board[newY][newX];
		}
		std::cout << std::endl;
		break;

	case 2:
		for (int i = 0; i < 5; ++i)
		{
			int newY = dy + dir_type2[i][0];
			int newX = dx + dir_type2[i][1];

			if (newY > 4 || newY < 0 || newX > 4 || newX < 0)
				continue;

			std::cout << board[newY][newX];
		}
		std::cout << std::endl;
		break;

	}
}

int main()
{
	Gacha(1, 1, 1);
	Gacha(3, 1, 2);

	return 0;
}