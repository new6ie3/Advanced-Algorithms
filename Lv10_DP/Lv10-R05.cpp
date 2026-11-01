#include <iostream>
#include <vector>
#include <algorithm>

int map[4][4] =
{
    0, 3, 5, 1,
    1, 1, 1, 5,
    1, 50, 20, 10,
    1, 50, 5, 0,
};

int sum[4][4] = {};

int main()
{
    int addonX = 0;
    int addonY = 0;

    for (int i = 1; i < 4; ++i)
    {
        addonX += map[0][i];
        addonY += map[i][0];

        sum[0][i] = addonX;
        sum[i][0] = addonY;
    }

    for (int y = 1; y < 4; ++y)
    {
        for (int x = 1; x < 4; ++x)
        {
            if (sum[y - 1][x] < sum[y][x - 1])
                sum[y][x] = map[y][x] + sum[y - 1][x];
            else
                sum[y][x] = map[y][x] + sum[y][x - 1];
        }
    }

    std::vector<std::pair<int, int>> path;
    int y = 3;
    int x = 3;

    while (true)
    {
        path.push_back({ y, x });

        if (y == 0 && x == 0)
            break;

        if (y == 0)
            x--;
        else if (x == 0)
            y--;
        else if (sum[y - 1][x] < sum[y][x - 1])
            y--;
        else
            x--;
    }

    std::reverse(path.begin(), path.end());

    for (auto [y, x] : path)
        std::cout << "(" << y << ", " << x << ") ";

    return 0;
}