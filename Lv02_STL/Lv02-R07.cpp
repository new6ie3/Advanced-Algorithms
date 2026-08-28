#include <iostream>

constexpr size_t width = 8;
constexpr size_t height = 4;

int land[height][width] =
{
	0,0,3,3,0,0,0,0,
	5,1,4,2,6,9,8,1,
	6,5,1,3,2,6,3,2,
	0,0,0,0,9,9,4,0,
};

int GetLandValue(int x1, int y1, int x2, int y2)
{
	int sum = 0;

	for (int y = y1; y <= y2; ++y)
	{
		for (int x = x1; x <= x2; ++x)
		{
			if (land[y][x] == 0)
				return 0;

			sum += land[y][x];
		}
	}

	return sum;
}

int main()
{
	int max = 0;
	for (int y1 = 0; y1 < height; ++y1)
	{
		for (int x1 = 0; x1 < width; ++x1)
		{
			for (int y2 = y1; y2 < height; ++y2)
			{
				for (int x2 = x1; x2 < width; ++x2)
				{
					int value = GetLandValue(x1, y1, x2, y2);

					if (value > max)
						max = value;
				}
			}
		}
	}

	std::cout << max << std::endl;

	return 0;
}