#include <iostream>

int gril[5][5] =
{
	1,0,0,0,0,
	1,0,1,0,1,
	0,0,1,0,0,
	0,0,1,0,1,
	0,1,0,0,0,
};

int dir[4][2] =
{
	0, -1,
	0, +1,
	-1, 0,
	+1, 0,
};
int count = 0;
void Active_Fire(int dy, int dx, int now = 0)
{
	bool flag[4] = {};
	for (int i = 0; i < 4; ++i)
	{
		int newY = dy + dir[i][0];
		int newX = dx + dir[i][1];

		if (newY > 4 || newY < 0 || newX > 4 || newX < 0 || gril[newY][newX] != 0)
		{
			flag[i] = true;
			continue;
		}

		gril[newY][newX] = now + 1;
		if (count < now + 1) count = now + 1;
		Active_Fire(newY, newX, now + 1);
	}

	for (int i = 0; i < 4; ++i)
		if (flag[i] == false)
			return;


}

int main()
{
	Active_Fire(0, 4);
	std::cout << count;

	return 0;
}