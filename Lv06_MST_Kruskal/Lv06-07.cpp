#include <iostream>

int map[4][4] =
{
    1,1,0,1,
    0,1,0,1,
    0,1,1,0,
    1,0,0,0,
};

int dir[][2] =
{
    0, 1,
    0, -1,
    1, 0,
    -1, 0
};

int count = 0;

void DFS(int y, int x)
{
    if (y < 0 || y >= 4 || x < 0 || x >= 4)
        return;

    if (map[y][x] != 1)
        return;

    count++;
    map[y][x] = 2;

    for (int i = 0; i < 4; ++i)
    {
        int ny = y + dir[i][0];
        int nx = x + dir[i][1];

        DFS(ny, nx);
    }
}

int main()
{
    DFS(0, 0);

    std::cout << count;

    return 0;
}