#include <iostream>
#include <queue>

int map[5][8] =
{
	0,0,0,0,0,0,0,0,
	0,1,0,1,0,1,1,1,
	0,1,1,1,0,0,1,1,
	0,0,0,0,0,1,0,0,
	0,1,1,1,1,1,0,0,
};

int dir[4][2] =
{
	0, 1,
	0, -1,
	1, 0,
	-1, 0
};

bool visited[5][8] = {};

int count = 0;
void BFS(int dy, int dx)
{
	if (map[dy][dx] == 0)
		return;

	if (visited[dy][dx])
		return;

	count++;
	std::queue<std::pair<int, int>> queue;
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

			if (ny >= 5 || ny < 0 || nx >= 8 || nx < 0)
				continue;

			if (visited[ny][nx] || map[ny][nx] == 0)
				continue;

			visited[ny][nx] = true;
			queue.push({ ny, nx });
		}
	}
}

int main()
{
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			BFS(i, j);
		}
	}

	std::cout << count;

	return 0;
}