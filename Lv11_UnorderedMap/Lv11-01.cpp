#include <iostream>
#include <unordered_map>

int main()
{
	std::string str = "FFFCFFFABCabc";
	std::unordered_map<char, int> dic;

	for (char c : str)
	{
		dic[c]++;
	}
	
	for (char c = 'A'; c <= 'z'; ++c)
	{
		if (dic.count(c) > 0)
		{
			std::cout << c << ':' << dic.at(int(c)) << std::endl;
		}
	}


	return 0;
}
