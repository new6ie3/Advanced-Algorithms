#include <iostream>
#include <vector>
#include <queue>


int main()
{
	std::vector<int> blocks = { 20, 57, 13, 40, 33, 8 };
	std::priority_queue<int, std::vector<int>, std::greater<int>> q;
	for (int b : blocks)
	{
		q.push(b);
	}

	int total = 100;
	int res = 0;

	while (!q.empty())
	{
		int block = q.top();
		q.pop();

		if (total < block)
			break;

		total -= block;
		res++;
	}

	std::cout << res;

	return 0;
}