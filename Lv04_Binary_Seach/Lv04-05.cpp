#include <iostream>

int Binary_Search_Root(int val, int start = 0, int end = 17)
{
	if (start > end)
		return -1;

	int mid = (start + end) / 2;
	if (val / mid == mid)
		return mid;

	if (mid * mid < val)
		Binary_Search_Root(val, mid + 1, end);
	else
		Binary_Search_Root(val, start, mid - 1);
}

int main()
{
	int val = 10;
	int res = Binary_Search_Root(val);


	return 0;
}