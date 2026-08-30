#include <iostream>

int group[5] = {};

int map[5][5] =
{
    0, 0, 0, 1, 0,
    0, 0, 1, 0, 0,
    0, 0, 0, 1, 1,
    1, 0, 1, 0, 1,
    0, 0, 1, 1, 0,
};

int Find(int x)
{
    while (group[x] != x)
    {
        x = group[x];
    }

    return x;
}

bool Union(int a, int b)
{
    a = Find(a);
    b = Find(b);

    if (a == b)
        return false;

    group[b] = a;

    return true;
}

int main()
{
    for (int i = 0; i < 5; ++i)
        group[i] = i;

    for (int i = 0; i < 5; ++i)
    {
        for (int j = i + 1; j < 5; ++j)
        {
            if (map[i][j] == 1)
            {
                if (!Union(i, j))
                {
                    std::cout << "Cycle 있음\n";
                    return 0;
                }
            }
        }
    }

    std::cout << "Cycle 없음\n";

}