#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::pair<int, std::string>> path =
{
	{3, ">>"},
	{2, ">>"},
	{1, "<<"},
	{3, ">>"},
	{2, "<<"},
	{0, "terrorist"},
	{1, "<<"},
};

void Run(int index)
{
	auto iter = path.begin() + index;
	if (iter->first == 0)
	{
		std::cout << index << "¹ø" << std::endl;
		return;
	}

	(iter->second == "<<") ? Run(index - iter->first) : Run(index + iter->first);

	std::cout << index << "¹ø" << std::endl;
}

int main()
{
	int n = 2;
	Run(n);

	return 0;
}