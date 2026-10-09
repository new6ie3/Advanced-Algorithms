#include <iostream>
#include <queue>

int map[4][4] =
{
	0,0,0,0,
	1,1,0,1,
	0,0,0,0,
	1,0,1,0,
};

int dir[4][2] =
{
	0, 1,
	0, -1,
	1, 0,
	-1, 0
};

int BFS(int sy, int sx, int ey, int ex)
{
	std::queue<std::pair<int, int>> queue;
	bool visited[4][4] = {};
	int dist[4][4] = {};

	queue.push({ sy, sx });
	dist[sy][sx] = 0;
	visited[sy][sx] = true;

	while (!queue.empty())
	{
		int y = queue.front().first;
		int x = queue.front().second;
		queue.pop();

		if (y == ey && x == ex)
			return dist[y][x];

		for (int i = 0; i < 4; ++i)
		{
			int ny = y + dir[i][0];
			int nx = x + dir[i][1];

			if (ny > 3 || ny < 0 || nx > 3 || nx < 0)
				continue;

			if (!visited[ny][nx] && map[ny][nx] != 1)
			{
				visited[ny][nx] = true;
				dist[ny][nx] = dist[y][x] + 1;
				queue.push({ ny, nx });
			}
		}
	}
	return -1;
}

int main()
{
	int res = BFS(0, 0, 3, 3);
	std::cout << res;

	return 0;
}