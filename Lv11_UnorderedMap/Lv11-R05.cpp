#include <iostream>
#include <vector>

std::vector<std::pair<std::string, std::string>> banner =
{
	{"KFC", "#BBQ#"},
	{"MC", "#BBQ#"},
	{"BICMAC", "#MACBOOK#"},
	{"SHACK", "#SHOCK#"},
	{"SONY", "#NONY#"},
};

void ApplyBanner(std::string& str)
{
	for (std::pair<std::string, std::string> ban : banner)
	{
		int index = str.find(ban.first, 0);
		if(index != -1)
		{ 
			str.erase(index, ban.first.size());
			str.insert(index, ban.second);
		}
	}
}

int main()
{
	std::string str = "ILOVEKFCANDMC!!";
	ApplyBanner(str);

	return 0;
}