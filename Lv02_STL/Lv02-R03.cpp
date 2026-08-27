#include <iostream>

char bread[3][6] =
{
	'#', '#', '#', 'E', 'F', 'G',
	'H', '#', 'J', 'K', 'L', 'M',
	'N', 'O', 'P', 'Q', 'R', 'S',
};

int dir[4][2] =
{
	+0, +1,
	+0, -1,
	-1, +0,
	+1, +0,
};

int main()
{
	std::string str = "B";
	//std::cin >> str;

	for (int c : str)
	{
		if (bread[('A' / c)][(c % 'A')] == c)
			bread[('A' / c)][(c % 'A')] = '#';
		else
			bread[('A' / c)][(c % 'A')] = c;

		for (int i = 0; i < 4; ++i)
		{
			int newY = ('A' / c) + dir[i][0];
			int newX = (c % 'A') + dir[i][1];

			if (newY >= 3 || newY < 0 || newX >= 6 || newX < 0)
				continue;

			char newC = c + dir[i][1] + 6 * dir[i][0];

			if (bread[newY][newX] == newC)
				bread[newY][newX] = '#';
			else
				bread[newY][newX] = newC;
		}
	}

	return 0;
}