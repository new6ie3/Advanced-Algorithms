#include <iostream>

int nums[100] = {-10, -3, 0, 5 , 9, };
int balance[100] = {};

void Height_Balanced_BST(int start, int end, int now = 0)
{
	if (start > end)
		return;

	int mid = (start + end) / 2;
	balance[now] = nums[mid];
	std::cout << balance[now] << ' ';

	Height_Balanced_BST(start, mid - 1, now * 2 + 1);		// left
	Height_Balanced_BST(mid + 1, end, now * 2 + 2);			// right
}

int main()
{
	Height_Balanced_BST(0, 4);

	return 0;
}