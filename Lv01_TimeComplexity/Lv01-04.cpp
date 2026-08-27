#include <iostream>
#include <string>

using namespace std;

string str[] =
{
	"ADCBE",
	"QREWT",
	"ZVCXB",
	"OREPA",
	"MOPAM",
};

int main()
{
	for (int i = 0; i < 5; ++i)
	{
		char temp = str[i][1];
		str[i][1] = str[i][3];
		str[i][3] = temp;

		if (str[i] == "MAPOM")
		{
			cout << "yes";
			return 0;
		}
	}

	cout << "no";

	return 0;
}