#include <iostream>

char oil[10] = { '#','#','#','#','#','#', 0, 0, 0, 0 };
char oil2[10] = { '#','#','#', 0 ,0, 0, 0, 0, 0, 0 };

void Binary_Search(const char* oils, int start = 0, int end = 9)
{
	if (start > end)
	{
		std::cout << start * 10 << '%' << std::endl;
		return;
	}

	int mid = (start + end) / 2;
	if (oils[mid] == '#')
		Binary_Search(oils, mid + 1, end);
	else
		Binary_Search(oils, start, mid - 1);
}

int main()
{
	Binary_Search(oil);
	Binary_Search(oil2);

	return 0;
}