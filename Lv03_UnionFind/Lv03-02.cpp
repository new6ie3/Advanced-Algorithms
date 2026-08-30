#include <iostream>
#include <algorithm>

int group[100];

int GetGroupCount()
{
	int count = 0;
	for (int i = 0; i < 100; ++i)
	{
		if (group[i] != 0)
			count++;
	}

	return count;
}

void Insert(const char ch1, const char ch2)
{
	if (group[ch1] + ch1 > ch2)
		return;

	group[ch1] += group[ch2];
	group[ch2] = 0;
}

int main()
{
	group['A'] = 3;
	group['D'] = 3;
	group['G'] = 2;
	group['I'] = 2;

	Insert('G', 'I');
	Insert('D', 'E');
	Insert('G', 'J');

	std::cout << GetGroupCount();

	return 0;
}