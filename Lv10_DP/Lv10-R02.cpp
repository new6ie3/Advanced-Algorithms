#include <iostream>
#include <queue>
#include <algorithm>

int coins[] = { 10, 50, 100, 500 };

int main()
{
	std::priority_queue<int> q;

	for (int i = 0; i < 4; ++i)
		q.push(coins[i]);

	int total = 660;
	int res = 0;

	while (!q.empty())
	{
		int front = q.top();
		q.pop();

		int count = total / front;

		res += count;
		total %= front;
	}
	std::cout << res;

	return 0;
}