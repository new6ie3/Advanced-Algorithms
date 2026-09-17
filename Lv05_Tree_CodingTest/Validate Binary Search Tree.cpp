#include <iostream>

int treeA[100] = { 2, 1, 3, };
int treeB[100] = { 5, 1, 4, 0, 0, 3, 6, };

bool IsBST(const int* tree, int now = 0, int min = INT_MIN, int max = INT_MAX)
{
	if (tree[now] == 0)
		return true;

	if (tree[now] <= min || tree[now] >= max)
		return false;

	bool left = IsBST(tree, now * 2 + 1, min, tree[now]);
	bool right = IsBST(tree, now * 2 + 2, tree[now] , max);

	return left && right;
}

int main()
{
	bool a = IsBST(treeA);
	bool b = IsBST(treeB);

	std::cout << a << std::endl;
	std::cout << b << std::endl;

	return 0;
}