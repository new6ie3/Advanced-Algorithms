#include <iostream>
#include <queue>
#include <unordered_map>

enum Dir
{
	A_Left,
	A_Right,
	B_Left,
	B_Right
};

struct Move
{
	int a;
	int b;
};

std::unordered_map<Dir, Move> moveDoor =
{
	{A_Left, {-1, 0}},
	{A_Right, {+1, 0}},
	{B_Left, {0, -1}},
	{B_Right, {0, +1}},
};

constexpr int cus = 12;
int customers[cus] = { 0,1,0,1,0,1,2,3,2,3,2,3, };
int door[5] = { 0, 1, 1, 0, 0 };
bool visited[5][5][cus + 1] = {};

struct Node
{
	int a_pos;
	int b_pos;
	int customer_idx;
	int count;
};

int BFS()
{
	std::queue<Node> queue;
	queue.push({ 1, 2, 0, 0 });
	visited[1][2][0] = true;


	while (!queue.empty())
	{
		Node current = queue.front();
		queue.pop();

		while (current.customer_idx < cus)
		{
			int customer = customers[current.customer_idx];

			if (customer != current.a_pos && customer != current.b_pos)
				current.customer_idx++;
			else break;
		}

		if (current.customer_idx == cus)
			return current.count;

		for (auto& [dir, move] : moveDoor)
		{
			int nextA = current.a_pos + move.a;
			int nextB = current.b_pos + move.b;

			if (nextA < 0 || nextA >= 5 || nextB < 0 || nextB >= 5 || nextA == nextB)
				continue;

			if (visited[nextA][nextB][current.customer_idx] == true)
				continue;

			Node next = current;
			next.a_pos = nextA;
			next.b_pos = nextB;
			next.count++;

			visited[nextA][nextB][current.customer_idx] = true;
			queue.push(next);
		}
	}

	return -1;
}

int main()
{
	int res = BFS();
	std::cout << res;

	return 0;
}