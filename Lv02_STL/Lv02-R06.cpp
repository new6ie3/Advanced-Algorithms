#include <iostream>

constexpr size_t n = 5;
int board[n][n] =
{
	1, 0, 1, 0, 1,
	1, 1, 1, 1, 1,
	0, 0, 1, 0, 0,
	0, 0, 1, 0, 0,
	0, 1, 0, 1, 0,
};

int main()
{
	int k;
	std::cin >> k;

	for (size_t t = 0; t < k; ++t)
	{
		for (size_t y = 0; y < n; ++y)
		{
			for (size_t x = y + 1; x < n; ++x)
			{
				int temp = board[y][x];
				board[y][x] = board[x][y];
				board[x][y] = temp;
			}
		}

		for (size_t y = 0; y < n; ++y)
		{
			for (size_t x = 0; x < n / 2; ++x)
			{
				int temp = board[y][x];
				board[y][x] = board[y][n - x - 1];
				board[y][n - x - 1] = temp;
			}
		}
	}

	return 0;
}