#include <iostream>
#include <string>

void Replace(std::string& str, int start = 0)
{
    if (start >= str.size())
        return;

    if ((str[start] == '(' || str[start] == ')') && start > 0 && str[start] == str[start - 1])
    {
        str.erase(start, 1);
        Replace(str, start);
        return;
    }

    if (str[start] == '^' && start >= 2  && str[start - 1] == '^' && str[start - 2] == '^')
    {
        str.erase(start, 1);
        Replace(str, start);
        return;
    }

    if (start >= 2 && str[start] == '^' && str[start - 2] == '^' && str[start - 1] != '^')
    {
        str[start - 1] = '_';
    }

    Replace(str, start + 1);
}

int main()
{
    std::string str = "(((((^0^))((^^^)))(^_^)))))";
    Replace(str);
    std::cout << str;

    return 0;
}