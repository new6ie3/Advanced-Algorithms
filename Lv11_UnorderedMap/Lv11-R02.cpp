#include <iostream>
#include <vector>

std::vector<std::string> vec;

void Parsing(std::string str, int start = 0)
{
	int index = str.find("_", start);
	if (index == -1)
	{
		vec.push_back(str);
		return;
	}

	std::string findStr = str.substr(start, index - start);

	if (findStr != "")
	{
		vec.push_back(findStr);
	}
	str.erase(start, index + 1);

	Parsing(str, 0);
}

int main()
{
	std::string str = "HOT_FRIED____CHICKEN_KFC_IS_BEST";
	Parsing(str);

	int index = 1;
	for (std::string v : vec)
	{
		std::cout << index << '#' << v << std::endl;
		index++;
	}

	return 0;
}