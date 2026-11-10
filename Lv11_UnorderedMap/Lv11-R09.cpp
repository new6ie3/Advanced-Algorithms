#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    std::string strA = "OOBCDEOOAB";
    std::string strB = "ABCDEF";

    for (int len = strB.size(); len >= 1; --len)
    {
        for (int i = 0; i + len <= strB.size(); ++i)
        {
            std::string sub = strB.substr(i, len);

            if (strA.find(sub) != -1)
            {
                std::cout << sub;
                return 0;
            }
        }
    }

    return 0;
}