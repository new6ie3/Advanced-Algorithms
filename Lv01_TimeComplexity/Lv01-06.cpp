#include <iostream>

int Parking[9] = {1, 2, 3, 3, 5, 1, 0, 1, 3};

int main()
{
	int bus;
	std::cin >> bus;

	int cost = INT_MAX;

	for (int i = 0; i < 9 - bus + 1; ++i)
	{
		int sum = 0;

		for (int* p = Parking + i; p < Parking + i + bus; ++p)
			sum += *p;

		if (sum < cost)
			cost = sum;
	}

	std::cout << cost << std::endl;

	return 0;
}