#include <iostream>
#include <vector>

std::vector<std::string> hurts =
{
	"______*_______",
	"_____***______",
	"__**********__",
	"____****______",
	"____******____"
};

void Count_Hurt(std::string hurt)
{
	size_t count = 0;
	size_t index = 0;

	while (index < hurt.length())
	{
		if (hurt[index] == '*')
			count++;

		index++;
	}

	std::cout << count << std::endl;
}

int main()
{
	for (size_t i = 0; i < hurts.size(); ++i)
	{
		Count_Hurt(hurts[i]);
	}

	return 0;
}