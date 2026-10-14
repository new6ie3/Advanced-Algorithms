#include <iostream>
#include <queue>
#include <map>
#include <vector>

int map[4][9] =
{
    0,1,2,1,4,8,3,1,3,
    2,3,2,3,4,2,3,1,3,
    2,2,2,3,4,3,4,3,3,
    0,2,1,3,4,2,1,3,2,
};

int dir[4][2] =
{
    0, 1,
    0, -1,
    1, 0,
    -1, 0
};

bool visited[4][9] = {};

int BFS(int dy, int dx)
{
    std::queue<std::pair<int, int>> q;

    q.push({ dy, dx });
    visited[dy][dx] = true;

    int count = 1;

    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int ny = y + dir[i][0];
            int nx = x + dir[i][1];

            if (ny >= 4 || ny < 0 || nx >= 9 || nx < 0)
                continue;

            if (!visited[ny][nx] && map[dy][dx] == map[ny][nx])
            {
                visited[ny][nx] = true;
                count++;

                q.push({ ny, nx });
            }
        }
    }

    return count;
}

int main()
{
    std::map<int, int> groups;

    for (int y = 0; y < 4; ++y)
    {
        for (int x = 0; x < 9; ++x)
        {
            if (visited[y][x])
                continue;

            int count = BFS(y, x);

            if (groups[map[y][x]] < count)
                groups[map[y][x]] = count;
        }
    }

    std::pair<int, int> maxVal = { 0, 0 };
    for (const auto& [num, size] : groups)
    {
        if (maxVal.second < size)
        {
            maxVal.first = num;
            maxVal.second = size;
        }
    }

    std::cout << maxVal.first * maxVal.second;

    return 0;
}