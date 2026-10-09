#include <iostream>
#include <vector>

int count = 0;
int nums[3] = { 1, 5, 2 };
int path[3] = {};

std::vector<std::string> opers
{
	"!!",
	"#",
	"$",
	"&",
	"^"
};

int Operator(const int a, const int b, const char* op)
{
	if (strcmp(op, "!!") == 0) return a + b + b;
	else if (strcmp(op, "#") == 0) return a - b - b;
	else if (strcmp(op, "$") == 0) return a + 10;
	else if (strcmp(op, "&") == 0) return a + b * b;
	else if (strcmp(op, "^") == 0) return 0;
	else return -1;
}

void DFS(int num = 0, int now = 0)
{
	if (now == 2)
	{
		if (num > 20)
			count++;

		return;
	}

	for (int i = 0; i < 5; ++i)
	{
		if (now == 0)
			num = Operator(nums[now], nums[now + 1], opers[i].c_str());
		else
			num = Operator(num, nums[now + 1], opers[i].c_str());

		path[now] = num;
		DFS(num, now + 1);
		path[now] = 0;
		num = path[now - 1];
	}
}

int main()
{
	DFS();
	std::cout << count;

	return 0;
}