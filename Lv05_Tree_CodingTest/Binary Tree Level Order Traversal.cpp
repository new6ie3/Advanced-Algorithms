#include <iostream>
#include <queue>

int tree[100] = { 3, 9, 20, 0, 0, 15, 7, };

int main()
{
	std::queue<int> queue;
	queue.push(0);

	int level = 1;
	while (!queue.empty())
	{
		std::cout << level << " level : ";
		int count = queue.size();

		for (int i = 0; i < count; ++i)
		{
			int now = queue.front();
			int left = now * 2 + 1;
			int right = now * 2 + 2;

			if (tree[left] != 0)
				queue.push(left);

			if (tree[right] != 0)
				queue.push(right);

			queue.pop();
			std::cout << tree[now] << ' ';
		}
		std::cout << std::endl;
		level++;
	}

	return 0;
}