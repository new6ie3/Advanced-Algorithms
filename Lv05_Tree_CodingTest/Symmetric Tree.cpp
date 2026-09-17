#include <iostream>

int treeA[100] = { 1, 2, 2, 3, 4, 4, 3, };
int treeB[100] = { 1, 2, 2, 0, 3, 0, 3, };

bool IsSymmetric(const int* tree, int left, int right)
{
	if (tree[left] == 0 && tree[right] == 0)
		return true;

	if (tree[left] == 0 || tree[right] == 0)
		return false;

	if (tree[left] != tree[right])
		return false;

	bool res_left = IsSymmetric(tree, left * 2 + 1, right * 2 + 2);
	bool res_right = IsSymmetric(tree, left * 2 + 2, right * 2 + 1);

	return res_left && res_right;
}

int main()
{
	bool a = IsSymmetric(treeA, 1, 2);
	bool b = IsSymmetric(treeB, 1, 2);

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	return 0;
}