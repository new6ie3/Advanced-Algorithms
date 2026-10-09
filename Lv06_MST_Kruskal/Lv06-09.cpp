#include <iostream>

int dist = 0;

int map[4][4] =
{
	0,0,0,0,
	1,1,0,1,
	0,0,0,0,
	0,1,1,0,
};
bool visited[4][4] = {};

int dir[4][2] =
{
	0, 1,
	0, -1,
	1, 0,
	-1, 0,
};

void DFS(int y, int x, int endY, int endX, int now = 0)
{
    if (y == endY && x == endX)
    {
        dist = now;
        return;
    }

    for (int i = 0; i < 4; ++i)
    {
        int newY = y + dir[i][0];
        int newX = x + dir[i][1];

        if (newY < 0 || newY >= 4 || newX < 0 || newX >= 4)
            continue;

        if (map[newY][newX] == 0 && !visited[newY][newX])
        {
            visited[newY][newX] = true;
            DFS(newY, newX, endY, endX, now + 1);
            visited[newY][newX] = false;
        }
    }
}

int main()
{
    visited[0][0] = true;
    DFS(0, 0, 3, 3);

    std::cout << dist;

    return 0;
}