#include <iostream>
#include <algorithm>

std::string str = "ZFAABABBAB";
char path[4] = {};

void DFS(int now = 0)
{
    if (now == 3)
    {
        std::cout << path << '\n';
        return;
    }


    for (int i = 0; i < str.size(); ++i)
    {
        if (i > 0 && str[i] == str[i - 1])
            continue;

        path[now] = str[i];
        DFS(now + 1);
        path[now] = 0;
    }
}

int main()
{
	std::sort(str.begin(), str.end());
	DFS();

	return 0;
}