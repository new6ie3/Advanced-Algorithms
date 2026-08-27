#include <iostream>

std::string str[] =
{
	"ABC",
	"B",
	"TTS",
	"FRIENDS",
	"TRUE",
	"LOVE",
	"MORETIM"
};

bool Compare(const std::string a, const std::string b)
{
	if (a.length() != b.length())
		return a.length() < b.length();

	return a < b;
}

int main()
{
	size_t size = sizeof(str) / sizeof(str[0]);

	for (size_t i = 0; i < size - 1; ++i)
	{
		for (size_t j = 0; j < size - i - 1; ++j)
		{
			if (!Compare(str[j], str[j + 1]))
			{
				std::string temp = str[j];
				str[j] = str[j + 1];
				str[j + 1] = temp;
			}
		}
	}


	return 0;
}