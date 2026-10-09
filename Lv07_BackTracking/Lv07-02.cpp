#include <iostream>
#include <queue>

constexpr int X = 5;
constexpr int Y = 3;

int map[Y][X] =
{
	0,0,0,0,1,
	1,0,1,0,0,
	0,0,0,0,1,
};

int dir[][2] =
{
	0, 1,
	0, -1,
	1, 0,
	-1, 0
};

int BFS(int startX, int startY, int targetX, int targetY)
{
	std::queue<std::pair<int, int>> q;
	bool visited[Y][X] = {};
	int dist[Y][X] = {};

	q.push({ startX, startY });
	visited[startY][startX] = true;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (x == targetX && y == targetY)
			return dist[y][x];

		for (int i = 0; i < 4; ++i)
		{
			int newX = x + dir[i][1];
			int newY = y + dir[i][0];

			if (newX >= X || newX < 0 || newY >= Y || newY < 0)
				continue;

			if (!visited[newY][newX] && map[newY][newX] != 1)
			{
				visited[newY][newX] = true;
				dist[newY][newX] = dist[y][x] + 1;
				q.push({ newX, newY });
			}
		}
	}
	return -1;
}

int main()
{
	int startToCheese = BFS(0, 0, 0, 2);
	int CheeseToFriend = BFS(0, 2, 3, 0);

	int res = startToCheese + CheeseToFriend;
	std::cout << res;

	return 0;
}