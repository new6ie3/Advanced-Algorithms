#include <iostream>
#include <algorithm>

std::string strs[6] =
{
	"ABCD",
	"ABCE",
	"AGEH",
	"EIEI",
	"FEQE",
	"ABAD",
};

int main()
{
	std::string search = "AB??";
	std::cin >> search;

    int count = 0;
    for (int i = 0; i < 6; ++i)
    {
        bool match = true;

        for (int j = 0; j < 4; ++j)
        {
            if (search[j] != '?' && search[j] != strs[i][j])
            {
                match = false;
                break;
            }
        }

        if (match) count++;
    }


	return 0;
}