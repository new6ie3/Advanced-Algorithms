#include <iostream>

char layover[5] = { 'G', 'T', 'H', 'B', 'K' };
int map[5][5] =
{
	0, 3, 6, 0, 2,		//G
	0, 0, 2, 4, 0,		//T
	0, 0, 0, 1, 0,      //H
	0, 0, 10, 0, 0,		//B
	0, 0, 0, 8, 0,		//K
};


int min = 987654321;
char minPath[5] = {};
char path[5] = {};

void DFS(int cur, int end, int cost = 0, int now = 0)
{
	if (cur == end)
	{
		if (cost < min)
		{
			min = cost;
			path[now] = layover[end];
			for (int i = 0; i < 4; ++i)
				minPath[i] = path[i];
		}

		return;
	}
	
	for (int i = 0; i < 5; ++i)
	{
		if (map[cur][i] != 0)
		{
			path[now] = layover[cur];
			DFS(i, end, cost + map[cur][i], now + 1);
			path[now] = 0;
		}
	}

}

int FindIdx(const char c)
{
	for (int i = 0; i < 5; ++i)
	{
		if (layover[i] == c)
			return i;
	}

	return -1;
}

int main()
{
	char a = 'G';
	char b = 'B';

	int ia = FindIdx(a);
	int ib = FindIdx(b);

	DFS(ia, ib);

	std::cout << min << ':' << minPath;

	return 0;
}