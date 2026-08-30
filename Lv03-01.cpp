#include <iostream>
#include <algorithm>

char parent[1000];

char GetParent(const char x)
{
	if (parent[x] == 0)
		return x;

	int ret = GetParent(parent[x]);
	parent[x] = ret;

	return ret;
}

void Insert(const char ch1, const char ch2)
{
	int a = GetParent(ch1);
	int b = GetParent(ch2);

	if (a != b)
		parent[b] = a;

}

bool Identify()
{
	for (int i = 0; i < 1000; ++i)
	{
		if (parent[i] == 0)
			continue;

		for (int j = i; j < 1000; ++j)
		{
			if (parent[i] == parent[j])
				return true;
		}

	}

	return false;
}

int main()
{
	Insert('A', 'C');
	Insert('A', 'B');
	Insert('B', 'D');
	Insert('C', 'B');

	if (Identify)
		std::cout << "발견";
	else std::cout << "미발견";

	return 0;
}