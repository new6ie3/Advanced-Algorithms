#include <iostream>
#include <queue>
#include <unordered_map>

enum Addon
{
	DIV_2,
	MUL_2,
	ADD_1,
	SUB_1,
};

struct Oper
{
	int GetValue(int num)
	{
		switch (value)
		{
		case 0: return num / 2;
		case 1: return num * 2;
		case 2: return num + 1;
		case 3: return num - 1;

		default: return -1;
		}
	}

	int value;
};

std::unordered_map<Addon, Oper>	maps =
{
	{DIV_2, {0}},
	{MUL_2, {1}},
	{ADD_1, {2}},
	{SUB_1, {3}}
};

int BFS(int start, int end)
{
	std::queue<std::pair<int, int>> queue;
	std::unordered_map<int, bool> visited;

	queue.push({ start, 0 });
	visited[start] = true;

	while (!queue.empty())
	{
		int num = queue.front().first;
		int count = queue.front().second;

		queue.pop();
		if (num == end)
			return count;

		for (auto& [addon, oper] : maps)
		{
			int next = oper.GetValue(num);

			if (next < 0 || next > 20)
				continue;

			if (visited[next] == true)
				continue;

			visited[next] = true;
			queue.push({ next, count + 1 });
		}
	}
}

int main() 
{
	int res = BFS(3, 9);
	std::cout << res;

	return 0;
}