#include <iostream>
#include <queue>

const int mouse[] = { 0, 0 };
const int cheese[] = { 2, 0 };
const int finish[] = { 0, 3 };

const int dir[][2] =
{
    0, 1,
    0, -1,
    1, 0,
    -1, 0
};

int map[3][5] =
{
    0,0,0,0,1,
    1,0,1,0,0,
    0,0,0,0,1,
};

int BFS(const int start[], const int end[])
{
    std::queue<std::pair<int, int>> q;
    bool visited[3][5] = {};
    int dist[3][5] = {};

    q.push({ start[0], start[1] });
    visited[start[0]][start[1]] = true;

    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        if (y == end[0] && x == end[1])
            return dist[y][x];

        for (int i = 0; i < 4; ++i)
        {
            int ny = y + dir[i][0];
            int nx = x + dir[i][1];

            if (ny > 2 || ny < 0 || nx > 4 || nx < 0)
                continue;

            if (!visited[ny][nx] && map[ny][nx] == 0)
            {
                visited[ny][nx] = true;
                dist[ny][nx] = dist[y][x] + 1;

                q.push({ ny, nx });
            }
        }
    }

    return -1;
}

int main()
{
    int toCheese = BFS(mouse, cheese);
    int toFinish = BFS(cheese, finish);

    std::cout << toCheese + toFinish;

    return 0;
}