#include <iostream>
#include <string>
using namespace std;

string str[] =
{
	"HITS",
	"HI",
	"HITSM",
	"MUSIC",
	"SMU",
	"SIC",
	"USIC",
};

int main()
{
	int count = 0;
	string* start = str;
	size_t size = sizeof(str) / sizeof(str[0]);

	for (size_t i = 0; i < size - 1; ++i)
	{
		for (string* p = start + 1; p < str + size; ++p)
		{
			string result = *start + *p;

			if (result == "HITSMUSIC")
				count++;
		}

		start++;
	}

	cout << count << endl;

	return 0;
}