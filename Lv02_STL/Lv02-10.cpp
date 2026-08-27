#include <iostream>

int bit[4][4] =
{
	0, 1, 0, 0,
	0, 1, 0, 0,
	0, 0, 1, 0,
	0, 1, 0, 0,
};

int ary[4][4] =
{
	3, 4, 1, 6,
	7, 7, 2, 4,
	2, 6, 4, 5,
	4, 2, 6, 5,
};

void SortArray(int* ary, int len)
{
	int counts[10] = {};		// 0 ~ 9
	for (int i = 0; i < len; ++i)
		counts[ary[i]]++;

	for (int i = 0; i < len - 1; ++i)
	{
		if (counts[ary[i]] != counts[ary[i + 1]])
		{
			if (counts[ary[i]] < counts[ary[i + 1]])
			{
				int temp = ary[i];
				ary[i] = ary[i + 1];
				ary[i + 1] = temp;
			}
		}
		else
		{
			if (ary[i] > ary[i + 1])
			{
				int temp = ary[i];
				ary[i] = ary[i + 1];
				ary[i + 1] = temp;
			}
		}
	}
}

int main()
{
	int set[4];
	for (int y = 0; y < 4; ++y)
	{
		for (int x = 0; x < 4; ++x)
		{
			if (bit[y][x] == 1)
				set[y] = ary[y][x];
		}
	}

	SortArray(set, 4);


	return 0;
}