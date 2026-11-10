#include <iostream>
#include <vector>
#include <unordered_map>

std::string str = "BOBOOBOBOBOBBM";
std::unordered_map<std::string, int> hash;

int main()
{
	std::vector<std::string> vec =
	{
		"BOB",
		"OOB",
		"BBM",
	};

	int size = str.size();
	for (int i = 0; i < size - 2; ++i)
	{
		std::string s = str.substr(i, 3);
		hash[s]++;
	}

	for (std::string v : vec)
	{
		if (hash[v])
			std::cout << hash[v] << std::endl;
	}

	return 0;
}