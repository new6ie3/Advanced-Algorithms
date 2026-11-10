#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<std::string> mates =
{
	"POP",
	"TOM",
	"MINCODING",
	"MP",
	"BBQ",
	"KFC"
};

int main()
{
	std::unordered_map<std::string, int> map;
	map["POP"] = 1;
	map["TOM"] = 1;
	map["MC"] = 1;
	map["JASON"] = 1;
	map["KFC"] = 1;

	for (std::string name : mates)
	{
		bool isMate = map.count(name);
		(isMate) ? std::cout << "yes" : std::cout << "No";
		std::cout << std::endl;
	}

	return 0;
}