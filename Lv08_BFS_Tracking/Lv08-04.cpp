#include <iostream>
#include <queue>
#include <map>
enum Seafood
{
	None,
	Shirmp,
	Squize
};

struct Node
{
	int y;
	int x;
	Seafood seafood;
	int dist;
};

int map[7][7] =
{
	0,0,0,1,2,0,0,
	0,2,0,0,0,0,0,
	0,0,1,0,0,1,2,
	0,0,0,0,0,0,0,
	1,0,0,1,0,0,0,
	0,2,0,0,0,1,0,
	0,0,1,0,2,0,0,
};

bool visited[2][7][7] = {};

int dir[4][2] =
{
	0, 1,
	0, -1,
	-1, 0,
	1, 0,
};

bool BFS(int dy, int dx)
{
    std::queue<Node> queue;
    queue.push({ dy, dx, static_cast<Seafood>(map[dy][dx]), 0 });

    int type = 0;
    int limit = 0;

    switch (queue.front().seafood)
    {
    case Shirmp:
        type = 0;
        limit = 3;
        break;

    case Squize:
        type = 1;
        limit = 4;
        break;

    default:
        return true;
    }

    bool visited[2][7][7] = {};
    visited[type][dy][dx] = true;

    while (!queue.empty())
    {
        int y = queue.front().y;
        int x = queue.front().x;
        Seafood seafood = queue.front().seafood;
        int dist = queue.front().dist;

        queue.pop();

        for (int i = 0; i < 4; ++i)
        {
            int ny = y + dir[i][0];
            int nx = x + dir[i][1];

            if (ny >= 7 || ny < 0 || nx >= 7 || nx < 0)
                continue;

            if (visited[type][ny][nx])
                continue;

            int nextDist = dist + 1;

            if (nextDist >= limit)
                continue;

            if (map[ny][nx] == seafood)
                return false;

            visited[type][ny][nx] = true;
            queue.push({ ny, nx, seafood, nextDist });
        }
    }

    return true;
}

int main()
{
	for (int i = 0; i < 7; ++i)
	{
		for (int j = 0; j < 7; ++j)
		{
			if (map[i][j] == 0)
				continue;

			bool res = BFS(i, j);
			if (!res)
			{
				std::cout << "fail";
				return 0;
			}
		}
	}

	std::cout << "pass";
	return 0;
}