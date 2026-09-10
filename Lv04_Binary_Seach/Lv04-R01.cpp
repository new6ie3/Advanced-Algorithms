#include <iostream>

int binary_tree[] = { 3, 2, 5, 1, 6, 0, 7, 0, 0, 0, 0, 0, 0, 4, 8 };

void DFS(int now = 0, int level = 0)
{
	if (binary_tree[now] == 0)
		return;

	if (level == 3)
	{
		std::cout << binary_tree[now] << ' ';
		return;
	}

	DFS(now * 2 + 1, level + 1);
	DFS(now * 2 + 2, level + 1);

	std::cout << binary_tree[now] << ' ';
}

int main()
{
	DFS();

	return 0;
}