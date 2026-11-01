#include <iostream>
#include <vector>

std::vector<int> d =
{
	100000005,
	100000002,
	100000003,
	100000006,
	100000015,
	100000022,
	100000013,
	100000009,
	100000005,
};

int bucket[100] = {};

void FindCount(int age)
{
	std::cout << bucket[age % 100000000] << "¸¶¸®";
}

int main()
{
	for (int n : d)
	{
		bucket[n % 100000000]++;
	}

	FindCount(100000005);
	return 0;
}