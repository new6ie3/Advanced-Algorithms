#include <iostream>
#include <set>

struct Set
{
	std::set<std::pair<int, char>> set;
};

int main()
{
	int n;
	std::cin >> n;

	Set* sets = new Set[n];

	for (int i = 0; i < n; ++i)
	{
		int a;
		char b;

		std::cin >> a >> b;

		sets[i].set.insert({ a, b });
	}

	for (int i = 1; i < n; ++i)
	{
		Set target = sets[i];

		int j = i - 1;
		while (j >= 0 && sets[j].set > target.set)
		{
			sets[j + 1] = sets[j];
			--j;
		}

		sets[j + 1] = target;
	}

	delete[] sets;

	return 0;
}
