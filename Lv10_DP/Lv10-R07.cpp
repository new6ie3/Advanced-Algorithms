#include <iostream>

int map[7][3] =
{
    1, 0, 0,
    1, 2, 2,
    0, 3, 0,
    3, -10, -5,
    15, -10, 50,
    15, -10, 10,
    0, 6, 4,
};

int sum[7][3] = {};

int dir[3][2] =
{
    1, -1,
    1,  0,
    1,  1,
};

int main()
{
    for (int y = 0; y < 7; ++y)
        for (int x = 0; x < 3; ++x)
            sum[y][x] = INT_MIN;

    sum[0][0] = map[0][0];

    for (int y = 0; y < 6; ++y)
    {
        for (int x = 0; x < 3; ++x)
        {
            if (sum[y][x] == INT_MIN)
                continue;

            for (int i = 0; i < 3; ++i)
            {
                int ny = y + dir[i][0];
                int nx = x + dir[i][1];

                if (nx < 0 || nx >= 3)
                    continue;

                if (map[ny][nx] == 0)
                    continue;

                sum[ny][nx] = std::max(sum[ny][nx], sum[y][x] + map[ny][nx]);
            }
        }
    }

    int maxScore = INT_MIN;
    int endX = -1;

    for (int x = 0; x < 3; ++x)
    {
        if (sum[6][x] > maxScore)
        {
            maxScore = sum[6][x];
            endX = x;
        }
    }

    std::cout << maxScore;

    return 0;
}