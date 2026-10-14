#include <iostream>
#include <unordered_map>
#include <queue>

enum Direction
{
	Up,
	Down,
	Left,
	Right,
};

struct Velocity
{
	int x;
	int y;
};

int map[5][5] =
{
	0,0,0,1,0,
	0,0,0,1,0,
	1,1,0,0,0,
	0,0,1,0,0,
	0,0,0,0,0,
};

int BFS(int startX, int startY, int endX, int endY)
{
	std::queue<std::pair<int, int>> queue;
	bool visited[5][5] = {};
	visited[startX][startY] = true;
	queue.push({ startX, startY });
	int dist[5][5] = {};

	std::unordered_map<Direction, Velocity> maps =
	{
		{Up, {0, -1}},
		{Down, {0, 1}},
		{Left, {-1, 0}},
		{Right, {1, 0}}
	};

	while (!queue.empty())
	{
		int x = queue.front().first;
		int y = queue.front().second;
		queue.pop();

		if (x == endX && y == endY)
			return dist[x][y];

		for (const auto& [dir, vel] : maps)
		{
			int nextX = x + vel.x;
			int nextY = y + vel.y;

			if (nextX >= 5 || nextX < 0 || nextY >= 5 || nextY < 0)
				continue;

			if (!visited[nextX][nextY] && map[nextX][nextY] != 1)
			{
				visited[nextX][nextY] = true;
				dist[nextX][nextY] = dist[x][y] + 1;
				queue.push({ nextX, nextY });
			}
		}
	}

	return -1;
}


int main()
{
	int result = BFS(0, 0, 4, 0);
	std::cout << result;

	return 0;
}