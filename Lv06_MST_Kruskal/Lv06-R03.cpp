#include <iostream>
#include <vector>

struct Drink
{
	std::string name;
	int cost;
	int point;
};

std::vector<Drink> drinks =
{
	{"Ameriano", 500, 30},
	{"Cafe", 300, 40},
	{"Mohitoo", 700, 10},
	{"Cola", 400, 20},
	{"Wine", 600, 30},
};

int maxPoints = 0;
void DFS(int n, int now = 0, int start = 0, int cost = 0, int points = 0)
{
	if (now == n)
	{
		int count = 10000 / cost;
		int totalPoint = count * points;

		if (maxPoints < totalPoint)
			maxPoints = totalPoint;

		return;
	}

	for (int i = start; i < 5; ++i)
	{
		DFS(n, now + 1, i + 1, drinks[i].cost + cost, drinks[i].point + points);
	}
}

int main()
{
	int n = 4;
	DFS(n);

	std::cout << maxPoints;
	return 0;
}