#include <iostream>

int ground[3][3] = 
{
	852, 0, 51,
	0, 5, 0,
	3, 0, 0,
};

void Run(int wind)
{
	for (int y = 0; y < 3; ++y)
	{
		for (int x = 0; x < 3; ++x)
		{
			if (ground[y][x] == 0)
				continue;

			int target = ground[y][x] % 10;
			(target < wind) ? ground[y][x] /= 10 : ground[y][x] -= wind;
		}
	}
}

int main()
{
	int n;
	std::cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int wind;
		std::cin >> wind;

		Run(wind);
	}

	return 0;
}