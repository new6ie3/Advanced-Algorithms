#include <iostream>
#include <vector>
#include <algorithm>

int congressman[5] = {};
std::vector<std::pair<int, std::string>> vote =
{
	{0, "sam"},
	{1, "sammy"},
	{3, "sole"},
	{2, "coo"},
	{0, "luke"},
	{1, "haily"},
	{2, "elly"},
	{3, "hoo"},
	{2, "kim"},
	{2, "joon"},
	{4, "john"},
	{4, "loo"},
};

int main()
{
	for (int i = 0; i < vote.size(); ++i)
	{
		congressman[vote[i].first]++;
	}

	int idx = 0;
	for (int i = 1; i < 5; ++i)
	{
		if (congressman[idx] < congressman[i])
			idx = i;
	}

	for (auto& person : vote)
	{
		if (person.first == idx)
		{
			std::cout << person.second << '\n';
		}
	}

	return 0;
}