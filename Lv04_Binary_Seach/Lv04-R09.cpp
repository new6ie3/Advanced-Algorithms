#include <iostream>

int house[4][4] =
{
	6, 4, -2, 3,
	0, -4, 4, 1,
	-4, 4, 0, -2,
	5, 1, 6, 9,
};
int path[4];
int max = 0;
void Recursive(int val = 1, int now = 0)
{
    if (now == 4)
    {
        if (val > max)
            max = val;

        return;
    }

    for (int i = 0; i < 4; ++i)
    {
        if (house[now][i] == 0)
            continue;

        path[now] = house[now][i];

        Recursive(val * house[now][i], now + 1);

        path[now] = 0;
    }
}

int main()
{
	Recursive();
	std::cout << max;

	return 0;
}