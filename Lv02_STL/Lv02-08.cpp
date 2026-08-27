#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

std::vector<std::string> names =
{
	"redeye",
	"apple",
	"Steve",
	"Berry",
	"eUnBo",
};

void ReName()
{
    for (auto& name : names)
    {
        bool allLower = std::all_of(name.begin(), name.end(), 
            [](char c)
            {
                return std::islower(c);
            });

        bool firstUpperRestLower = std::isupper(name[0]) && std::all_of(name.begin() + 1, name.end(),
                [](char c)
                {
                    return std::islower(c);
                });

        if (allLower)
        {
            name[0] = std::toupper(name[0]);
        }

        else if (!firstUpperRestLower)
        {
            std::transform(name.begin(), name.end(), name.begin(),
                [](char c)
                {
                    return std::toupper(c);
                });
        }
    }

    std::sort(names.begin(), names.end());
}

int main()
{
    ReName();

	return 0;
}