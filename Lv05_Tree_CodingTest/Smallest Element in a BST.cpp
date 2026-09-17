#include <iostream>

int tree[100] = { 5, 3, 6, 2, 4, 0, 0, 1, };

int count = 0;
int GetSmallestElement(int k, int now = 0)
{
	if (now > 99 || tree[now] == 0)
		return 0;

	int left = GetSmallestElement(k, now * 2 + 1);

	count++;
	if (count == k)
		return tree[now];

	int right = GetSmallestElement(k, now * 2 + 2);

	if (left != 0 || right != 0)
		return left ? left : right;
}
int main()
{
	int res = GetSmallestElement(3);
	std::cout << res;

	return 0;
}