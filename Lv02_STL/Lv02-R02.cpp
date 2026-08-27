#include <iostream>
#include <algorithm>

int main()
{
	std::string str = "AEBC";
	std::cin >> str;

	bool flag = true; 
	do
	{
		auto index = str.find_first_not_of('_');

		if (index != std::string::npos)
		{
			for (auto& c : str)
			{
				if (c == '_')
					continue;

				(c == 'A') ? c = '_' : c--;
			}
			std::cout << str << std::endl;
		}
		else
		{
			flag = false;
		}

	} while (flag);


	return 0;
}