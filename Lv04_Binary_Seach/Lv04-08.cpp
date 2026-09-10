#include <iostream>
#include <queue>
#include <vector>

int map[4][4] =
{
    0, 0, 30, 20,
    10, 0, 5, 40,
    10, 0, 0, 5,
    0, 50, 0, 0,
};

struct Heap
{
    char start;
    char end;
    int cost;

    bool operator<(const Heap& other) const
    {
        return cost < other.cost;
    }
};

int main()
{
    std::priority_queue<Heap> pq;

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (map[i][j] == 0)
                continue;

            Heap h;
            h.start = 'A' + i;
            h.end = 'A' + j;
            h.cost = map[i][j];

            pq.push(h);
        }
    }

    for (int i = 0; i < 3; ++i)
    {
        Heap h = pq.top();
        std::cout << h.start << '-' << h.end << ' ' << h.cost << std::endl;

        pq.pop();
    }

    return 0;
}