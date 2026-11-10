#include <iostream>
#include <unordered_map>
#include <string>

std::unordered_map<std::string, int> dic;

std::string ary[5] =
{
    "10101",
    "11101",
    "01010",
    "11010",
    "11010",
};

int main()
{
    dic["1011"]++;
    dic["0011"]++;
    dic["1111"]++;
    dic["0000"]++;
    dic["1100"]++;

    bool isMos = false;

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            std::string mos = ary[i].substr(j, 4);

            if (dic[mos])
            {
                isMos = true;
                break;
            }
        }

        if (isMos)
            break;
    }

    std::cout << (isMos ? "yes" : "no");

    return 0;
}