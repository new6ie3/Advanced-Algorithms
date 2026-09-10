#include <iostream>

std::string fish = "#~~~~~~~#~~~~#";

int main()
{
    int maxLength = 0;
    int length = 0;

    for (char c : fish)
    {
        if (c == '~')
        {
            length++;

            if (length > maxLength)
                maxLength = length;
        }
        else
        {
            length = 0;
        }
    }

    for (int i = 0; i < maxLength; ++i)
        std::cout << '~';

    return 0;
}