#include <iostream>

constexpr size_t rows = 8;
constexpr size_t cols = 8;

char datas[rows][cols] =
{
	'#', '#', '#', '#', '#', '#', '#', '#',
	'#', '#', '#', '#', '#', '#', '#', '#',
	'#', '#', '#', '#', '#', '#', '#', '#',
	'#', '#', '#', '#', '#', '#', '#', '#',
	'#', '#', '#', '#', '#', '#', '#', '#',
	'#', '#', '#', 0, 0, 0, 0, 0,
	 0, 0, 0, 0, 0, 0, 0, 0,
	 0, 0, 0, 0, 0, 0, 0, 0,
};

int main()
{
	size_t idx = 0;
	for (size_t i = 1; i < rows; ++i)
	{
		if (datas[i][0] == 0)
		{
			idx = i - 1;
			break;
		}
	}

	for (size_t i = 0; i < cols; ++i)
	{
		if (datas[idx][i] == 0)
		{
			std::cout << idx << ' ' << i - 1;
			break;
		}
	}

	return 0;
}