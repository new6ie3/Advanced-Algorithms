#include <iostream>
#include <string>

int main()
{
    std::string str = "____bck____a_c_k_ ";

    if (str.find("bad") != -1 || str.find("no") != -1 || str.find("puck") != -1)
    {
        std::cout << "fail";
        return 0;
    }

    int word[100] = {};
    int underCount = 0;

    for (char c : str)
    {
        if (c == '_')
        {
            underCount++;

            if (underCount > 5)
            {
                std::cout << "fail";
                return 0;
            }
        }
        else
            underCount = 0;

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            word[c]++;

            if (word[c] > 5)
            {
                std::cout << "fail";
                return 0;
            }
        }

        if (c >= '0' && c <= '9')
        {
            std::cout << "fail";
            return 0;
        }
    }

    std::cout << "pass";

    return 0;
}