#include <iostream>

int map[4][5] = 
{
	0,0,1,0,1,
	0,0,0,0,0,
	0,1,0,0,0,
	0,0,0,0,0,
};

int dir[][2] =
{
	0,1,
	0,-1,
	1,1,
	1,0,
	1,-1,
	-1,-1,
	-1,0,
	-1,1,
};

bool Checking_Map()
{
	for (int y = 0; y < 4; ++y)
	{
		for (int x = 0; x < 5; ++x)
		{
			if (map[y][x] == 0)
				return false;
		}
	}
	return true;
}

int Fire(int now = 0)
{
    if (Checking_Map())
        return now;

    for (int y = 0; y < 4; ++y)
    {
        for (int x = 0; x < 5; ++x)
        {
            if (map[y][x] == 1)
            {
                for (int i = 0; i < 8; ++i)
                {
                    int ny = y + dir[i][0];
                    int nx = x + dir[i][1];

                    if (ny > 3 || ny < 0 || nx > 4 || nx < 0)
                        continue;

                    if (map[ny][nx] == 0)
                        map[ny][nx] = 2;
                }
            }
        }
    }

    for (int y = 0; y < 4; ++y)
    {
        for (int x = 0; x < 5; ++x)
        {
            if (map[y][x] == 2)
                map[y][x] = 1;
        }
    }

    return Fire(now + 1);
}

int main()
{
	int res = Fire();
	std::cout << res;

	return 0;
}