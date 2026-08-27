#include <iostream>

int main()
{
	int building;
	std::cin >> building;

	int* cost = new int[building];
	for (int i = 0; i < building; ++i)
		std::cin >> cost[i];


	int max = INT_MIN;
	int startIdx, endIdx;
	for (int i = 0; i < building; ++i)
	{
		int sum = 0;
		for (int* p = cost + i; p < cost + building; ++p)
		{
			sum += *p;

			if (sum > max)
			{
				max = sum;
				startIdx = i;
				endIdx = p - cost;
			}

			if (sum < 0)
				break;
		}
	}


	std::cout << startIdx << ' ' << endIdx << std::endl;

	delete[] cost;

	return 0;
}