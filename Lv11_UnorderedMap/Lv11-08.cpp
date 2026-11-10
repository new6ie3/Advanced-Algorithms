#include <iostream>
#include <vector>
void Create_name(std::string name)
{
	int hash[28] = {};
	std::vector<char> vowels = { 'a', 'e', 'i', 'o', 'u' };

	for (char c : name)
	{
		if (hash[c - 'a'] >= 2)
		{
			std::cout << "no" << std::endl;
			return;
		}
		hash[c - 'a']++;

		if (!(c >= 'a' && c <= 'z'))
		{
			std::cout << "no" << std::endl;
			return;
		}

		for (char v : vowels)
		{
			if (v == c)
			{
				for (auto iter = vowels.begin(); iter != vowels.end(); ++iter)
				{
					if (*iter == c)
					{
						vowels.erase(iter);
						break;
					}
				}
			}
		}
	}

	if(vowels.size() >= 2)
		std::cout << "good" << std::endl;
	else
		std::cout << "no" << std::endl;
}

int main()
{
	Create_name("kfcbbqioi");
	Create_name("mincoding");
	Create_name("samhaiom_t");

	return 0;
}