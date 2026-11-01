#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

std::vector<std::pair<int, int>> vec
{
	{1, 6},
	{3, 8},
	{8, 9},
	{2, 4},
	{4, 6},
	{7, 9},
};

int main()
{
	std::sort(vec.begin(), vec.end(),
		[](const auto& a, const auto& b)
		{
			return a.second < b.second;
		});

	std::queue<std::pair<int, int>> q;
	for (std::pair<int, int> v : vec)
	{
		q.push(v);
	}

	int res = 0;
	int lastend = 0;

	while (!q.empty())
	{
		int start = q.front().first;
		int end = q.front().second;
		q.pop();

		if (start >= lastend)
		{
			res++;
			lastend = end;
		}
	}

	std::cout << res;
	return 0;
}