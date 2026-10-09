#include <iostream>
#include <queue>

constexpr int X = 5;
constexpr int Y = 3;

int map[Y][X] =
{
	3, 0, 0, 0, 2,
	-1, -1, 4, -1, -1,
	0, 1, 0, 2, 4,
};

int dir[4][2] =
{
	0, 1,
	0, -1,
	1, 0,
	-1, 0,
};

struct Result
{
    int y;
    int x;
    int dist;
};

Result BFS(int startY, int startX, int target)
{
    std::queue<std::pair<int, int>> q;
    bool visited[Y][X] = {};
    int dist[Y][X] = {};

    q.push({ startY, startX });
    visited[startY][startX] = true;

    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        if (map[y][x] == target)
            return { y, x, dist[y][x] };

        for (int i = 0; i < 4; ++i)
        {
            int ny = y + dir[i][0];
            int nx = x + dir[i][1];

            if (ny >= Y || ny < 0 || nx >= X || nx < 0)
                continue;

            if (!visited[ny][nx] && map[ny][nx] != -1)
            {
                visited[ny][nx] = true;
                dist[ny][nx] = dist[y][x] + 1;
                q.push({ ny, nx });
            }
        }
    }

    return { -1, -1, -1 };
}

int main()
{
    int y = 0;
    int x = 0;
    int totalDist = 0;

    for (int target = 1; target <= 4; ++target)
    {
        Result res = BFS(y, x, target);

        totalDist += res.dist;

        y = res.y;
        x = res.x;
    }

    std::cout << totalDist;

    return 0;
}