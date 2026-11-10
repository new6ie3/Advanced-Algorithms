#include <iostream>
#include <string>

std::string input[5] =
{
	"SVCMCDMCD",
	"CCCMCCD",
	"MCDDT",
	"MCDDDC",
	"MMMMM",
};

int main()
{
	int count = 0;

	for (int i = 0; i < 5; ++i)
	{
		while (1)
		{
			int index = input[i].find("MCD", 0);
			if (index == -1)
				break;

			input[i].erase(index, 3);
			count++;
		}
	}

	std::cout << count;

	return 0;
}