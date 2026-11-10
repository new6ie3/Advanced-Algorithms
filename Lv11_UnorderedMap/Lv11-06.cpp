#include <iostream>
#include <unordered_map>

char ary[][6] =
{
	'A', 'B', 'A', 'B', 'A', 'B',
	'C', 'D', 'C', 'D', 'C', 'D',
	'A', 'G', 'G', 'F', 'H', 'A',
	'B', 'B', 'F', 'A', 'B', 'C',
	'D', 'D', 'C', 'C', 'D', 'D',
	'F', 'F', 'D', 'H', 'A', 'S',
};

int main()
{
	std::unordered_map<std::string, int> dic;

	for (int y = 0; y < 5; ++y)
	{
		for (int x = 0; x < 5; ++x)
		{
			std::string s;
			s += ary[y][x];
			s += ary[y][x + 1];
			s += ary[y + 1][x];
			s += ary[y + 1][x + 1];

			dic[s]++;
		}
	}

	std::string findStr = "ABCD";
	std::cout << dic[findStr];

	return 0;
}