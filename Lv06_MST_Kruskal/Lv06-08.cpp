#include <iostream>
#include <queue>

int map[][8] =
{
    0,0,1,1,0,0,1,0,
    0,0,0,0,1,1,0,1,
    1,0,0,0,1,0,1,0,
    1,0,0,0,0,1,1,0,
    0,1,1,0,0,0,0,1,
    0,1,0,1,0,0,1,1,
    1,0,1,1,0,1,0,0,
    0,1,0,0,1,1,0,0,
};

#include <iostream>
#include <queue>

int nodes[8] = { 1, 2, 3, 4, 6, 7, 8, 9 };

void BFS(int start)
{
    std::queue<int> q;
    bool visited[8] = {};

    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        std::cout << nodes[now] << ' ';

        for (int i = 0; i < 8; ++i)
        {
            if (map[now][i] == 1 && !visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main()
{
    BFS(2);

    return 0;
}