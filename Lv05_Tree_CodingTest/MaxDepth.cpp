#include <iostream>

int tree[100] = { 3, 9, 20, 0, 0, 15, 7, };

int GetLevel(int now = 0, int level = 0)
{
	if (tree[now] == 0)
	{
		return level;
	}

	int left = GetLevel(now * 2 + 1, level + 1);
	int right = GetLevel(now * 2 + 2, level + 1);

	return (left < right) ? right : left;
}

int main()
{
	int level = GetLevel();
	std::cout << level;

	return 0;
}