#include <iostream>

char puzzle[4][4] =
{
	'A', 'B', 'T', 'B',
	'A', 'T', 'C', 'D',
	'B', 'G', 'A', 'D',
	'A', 'B', 'C', 'T',
};

bool isSuccess = false;

bool Check()
{
    for (int y = 0; y < 4; ++y)
    {
        for (int x = 0; x < 2; ++x)
        {
            if (puzzle[y][x] == 'A' && puzzle[y][x + 1] == 'A' && puzzle[y][x + 2] == 'A')
            {
                return true;
            }
        }
    }

    return false;
}

void Rotate(int index, bool left)
{
    int y = index / 2;
    int x = index % 2;

    int dy[8] = { 0, 0, 0, 1, 2, 2, 2, 1 };
    int dx[8] = { 0, 1, 2, 2, 2, 1, 0, 0 };
    char temp[8];

    for (int i = 0; i < 8; ++i)
        temp[i] = puzzle[y + dy[i]][x + dx[i]];

    for (int i = 0; i < 8; ++i)
    {
        if (left)
        {
            puzzle[y + dy[(i + 1) % 8]][x + dx[(i + 1) % 8]] = temp[i];
        }
        else
        {
            puzzle[y + dy[(i + 7) % 8]][x + dx[(i + 7) % 8]] = temp[i];
        }
    }
}

void DFS(int now = 0)
{
    if (Check())
    {
        isSuccess = true;
        return;
    }

    if (now == 6)
    {
        return;
    }

    for (int i = 0; i < 4; ++i)
    {
        Rotate(i, true);
        DFS(now + 1);
        Rotate(i, false);
    }
}


int main()
{
    DFS();
    std::cout << (isSuccess ? "가능" : "불가능");

	return 0;
}