#include <iostream>

int BST[10] = {};

void Insert(int val, int now = 0)
{
	if (BST[now] == 0)
	{
		BST[now] = val;
		return;
	}

	if (BST[now] < val)
	{
		Insert(val, now * 2 + 2);
	}
	else
	{
		Insert(val, now * 2 + 1);
	}
}

void Sort(int now = 0)
{
	if (now >= 10)
		return;

	if (BST[now] == 0)
		return;

	Sort(now * 2 + 1);
	std::cout << BST[now] << ' ';
	Sort(now * 2 + 2);
}


int main()
{
	int nums[5] = { 5, 7, 2, 3, 1 };
	for (int i = 0; i < 5; ++i)
	{
		Insert(nums[i]);
	}

	Sort();

	return 0;
}