#include <iostream>
#include <queue>

char map[8][9] =
{
	'_','_','_','_','_','_','#','#','#',
	'_','_','_','_','_','_','#','#','#',
	'_','_','_','_','_','_','#','#','#',
	'_','_','_','_','_','#','#','#','#',
	'_','_','_','_','#','#','_','_','_',
	'#','_','_','_','_','_','_','_','_',
	'#','#','_','_','_','_','_','_','_',
	'#','#','#','_','_','_','_','_','_',
};

int dir[][2] =
{
	0, 1,
	0, -1,
	1, 0,
	-1, 0,
};

bool visited[8][9] = {};


int BFS(int dy, int dx)
{
    std::queue<std::pair<int, int>> queue;
    int dist[8][9] = {};

    visited[dy][dx] = true;
    queue.push({ dy, dx });

    while (!queue.empty())
    {
        int y = queue.front().first;
        int x = queue.front().second;
        queue.pop();

        for (int i = 0; i < 4; ++i)
        {
            int ny = y + dir[i][0];
            int nx = x + dir[i][1];

            if (ny >= 8 || ny < 0 || nx >= 9 || nx < 0)
                continue;

            if (!visited[ny][nx] && map[ny][nx] == '#')
            {
                visited[ny][nx] = true;
                queue.push({ ny, nx });
            }
        }
    }

    for (int y = 0; y < 8; ++y)
    {
        for (int x = 0; x < 9; ++x)
        {
            if (visited[y][x])
                queue.push({ y, x });
        }
    }

    while (!queue.empty())
    {
        int y = queue.front().first;
        int x = queue.front().second;
        queue.pop();

        for (int i = 0; i < 4; ++i)
        {
            int ny = y + dir[i][0];
            int nx = x + dir[i][1];

            if (ny >= 8 || ny < 0 || nx >= 9 || nx < 0)
                continue;

            if (visited[ny][nx])
                continue;

            if (map[ny][nx] == '#')
                return dist[y][x];

            visited[ny][nx] = true;
            dist[ny][nx] = dist[y][x] + 1;

            queue.push({ ny, nx });
        }
    }

    return -1;
}

int main()
{
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			if (map[i][j] == '_')
				continue;

			int res = BFS(i, j);
			std::cout << res;
			return 0;
		}
	}

	return 0;
}