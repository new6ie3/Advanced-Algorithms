#include <iostream>

int bst[100] = { 5, 3, 6, 2, 4, 0, 0, 1, };

bool flag = false;
int GetInorderSuccessor(int p, int now = 0)
{
	if (now > 99 || bst[now] == 0)
		return 0;

	int left = GetInorderSuccessor(p, now * 2 + 1);
	
	if (bst[now] > p && !flag)
	{
		flag = true;
		return bst[now];
	}

	int right = GetInorderSuccessor(p, now * 2 + 2);

	if (left != 0 || right != 0)
		return left ? left : right;
}

int main()
{
	int res = GetInorderSuccessor(6);
	std::cout << res;

	return 0;
}