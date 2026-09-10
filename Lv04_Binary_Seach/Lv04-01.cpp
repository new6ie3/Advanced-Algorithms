#include <iostream>

int ary[] = {4, 4, 5, 7, 8, 10, 20, 22, 23, 24};

bool SearchRecursive(int find, int start = 0, int end = 9)
{
	if (start > end)
		return false;

	int mid = (start + end) / 2;

	if (ary[mid] == find)
	{
		return true;
	}
	else if(ary[mid] < find)
	{
		SearchRecursive(find, mid + 1, end);
	}
	else if(ary[mid] > find)
	{
		SearchRecursive(find, start, mid - 1);
	}
};

int main()
{
	int find = 20;
	bool result = SearchRecursive(find);

	if (result)
		std::cout << 'O';
	else
		std::cout << 'X';


	return 0;
}
