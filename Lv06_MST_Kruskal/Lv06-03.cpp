#include <iostream>
#include <queue>

const int start[] = { 0, 0 };
const int end[] = { 3, 3 };
const int dir[][2] =
{
	0, 1,
	0, -1,
	1, 0,
	-1, 0
};

int map[4][4] =
{
	0,0,0,0,
	1,1,0,1,
	0,0,0,0,
	1,0,1,0,
};

int BFS()
{
	bool visited[4][4] = { false, };
	std::queue<std::pair<int, int>> queue;

	queue.push({start[1], start[0]});
	visited[start[1]][start[0]] = true;

	while (!queue.empty())
	{
		int y = queue.front().first;
		int x = queue.front().second;
		queue.pop();

		if (y == end[0] && x == end[1])
			return map[y][x];

		for (int i = 0; i < 4; ++i)
		{
			int newY = y + dir[i][0];
			int newX = x + dir[i][1];

			if (newY > 3 || newY < 0 || newX > 3 || newX < 0)
				continue;

			if (!visited[newY][newX] && map[newY][newX] == 0)
			{
				visited[newY][newX] = true;
				map[newY][newX] = map[y][x] + 1;
				queue.push({ newY, newX });
			}
		}
	}

	return -1;
}

int main()
{
	int res = BFS();
	std::cout << res;

	return 0;
}